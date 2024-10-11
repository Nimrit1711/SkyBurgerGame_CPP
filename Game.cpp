#include "Game.h"
#include <cstdlib> 
#include <iostream> 
#include <ctime>

Game::Game() : window(sf::VideoMode(900, 800), "Sky Burger Game"),
               player(&burger), spawnTimer(0.0f), spawnInterval(0.5f), cameraMoveSpeed(1.0f),
               gameRunning(true), halfWindowHeight(window.getSize().y / 2) {
                srand(static_cast<unsigned int>(time(0)));
                gameMode = new GameMode(GameMode::Difficulty::Easy); // Seed random number generator
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
    float fallingSpeed = gameMode->getFallingSpeed();
    player.handleInput(window);
    player.update(deltaTime, window);

    // Spawn new items
    spawnTimer += deltaTime;
    if (spawnTimer >= spawnInterval) {
        spawnTimer = 0.0f; // Reset spawn timer
        spawnFallingObjects();
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
    window.clear(sf::Color(197, 234, 250));

    // Render falling items
    for (auto& item : fallingItems) {
        item->render(window);
    }

    player.render(window);
    burger.render(window, player.getPlayerPosition(), player);
    window.display();
}

// spawns food items food and objects 
void Game::spawnFallingObjects() {
    // Generate random X position within window width
    float randomX = static_cast<float>(rand() % window.getSize().x);
    
    // Randomly select a food type to spawn
    int randomSpawnType = rand() % 10;

    FallingObjects* newItem = nullptr;
    if (randomSpawnType == 0) {
        newItem = new Lettuce();
    } else if (randomSpawnType == 1) {
        newItem = new Tomato();
    } else if (randomSpawnType == 2) {
        newItem = new Patty();
    } else if (randomSpawnType == 3) {
        newItem = new Cheese();
    } else if (randomSpawnType == 4) {
        newItem = new Onion();
    } else if (randomSpawnType == 5) {
        newItem = new Bomb();
    } else if (randomSpawnType == 6) {
        newItem = new Sock();
    } else if (randomSpawnType == 7) {
        newItem = new BananaPeel();
    } else if (randomSpawnType == 8) {
        newItem = new GoldenIngredient();
    } else {
        newItem = new PoisonBottle();
    }

    newItem->setPosition(sf::Vector2f(randomX, 0.0f));
    fallingItems.push_back(newItem); // Adds the new item to the vector
}
