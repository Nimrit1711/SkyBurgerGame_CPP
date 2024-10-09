#include "Score.h"

// Constructor to initialize scores
Score::Score() : currentScore(0), highestScore(0) {}

// Update the score based on the collected food item
void Score::updateScore(const FoodItem &food) {
    // Use FoodItem's getPointValue() to add points to the current score
    currentScore += food.getPointValue();
}

// Update the highest score if the current score exceeds it
void Score::updateHighestScore() {
    if (currentScore > highestScore) {
        highestScore = currentScore;
    }
}

// Get the current score
int Score::getCurrentScore() const {
    return currentScore;
}

// Get the highest score
int Score::getHighestScore() const {
    return highestScore;
}

// Reset the current score (useful for restarting the game)
void Score::resetScore() {
    currentScore = 0;
}
