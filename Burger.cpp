#include "Burger.h"
#include "Player.h"
#include "FoodItem.h"

using namespace std;
#include <iostream>
Burger::Burger(): totalPoints(0) {}

void Burger::addIngredient(std::unique_ptr<FoodItem> ingredient) {
    totalPoints += ingredient->getPointValue(); // Updates the total points
    burgerPile.push_back(move(ingredient)); // Stores the ingredients
}

void Burger::render(RenderWindow& window, const Vector2f& playerPosition,  const Player& player) {
    float yStackPosition= playerPosition.y;  
    //centering the ingreident ontop of the stack
    float playerWidth = player.getPlayerBounds().width;
    for (const auto& item : burgerPile) {
        yStackPosition -= item->getGlobalBounds().height;
        //center
        float itemWidth = item->getGlobalBounds().width;
        float xCentered = playerPosition.x + (playerWidth / 2) - (itemWidth / 2);

        item->setPosition(Vector2f(xCentered, yStackPosition));
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

void Burger::moveDown(float distance) {
    for (auto& item : burgerPile) {
        item->setPosition(item->getPosition() + Vector2f(0, distance));
    }
}

