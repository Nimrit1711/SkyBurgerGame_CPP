// tester for when burger collects golden and regular ingredient

#include <iostream>
#include "Score.h"
#include "Burger.h"
#include "GoldenIngredient.h"

// Dummy Player class for testing
class Player {};

// Implementing a simple burger class for testing
class SimpleBurger : public Burger {
public:
    SimpleBurger() {}

    // You can implement scoring related behavior if needed
};

int main() {
    // Create a Score object
    Score score;

    // Create a Burger object
    SimpleBurger burger;

    // Create a Player object
    Player player;

    // Create a GoldenIngredient object
    GoldenIngredient goldenItem;

    // Test the initial score
    std::cout << "Initial score: " << score.getCurrentScore(SettingsMenu::DEFAULT) << std::endl;

    // Simulate collecting some items (using burger for regular items)
    score.updateScore(burger, SettingsMenu::DEFAULT);  // Collect regular food
    score.updateScore(burger, SettingsMenu::DEFAULT);  // Collect another regular food
    std::cout << "Score after collecting 2 regular items: " << score.getCurrentScore(SettingsMenu::DEFAULT) << std::endl;

    // Simulate collision with the golden ingredient (check collision logic should apply)
    goldenItem.checkCollision(player, burger);  // Simulate interaction with the player and burger
    score.updateScore(burger, SettingsMenu::DEFAULT);  // Assuming collision increases score
    std::cout << "Score after collecting a golden item: " << score.getCurrentScore(SettingsMenu::DEFAULT) << std::endl;

    // Update highest score and display it
    score.updateHighestScore(SettingsMenu::DEFAULT);
    std::cout << "Highest score so far: " << score.getHighestScore() << std::endl;

    // Reset the score and test the highest score remains the same
    score.resetScore(SettingsMenu::DEFAULT);
    std::cout << "Score after reset: " << score.getCurrentScore(SettingsMenu::DEFAULT) << std::endl;
    std::cout << "Highest score after reset: " << score.getHighestScore() << std::endl;

    return 0;
}
