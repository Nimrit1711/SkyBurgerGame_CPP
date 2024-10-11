#include "Game.h"
#include <cstdlib> 
#include <iostream> 
#include <ctime>

Game::Game(GameMode::Difficulty selectedDifficulty, RenderWindow& existingWindow) : window(existingWindow),
               player(&burger), spawnTimer(0.0f), spawnInterval(0.5f),hazardSpawnTimer(0.0f), cameraMoveSpeed(1.0f),
               gameRunning(true), isHazard(false), halfWindowHeight(window.getSize().y / 2) {
                srand(static_cast<unsigned int>(time(0)));
                gameMode = new GameMode(selectedDifficulty); // Seed random number generator
}

Game::~Game() {
    delete gameMode;
}

//runs the main game loop 
void Game::run() {
    Clock clock;
    // while game is open and player is alive
    while (window.isOpen() && gameRunning) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render(); // render all of the graphics
    }

    // deallocate falling items
    for (auto& item : fallingItems) {
        delete item;
    }
}

// handles if window is still open
void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

// handles players input, position and the rest of the games mechanics 
void Game::update(float deltaTime) {
    float spawnInterval = gameMode->getSpawnRate();
    float hazardSpawnInterval = gameMode->getHazardSpawnRate();
    float fallingSpeed = gameMode->getFallingSpeed();
    player.handleInput(window);
    player.update(deltaTime, window);

    // Spawn new items
    spawnTimer += deltaTime;
    hazardSpawnTimer += deltaTime; // Increments hazard timer

    // Check if it's time to spawn a food item
    if (spawnTimer >= spawnInterval) {
        spawnTimer = 0.0f; // Reset spawn timer
        spawnFallingObjects(isHazard); // Spawn a food item
    }

    // Check if it's time to spawn a hazard
    if (hazardSpawnTimer >= hazardSpawnInterval) {
        hazardSpawnTimer = 0.0f; // Reset hazard timer
        spawnFallingObjects(true); // Pass true to spawn a hazard
    }

    for (auto it = fallingItems.begin(); it != fallingItems.end(); ) { 
            (*it)->update(deltaTime);
            if (auto foodItem = dynamic_cast<FoodItem*>(*it)) { // if its a food item
                foodItem->checkCollision(player, burger);
                if (foodItem->getIsCaught()) {
                    it = fallingItems.erase(it);
                    continue;
                }
            } else if (auto hazard = dynamic_cast<Hazards*>(*it)) { // if object is a hazard
                hazard->checkCollision(player, burger);
                if (hazard->getIsCaught()) {
                    if (auto poisonBottle = dynamic_cast<PoisonBottle*>(hazard)) { // checks if its the poison bottle
                        poisonBottle->applyPoisonEffect(player);
                        //burger.startFlashing(0.03f);
                    } else {
                        player.loseLife();    //if its the other hazards, lose a life. 
                    }
                    //burger.startFlashing(1.f);
                    delete *it; // delete the dynamically allocated object                  
                    it = fallingItems.erase(it); // removes graphic
                    
                    if (!player.isAlive()){  // if player is not alive. end the game
                        gameRunning = false;
                        std::cout<<"Total Points: "<<burger.getTotalPoints()<<std::endl;
                    }
                    continue;
                }
            }
            ++it;        
        }

     // camera logic.
        float topOfStackY = burger.getTopOfStack(player.getPlayerPosition()).y;
    
        // If the stack is above halfway the window height, the burger pile moves down
        if (topOfStackY < halfWindowHeight) {
            player.setPosition(Vector2f(player.getPlayerPosition().x, player.getPlayerPosition().y + cameraMoveSpeed));
            burger.moveDown(cameraMoveSpeed); 
        }
}

// renders all of the objects/windows graphics 
void Game::render() {
    window.clear(Color(197, 234, 250));

    // Render falling items
    for (auto& item : fallingItems) {
        item->render(window);
    }

    player.render(window);
    burger.render(window, player.getPlayerPosition(), player);
    window.display();
}

// spawns food items food and objects 
void Game::spawnFallingObjects(bool isHazard) {
    // Generate random X position within window width
    float randomX = static_cast<float>(rand() % window.getSize().x);
    
     FallingObjects* newItem = nullptr;
    
    // If spawning a hazard
    if (isHazard) {
        int randomHazardType = rand() % 3; // Adjust this based on how many hazards you have
        if (randomHazardType == 0) {
            newItem = new Bomb();
        } else if (randomHazardType == 1) {
            newItem = new Sock();
        } else {
            newItem = new PoisonBottle();
        }
    } else { // If spawning a food item
        int randomFoodType = rand() % 6;
        if (randomFoodType == 0) {
            newItem = new Lettuce();
        } else if (randomFoodType == 1) {
            newItem = new Tomato();
        } else if (randomFoodType == 2) {
            newItem = new Patty();
        } else if (randomFoodType == 3) {
            newItem = new Cheese();
        } else if (randomFoodType == 4) {
            newItem = new Onion();
        } else {
            newItem = new GoldenIngredient();
        }
            
        
    }

    newItem->setPosition(Vector2f(randomX, 0.0f));
    fallingItems.push_back(newItem); // Adds the new item to the vector

}


bool Game::isGameOver() const {
    return !gameRunning;  // If gameRunning is false, the game is over
}

int Game:: getCurrentScore() const {
        return burger.getTotalPoints();
    }

const Score& Game::getScore() const {
     return score; 
     }