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
            fallingSpeed = 100.0f; // Lower falling speed
            spawnRate = 6.0f;       // Spawns every 1.5 seconds
            hazardSpawnRate = 0.5f; // Fewer hazards
            break;
        case Difficulty::Normal:
            fallingSpeed = 200.0f; // Normal falling speed
            spawnRate = 3.0f;       // Spawns every 1.0 seconds
            hazardSpawnRate = 1.0f; // Normal hazards
            break;
        case Difficulty::Hard:
            fallingSpeed = 230.0f; // Increased falling speed
            spawnRate = 0.75f;      // Spawns every 0.75 seconds
            hazardSpawnRate = 2.0f; // More hazards
            break;       
    }
}
