#include "GoldenIngredient.h"

#include <iostream>

GoldenIngredient::GoldenIngredient() : FoodItem(50, 220.f) {
    
    if (!goldenTexture.loadFromFile("assets/images/goldCoin.png")){
            std::cout<<"file not loaded"<<endl;
        }
        foodShape.setTexture(&goldenTexture);
        foodShape.setScale(0.5f, 2.5f);
}


FoodItem* GoldenIngredient::create() const {
    return new GoldenIngredient();
}


void GoldenIngredient::checkCollision(Player& player, Burger& burger) {
      if (getIsCaught()) {
        return; // Skip if already caught
    }

    Vector2f playerPosition=player.getPlayerPosition(); // gets player position
    Vector2f topOfStack = burger.getTopOfStack(playerPosition); // gets top of stack 
    FloatRect foodBounds = getGlobalBounds(); // gets bounds of the falling food item 

    if (foodBounds.intersects(FloatRect(topOfStack.x, topOfStack.y, foodBounds.width, foodBounds.height))) { // if food does hit player
        burger.incrementScore(getPointValue());  // Award 50 points       
        setIsCaught(true);  // set to is caught
        fallSpeed = 0.0f; //stop the food from falling
    }        
}