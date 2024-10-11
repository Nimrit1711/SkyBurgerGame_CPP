#include "GameMode.h"
#include "Game.h"

// Constructor initializes the default game mode and sets appropriate parameters
GameMode::GameMode(const std::string& modeName) : modeName(modeName) {
    setGameMode(modeName);  // Apply settings based on the mode
} 

// Sets the game mode and adjusts the fall speed and hazard spawn rate accordingly
void GameMode::setGameMode(const std::string& mode) {
    modeName = mode;

    // Set the parameters based on the selected game mode
    if (modeName == "easy") {
        fallSpeedMultiplier = 1;  // Slow falling objects
        hazardSpawnRate = 3;      // Less frequent hazard spawns
    } 
    else if (modeName == "hard") {
        fallSpeedMultiplier = 3;  // Faster falling objects
        hazardSpawnRate = 1;      // Frequent hazard spawns
    } 
    else {
        modeName = "default";     // Default mode
        fallSpeedMultiplier = 2;  // Medium speed falling objects
        hazardSpawnRate = 2;      // Medium hazard spawns
    }
}

// Applies the game mode to the game, adjusting spawn rate and falling speed
void GameMode::applyMode(Game& game) {
    // Use setters to modify the game state
    game.setHazardSpawnRate(hazardSpawnRate);
    game.setFallSpeedMultiplier(fallSpeedMultiplier);
}

// Returns the fall speed multiplier based on the current game mode
int GameMode::getFallSpeedMultiplier() const {
    return fallSpeedMultiplier;
}

// Returns the hazard spawn rate based on the current game mode
int GameMode::getHazardSpawnRate() const {
    return hazardSpawnRate;
}

// Returns the current game mode as a string
std::string GameMode::getGameMode() const {
    return modeName;
}