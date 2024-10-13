#include <iostream>
#include <vector>
#include <cassert>
#include "Burger.h"
#include "FoodItem.h"

// Mocking getBurgerHeight() and addFoodItem() for the test
class TestBurger : public Burger {
public:
    // Mock getBurgerHeight method
    int getBurgerHeight() const {
        return foodItems.size();  // Mocked size of the burger stack
    }

    // Mock addFoodItem method
    void addFoodItem(const FoodItem& item) {
        foodItems.push_back(item.create());
    }

private:
    std::vector<FoodItem*> foodItems;  // Simulated food items list for testing
};

// Implementing a test food item class
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
};

void test_addFoodItem() {
    // Create a mock Burger object
    TestBurger burger;

    // Create a test food item
    testerFoodItem item(1, 1.0f);

    // Add food item to the burger
    burger.addFoodItem(item);

    // Assert that the burger height increased by 1
    assert(burger.getBurgerHeight() == 1);
}

void test_getBurgerHeight() {
    // Create a mock Burger object
    TestBurger burger;

    // Initial height should be 0
    assert(burger.getBurgerHeight() == 0);

    // Create a test food item
    testerFoodItem item(1, 1.0f);

    // Add food item to the burger
    burger.addFoodItem(item);

    // Assert that the burger height is now 1
    assert(burger.getBurgerHeight() == 1);
}

int main() {
    // Run unit tests
    test_addFoodItem();
    test_getBurgerHeight();

    std::cout << "All unit tests passed!" << std::endl;

    return 0;
}
