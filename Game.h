#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "Player.h"
#include "Burger.h"
#include "GameMode.h"
#include "Score.h"
#include "FallingObjects.h"
#include "Lettuce.h"      
#include "Tomato.h"       
#include "Cheese.h"       
#include "Onion.h"        
#include "Patty.h"        
#include "BananaPeel.h"  
#include "GoldenIngredient.h"     
#include "Bomb.h"         
#include "PoisonBottle.h" 
#include "Sock.h"         

class Game {
public:
    // Constructor to initialize the game
    Game();

    // Runs the main game loop
    void run();

    // Setters for hazard spawn rate and falling speed multiplier
    void setHazardSpawnRate(int rate);
    void setFallSpeedMultiplier(int multiplier);

private:
    // Initializes game components
    void initialize();

    // Processes player inputs and window events
    void handleInput();

    // Updates the game logic
    void update(float deltaTime);

    // Renders game objects
    void render();

    // Spawns new falling objects (food or hazards)
    void spawnObjects();

    // Checks for collisions between player, food, and hazards
    void checkAllCollisions();

    // Handles the game-over condition
    void handleGameOver();

    // Resets the game state after game over
    void resetGame();

    sf::RenderWindow window;                  // The game window
    Player player;                            // Player object
    Burger burger;                            // Burger object
    GameMode gameMode;                        // Current game mode
    Score score;                              // Tracks player's score
    sf::Clock clock;                          // SFML clock for tracking time
    std::vector<std::unique_ptr<FallingObjects>> fallingItems; // List of falling objects
    float spawnTimer;                         // Timer for spawning objects
    bool gameRunning;                         // Game running status

    // Private members controlled via setters
    int hazardSpawnRate;                      // Hazard spawn rate based on game mode
    int fallSpeedMultiplier;                  // Fall speed multiplier based on game mode
};

#endif // GAME_H