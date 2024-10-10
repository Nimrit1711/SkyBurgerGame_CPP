#ifndef SCORE_H
#define SCORE_H

#include "FoodItem.h"
#include "Burger.h"
 // Access point values

class Score {
private:
    int currentScore;   // The player's current score
    int highestScore;   // The highest score achieved

public:
    Score();
    void updateScore(const Burger &score);  // Update score based accumilated burger
    void updateHighestScore();  // Update highest score if the current score surpasses it
    int getCurrentScore() const;  // Get the current score
    int getHighestScore() const;  // Get the highest score
    void resetScore();  // Reset the current score (e.g., on game restart)
};

#endif
