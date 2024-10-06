#include "Burger.h"
#include "FoodItem.h"

using namespace std;
#include <iostream>
Burger::Burger(): totalPoints(0) {}

void Burger::addIngredient(std::unique_ptr<FoodItem> ingredient) {
    totalPoints += ingredient->getPointValue(); // Updates the total points
    burgerPile.push_back(move(ingredient)); // Stores the ingredients
}

void Burger::render(sf::RenderWindow& window, const sf::Vector2f& playerPosition) {
    float yStackPosition= playerPosition.y;    
    for (const auto& item : burgerPile) {
        yStackPosition -= item->getGlobalBounds().height;
        item->setPosition(Vector2f(playerPosition.x, yStackPosition));
        item->render(window); // Renders each ingredient
        cout<<totalPoints<<endl; // testing point score by printing it
    }
}

int Burger::getTotalPoints() const {
    return totalPoints; 
}



Vector2f Burger::getTopOfStack(const Vector2f& playerPosition) const {
  if (burgerPile.empty()) {
        // If no ingredients, return the player's position (bun's position)
        return playerPosition;  // You'll need to pass the player position to this function
    } else {
        // Get the position of the topmost item
        const auto& topItem = burgerPile.back();
        sf::FloatRect topBounds = topItem->getGlobalBounds();
        // Return the position at the top of the topmost item
        return sf::Vector2f(topItem->getPosition().x, topBounds.top);
    }
}

