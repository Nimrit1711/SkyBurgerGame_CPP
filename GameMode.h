#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <string>

class Game;  // Forward declaration of the Game class

class GameMode {
private:
    std::string modeName;  // Stores the current game mode (e.g., "easy", "default", "hard")
    int fallSpeedMultiplier;  // Multiplier to increase the speed of falling objects
    int hazardSpawnRate;      // Controls how frequently hazards spawn

public:
    // Constructor to initialize the game mode
    GameMode(const std::string& modeName = "default");

    // Sets the game mode (easy, default, hard) and adjusts the settings accordingly
    void setGameMode(const std::string& mode);

    // Applies the game mode to the game by adjusting spawn rate and falling speed
    void applyMode(Game& game);

    // Returns the fall speed multiplier based on the current game mode
    int getFallSpeedMultiplier() const;

    // Returns the hazard spawn rate based on the current game mode
    int getHazardSpawnRate() const;

    // Returns the current game mode as a string
    std::string getGameMode() const;
};

#endif // GAMEMODE_H