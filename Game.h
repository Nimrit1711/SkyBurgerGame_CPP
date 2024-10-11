#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <cstdlib> 
#include <iostream> 
#include <ctime>   
#include "Player.h"
#include "Score.h"
#include "FoodItem.h"
#include "FallingObjects.h"
#include "Burger.h"
#include "Lettuce.h"
#include "Tomato.h"
#include "Onion.h"
#include "Patty.h"
#include "Cheese.h"
#include "Hazards.h"
#include "PoisonBottle.h"
#include "GoldenIngredient.h"
#include "Bomb.h"
#include "BananaPeel.h"
#include "Sock.h"
#include "GameMode.h"
using namespace sf;
using namespace std;

class Game {
public:
    Game(GameMode::Difficulty selectedDifficulty, RenderWindow& existingWindow);
    void run(); // Main game loop
    ~Game();
    bool isGameOver() const;
    int getCurrentScore() const;
    const Score& getScore() const;


private:
    GameMode* gameMode; // pointer to the GameMode selection
    void processEvents();
    void update(float deltaTime);
    void render();
    void spawnFallingObjects(bool isHazard);
    

    Score score;
    RenderWindow& window;
    Player player;
    Burger burger;
    vector<FallingObjects*> fallingItems; //lists of falling items 

    float spawnTimer;  // timer for food 
    float hazardSpawnTimer; // timer for hazards
    float spawnInterval;
    const float cameraMoveSpeed;
    bool gameRunning; // checks if game is running/player is alive
    const float halfWindowHeight; // half window size for camera control
    bool isHazard; //checks if falling object is hazard or foodItem
    
};

#endif 
