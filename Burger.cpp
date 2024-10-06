#include "Burger.h"

Burger::Burger() : totalPoints(0) {}

void Burger::addIngredient(std::unique_ptr<FoodItem> ingredient) {
    totalPoints += ingredient->getPointValue(); // Updates the total points
    burgerPile.push_back(move(ingredient)); // Stores the ingredients
}

void Burger::render(sf::RenderWindow& window, const sf::Vector2f& playerPosition) {
    for (const auto& item : burgerPile) {
        item->render(window); // Renders each ingredient
    }
}

int Burger::getTotalPoints() const {
    return totalPoints; 
}
