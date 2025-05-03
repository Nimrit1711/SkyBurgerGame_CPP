#ifndef GAMEMODE_H
#define GAMEMODE_H

#include <string>

class GameMode {
public:
    // Difficulties modes choices:
    enum class Difficulty {
        Easy,
        Normal,
        Hard        
    };

    GameMode(Difficulty mode);

    // getters for game parameters
    float getFallingSpeed() const;
    float getSpawnRate() const;
    float getHazardSpawnRate() const;

    // Method to set parameters based on selected difficulty
    void setGameMode(Difficulty mode);

private:
    float fallingSpeed;
    float spawnRate;
    float hazardSpawnRate;
};

#endif
