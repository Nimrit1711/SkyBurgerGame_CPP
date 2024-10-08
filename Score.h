#ifndef SCORE_H
#define SCORE_H

#include "FoodItem.h" 
#include <iostream>

class Score {
private:
    int currentScore;  // Player's score in that game
    int highestScore;  // Highest score the player has achieved
    int lives;         // Number of player's lives
    bool gameOver;     // Boolean to indicate if the game is over

public:
    // Constructor
    Score(int initialLives);

    // Destructor
    ~Score();

    // Function declarations
    void updateScore(FoodItem& food); // Increases score based on the food's point value
    void updateHighestScore();        // Updates the highest score
    int getHighScore() const;         // Retrieves the highest score
    bool isGameOver() const;          // Returns true if the player has zero lives
};

#endif
