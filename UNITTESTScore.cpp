#include <iostream>
#include "Score.h"
#include "Burger.h"

int main() {
    Score score;
    Burger burger;

    // Test initial score
    std::cout << "Initial score: " << score.getCurrentScore(SettingsMenu::DEFAULT) << std::endl;

    // Update the score
    score.updateScore(burger, SettingsMenu::DEFAULT);
    score.updateScore(burger, SettingsMenu::DEFAULT);
    std::cout << "Score after updates: " << score.getCurrentScore(SettingsMenu::DEFAULT) << std::endl;

    // Test highest score
    score.updateHighestScore(SettingsMenu::DEFAULT);
    std::cout << "Highest score: " << score.getHighestScore() << std::endl;

    // Reset the score
    score.resetScore(SettingsMenu::DEFAULT);
    std::cout << "Score after reset: " << score.getCurrentScore(SettingsMenu::DEFAULT) << std::endl;

    return 0;
}
