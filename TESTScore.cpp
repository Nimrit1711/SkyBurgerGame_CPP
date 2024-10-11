#include <iostream>
#include "Score.h"
#include "FoodItem.h"

// Dummy Player and Burger classes to match the function signatures
class Player {};
class Burger {};

// Implementing a simple food item for testing
class SimpleFoodItem : public FoodItem {
public:
    SimpleFoodItem(int points, float speed) : FoodItem(points, speed) {}

    // Implementing pure virtual functions from FallingObjects
    void setPosition(const sf::Vector2f& pos) override {}
    void update(float deltaTime) override {}
    void render(sf::RenderWindow& window) override {}
    void checkCollision(Player& player, Burger& burger) override {}
    sf::FloatRect getGlobalBounds() const override { return sf::FloatRect(); }
    FoodItem* create() const override { return new SimpleFoodItem(pointValue, fallSpeed); }
};

int main() {
    // Create a Score object
    Score score;

    // Create some food items (regular and golden items)
    SimpleFoodItem regularItem(1, 1.0f);  // Regular food item worth 1 point
    SimpleFoodItem goldenItem(5, 1.0f);   // Golden food item worth 5 points

    // Test adding points
    std::cout << "Initial score: " << score.getCurrentScore() << std::endl;

    // Collect some regular items
    score.updateScore(regularItem);
    score.updateScore(regularItem);
    std::cout << "Score after collecting 2 regular items: " << score.getCurrentScore() << std::endl;

    // Collect a golden item
    score.updateScore(goldenItem);
    std::cout << "Score after collecting a golden item: " << score.getCurrentScore() << std::endl;

    // Update highest score and display it
    score.updateHighestScore();
    std::cout << "Highest score so far: " << score.getHighestScore() << std::endl;

    // Reset the score and test the highest score remains the same
    score.resetScore();
    std::cout << "Score after reset: " << score.getCurrentScore() << std::endl;
    std::cout << "Highest score after reset: " << score.getHighestScore() << std::endl;

    return 0;
}
