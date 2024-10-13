//test burger source and header filexs

#include <iostream>
#include "Burger.h"
#include "FoodItem.h"  
#include "Player.h"     // Assuming SFML is used for rendering

class FoodItem {
public:
    FoodItem(const std::string& name, int points) {
        // constructor body (for testing)
    }
    
    int getPointValue() const {
        return 5;  // example value
    }

    void render(sf::RenderWindow& window) {
        // rendering logic (for testing)
    }
    
    sf::FloatRect getGlobalBounds() const {
        return sf::FloatRect(0, 0, 50, 50);  // example bounding box
    }

    sf::Color getFoodColor() const {
        return sf::Color::Green;  // example color
    }

    void setPosition(sf::Vector2f position) {
        // example set position
    }
    
    sf::Vector2f getPosition() const {
        return sf::Vector2f(0, 0);  // example position
    }
};

class Player {
public:
    Player() {
        // constructor (for testing)
    }

    sf::FloatRect getPlayerBounds() const {
        return sf::FloatRect(0, 0, 50, 50);  // example player bounds
    }
};



int main() {
    // Initialize objects for testing
    Burger burger;
    Player player;  
    sf::RenderWindow window(sf::VideoMode(800, 600), "Burger Test");

    // Test adding ingredients
    FoodItem* lettuce = new FoodItem("Lettuce", 5);  // Assuming FoodItem constructor (name, points)
    FoodItem* cheese = new FoodItem("Cheese", 10);

    burger.addIngredient(lettuce);
    burger.addIngredient(cheese);

    // Test score calculation
    std::cout << "Total points after adding ingredients: " << burger.getTotalPoints() << std::endl;

    // Test rendering
    sf::Vector2f playerPosition(400.f, 500.f);  // Player position
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Test rendering the burger on top of the player
        burger.render(window, playerPosition, player);

        window.display();
    }

    // Test moving the burger stack down
    std::cout << "Moving burger stack down by 10 units." << std::endl;
    burger.moveDown(10.0f);

    // Test flashing functionality
    std::cout << "Starting flashing for 2 seconds." << std::endl;
    burger.startFlashing(2.0f);
    
    // Simulate time passing to test flashing
    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 3.0f) {
        burger.updateFlash();
    }
    
    std::cout << "Flash should have ended." << std::endl;

    // Test resetting the burger
    burger.burgerReset();
    std::cout << "Burger reset. Total points after reset: " << burger.getTotalPoints() << std::endl;

    return 0;
}
