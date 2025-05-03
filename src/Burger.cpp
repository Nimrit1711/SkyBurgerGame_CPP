#include "Burger.h"
#include "Player.h"
#include "FoodItem.h"

using namespace std;
#include <iostream>
Burger::Burger(): totalPoints(0), isFlashing(false), flashDuration(0.5f), flashInterval(0.1f), flashColor(Color::Red){}

Burger:: ~Burger(){
    for (FoodItem* ingredient : burgerPile) {
        delete ingredient;
    }
}

// if collided, adds ingredient to the burger pile
void Burger::addIngredient(FoodItem* ingredient) {
    originalColors.push_back(ingredient->getFoodColor()); //stores the ingredients original colour
    incrementScore(ingredient->getPointValue());  // calculates points on the burger
    burgerPile.push_back(move(ingredient)); // Stores the ingredients
}

//render burgers graphics ontop of the player
void Burger::render(RenderWindow& window, const Vector2f& playerPosition,  const Player& player) {
     float yStackPosition = playerPosition.y; 

    float playerWidth = player.getPlayerBounds().width; // gets player width

    // rendering the flashing animation
    for (size_t i = 0; i < burgerPile.size(); ++i) {
       if (isFlashing && flashTimer.getElapsedTime().asSeconds() < flashDuration) {
            if (static_cast<int>(flashTimer.getElapsedTime().asSeconds() / flashInterval) % 2 == 0) { // if timer is at even time to alternate between red and og colour
                burgerPile[i]->setFoodColor(flashColor);  // Flashes red
            } else {
                burgerPile[i]->setFoodColor(originalColors[i]);  // flashes original color
            }
        } else {
            burgerPile[i]->setFoodColor(originalColors[i]);  // reverts back to og colour when its not flashion
        }

        // Calculates the y-position for each ingredient
        yStackPosition -= burgerPile[i]->getGlobalBounds().height;

        // Centers the ingredient horizontally on the player's position
        float itemWidth = burgerPile[i]->getGlobalBounds().width;
        float xCentered = playerPosition.x + (playerWidth / 2) - (itemWidth / 2);

        // Sets the position and renders the ingredient
        burgerPile[i]->setPosition(Vector2f(xCentered, yStackPosition));
        burgerPile[i]->render(window);
    }

    updateFlash();  // Updates the flashing status
}

int Burger::getTotalPoints() const {
    return totalPoints; 
}


void Burger::incrementScore(int points) {
    totalPoints += points;
}

//returns the position of the ingredient on the top of the stack
Vector2f Burger::getTopOfStack(const Vector2f& playerPosition) const {
  if (burgerPile.empty()) {
        // If no ingredients, return the player's position
        return playerPosition;  
    } else {
        // Gets the position of the topmost ingredient
        const auto& topItem = burgerPile.back();
        FloatRect topBounds = topItem->getGlobalBounds();
        //return the position
        return Vector2f(topItem->getPosition().x, topBounds.top);
    }
}

//moving the burger down if burger stack is to high
void Burger::moveDown(float distance) {
    for (auto& item : burgerPile) {
        item->setPosition(item->getPosition() + Vector2f(0, distance));
    }
}


void Burger::startFlashing(float duration) {
    isFlashing = true; //sets isFlashting to true when a hazard collides with player
    flashDuration = duration;
    flashTimer.restart();
}

void Burger::updateFlash() {
    if (isFlashing && flashTimer.getElapsedTime().asSeconds() >= flashDuration) {
        isFlashing = false; 
    }
}

void Burger::burgerReset() {
    burgerPile.clear();  // Clear the burger stack
}

