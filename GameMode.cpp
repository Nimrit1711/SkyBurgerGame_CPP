#include "GameMode.h"

// Constructor that sets the game mode and initializes parameters
GameMode::GameMode(Difficulty mode) {
    setGameMode(mode);
}

// getter for falling speed
float GameMode::getFallingSpeed() const {
    return fallingSpeed;
}

// getter for spawn rate
float GameMode::getSpawnRate() const {
    return spawnRate;
}

// getter for hazard spawn rate
float GameMode::getHazardSpawnRate() const {
    return hazardSpawnRate;
}

// setting the gamemode:
void GameMode::setGameMode(Difficulty mode) {
    switch (mode) {
        // if mode is easy:
        case Difficulty::Easy:
            fallingSpeed = 180.0f; // Lower falling speed
            spawnRate = 1.0f;       // food Spawns every 1 seconds
            hazardSpawnRate = 3.0f; // hazard spawns every 3 seconds
            break;
        case Difficulty::Normal:
            fallingSpeed = 200.0f; // Normal falling speed
            spawnRate = 1.0f;       // food Spawns every 1 second
            hazardSpawnRate = 2.0f; // hazard spawns every 2 seconds
            break;
        case Difficulty::Hard:
            fallingSpeed = 220.0f; // faster falling speed
            spawnRate = 1.0f;      // food Spawns every 1 second
            hazardSpawnRate = 0.5f; // hazard spawns every 0.5 seconds
            break;       
    }
}
