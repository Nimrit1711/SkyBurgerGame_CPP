#include "Score.h"
#include "Burger.h"

// Constructor
Score::Score(int initialLives) {
    currentScore = 0;  // Initialize current score to 0
    highestScore = 0;  // Initialize highest score to 0 (or retrieve from a file if persistent)
    lives = initialLives;  // Set initial number of lives
    gameOver = false;  // Game is not over initially
}

// Destructor
Score::~Score() {
   
}

// Update score based on the FoodItem's point value
void Score::updateScore(FoodItem& food) {
    currentScore += food.getPointValue(); // check the get point function
    if (lives <= 0) {
        gameOver = true;  // If lives are 0 or less, mark game as over
    }
}

// Update the highest score if the current score is higher
void Score::updateHighestScore() {
    if (currentScore > highestScore) {
        highestScore = currentScore;
    }
}

// Retrieve the highest score
int Score::getHighScore() const {
    return highestScore;
}

// Check if the game is over (when lives are zero or less)
bool Score::isGameOver() const {
    return gameOver;
}
