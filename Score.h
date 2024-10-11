#ifndef SCORE_H
#define SCORE_H

#include "SettingsMenu.h"  // To access the Difficulty enum
#include "Burger.h"        // Holds the score data

class Score {
private:
    int scoreEasy;         // Score for EASY mode
    int scoreDefault;      // Score for DEFAULT mode
    int scoreHard;         // Score for HARD mode
    int highestScore;      // Tracks the highest score overall

public:
    // Constructor
    Score();

    // Update the score based on the collected food item and the difficulty mode
    void updateScore(const Burger &burger, SettingsMenu::Difficulty mode);

    // Update the highest score if the current score in any difficulty exceeds it
    void updateHighestScore(SettingsMenu::Difficulty mode);

    // Get the current score for the selected difficulty
    int getCurrentScore(SettingsMenu::Difficulty mode) const;

    // Get the highest score across all difficulties
    int getHighestScore() const;

    // Reset the current score for the selected difficulty
    void resetScore(SettingsMenu::Difficulty mode);
};

#endif
