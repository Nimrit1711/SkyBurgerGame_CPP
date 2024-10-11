#include "Game.h"
#include <iostream>


// Constructor initializes game components
Game::Game() : window(sf::VideoMode(900, 800), "SkyBurger"),
               player(&burger),
               gameMode("default"),  // Default game mode
               gameRunning(true),
               spawnTimer(0.0f) {
    initialize();
}

// Set the hazard spawn rate based on the game mode
void Game::setHazardSpawnRate(int rate) {
    hazardSpawnRate = rate;
}

// Set the falling speed multiplier based on the game mode
void Game::setFallSpeedMultiplier(int multiplier) {
    fallSpeedMultiplier = multiplier;
}

// Initializes game components
void Game::initialize() {
    srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    
    // Example: Set to default mode (could be changed to hard/easy later by player input)
    gameMode.setGameMode("default");

    // Apply the game mode to adjust spawn rate and fall speed
    gameMode.applyMode(*this);
}

// Main game loop
void Game::run() {
    while (window.isOpen() && gameRunning) {
        handleInput();               // Process user input
        float deltaTime = clock.restart().asSeconds();
        update(deltaTime);           // Update the game state
        render();                    // Render all game objects
    }
}

// Handles player input
void Game::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    player.handleInput(window);  // Handle player movement (left and right)
}

// Updates the game state
void Game::update(float deltaTime) {
    player.update(deltaTime, window);

    // Timer to control the spawn rate
    spawnTimer += deltaTime;
    if (spawnTimer >= gameMode.getHazardSpawnRate()) {
        spawnObjects();  // Spawn new food items or hazards
        spawnTimer = 0.0f;
    }

    // Check for collisions between player, food, and hazards
    checkAllCollisions();
}

// Spawns new food items and hazards
void Game::spawnObjects() {
    int randomType = rand() % 9;  // Choose a random type of object
    FallingObjects* newObject = nullptr;

    // Spawn food items
    if (randomType == 0) {
        newObject = new Lettuce();
    } else if (randomType == 1) {
        newObject = new Tomato();
    } else if (randomType == 2) {
        newObject = new Cheese();
    } else if (randomType == 3) {
        newObject = new Onion();
    } else if (randomType == 4) {
        newObject = new Patty();
    } else if( randomType==5){
        newObject = new GoldenIngredient();
    }
       // Spawn hazards
    else if (randomType == 6) {
        newObject = new BananaPeel();
    } else if (randomType == 7) {
        newObject = new Bomb();
    } else if (randomType == 8) {
        newObject = new PoisonBottle();
    } else {
        newObject = new Sock();
    } 

    if (newObject) {
        newObject->setPosition(sf::Vector2f(rand() % window.getSize().x, 0.0f));
        fallingItems.push_back(std::unique_ptr<FallingObjects>(newObject));
    }
}

// Checks for collisions between the player and falling objects
void Game::checkAllCollisions() {
    for (auto it = fallingItems.begin(); it != fallingItems.end();) {
        (*it)->update(clock.restart().asSeconds());

        if (auto foodItem = dynamic_cast<FoodItem*>(it->get())) {
            foodItem->checkCollision(player, burger);
            if (foodItem->getIsCaught()) {
                score.updateScore(*foodItem);  // Update score
                it = fallingItems.erase(it);
                continue;
            }
        } else if (auto hazard = dynamic_cast<Hazards*>(it->get())) {
            hazard->checkCollision(player, burger);
            if (hazard->getIsCaught()) {
                player.loseLife();
                it = fallingItems.erase(it);
                if (!player.isAlive()) {
                    gameRunning = false;
                    handleGameOver();
                }
                continue;
            }
        }
        ++it;
    }
}

// Renders the game window and all objects
void Game::render() {
    window.clear(sf::Color(197, 234, 250));  // Clear the screen

    // Render falling objects
    for (const auto& item : fallingItems) {
        item->render(window);
    }

    player.render(window);
    burger.render(window, player.getPlayerPosition(), player);
    window.display();  // Display the updated window
}

// Handles the game over condition
void Game::handleGameOver() {
    std::cout << "Game Over! Final score: " << score.getCurrentScore() << std::endl;
    resetGame();  // Reset the game after game over
}

// Resets the game state after game over
void Game::resetGame() {
    fallingItems.clear();  // Clear all falling objects
    gameRunning = false;
}