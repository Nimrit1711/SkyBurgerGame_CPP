#include "Score.h"
#include "SettingsMenu.h"  // Include the difficulty enum from SettingsMenu

// Constructor to initialize scores for each difficulty level
Score::Score() : scoreEasy(0), scoreDefault(0), scoreHard(0), highestScore(0) {}

// Update the score based on the collected food item and difficulty mode
void Score::updateScore(const Burger &burger, SettingsMenu::Difficulty mode) {
    // Use Burger's total point score to update the score for the selected difficulty
    switch (mode) {
        case SettingsMenu::EASY:
            scoreEasy += burger.getTotalPoints();
            break;
        case SettingsMenu::DEFAULT:
            scoreDefault += burger.getTotalPoints();
            break;
        case SettingsMenu::HARD:
            scoreHard += burger.getTotalPoints();
            break;
    } 
}

void Score:: updateScoreN(const Burger &burger){
    currentScore+= burger.getTotalPoints();
}

// Update the highest score based on the current difficulty
void Score::updateHighestScore(SettingsMenu::Difficulty mode) {
    int currentScore = 0;
    switch (mode) {
        case SettingsMenu::EASY:
            currentScore = scoreEasy;
            break;
        case SettingsMenu::DEFAULT:
            currentScore = scoreDefault;
            break;
        case SettingsMenu::HARD:
            currentScore = scoreHard;
            break;
    }

    if (currentScore > highestScore) {
        highestScore = currentScore;
    }
}

// Get the current score for the selected difficulty
int Score::getCurrentScore(SettingsMenu::Difficulty mode) const {
    switch (mode) {
        case SettingsMenu::EASY:
            return scoreEasy;
        case SettingsMenu::DEFAULT:
            return scoreDefault;
        case SettingsMenu::HARD:
            return scoreHard;
        default:
            return 0;  // Default to 0 if mode is not recognized
    }
}

// Get the highest score overall (across all difficulty modes)
int Score::getHighestScore() const {
    return highestScore;
}

// Reset the current score for the selected difficulty (useful for restarting the game)
void Score::resetScore(SettingsMenu::Difficulty mode) {
    switch (mode) {
        case SettingsMenu::EASY:
            scoreEasy = 0;
            break;
        case SettingsMenu::DEFAULT:
            scoreDefault = 0;
            break;
        case SettingsMenu::HARD:
            scoreHard = 0;
            break;
    }
}


void Score:: scoreReset(){
    currentScore=0;
}