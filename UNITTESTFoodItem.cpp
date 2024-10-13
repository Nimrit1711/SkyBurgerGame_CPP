#include <iostream>
#include "FoodItem.h"

// Implementing a test food item class for testing
class testerFoodItem : public FoodItem {
public:
    testerFoodItem(int points, float speed) : FoodItem(points, speed) {}

    // Implement abstract methods
    void setPosition(const sf::Vector2f& pos) override {}
    void update(float deltaTime) override {}
    void render(sf::RenderWindow& window) override {}
    void checkCollision(Player& player, Burger& burger) override {}
    sf::FloatRect getGlobalBounds() const override { return sf::FloatRect(); }
    FoodItem* create() const override { return new testerFoodItem(pointValue, fallSpeed); }

    // Add getter method for fall speed
    float getFallSpeed() const { return fallSpeed; }  // Return the fall speed
};

int main() {
    testerFoodItem item(1, 1.0f);  // Create a tester food item with 1 point and speed 1.0f

    // Test food item properties
    std::cout << "Food Item Points: " << item.getPointValue() << std::endl;
    std::cout << "Food Item Speed: " << item.getFallSpeed() << std::endl;  // Now getFallSpeed works

    return 0;
}
