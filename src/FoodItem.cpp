#include "FoodItem.h"
#include "Player.h"
#include "Burger.h"
#include <iostream>


FoodItem::FoodItem(int points, float speed):
    pointValue(points), fallSpeed(speed), isCaught(false) {
    foodShape.setSize(Vector2f(100.f, 20.f));
     
    }

//updates foodItems position
void FoodItem::update(float deltaTime) {
    foodShape.move(0, fallSpeed * deltaTime);
}

//renders FoodItems graphics
void FoodItem::render(RenderWindow& window) {
    window.draw(foodShape);
}

//checks if the food item has collided with the player and burgerpile
void FoodItem::checkCollision(Player& player, Burger& burger) {
     if (getIsCaught()) {
        return; //skips if added to the burger pile
    }
    Vector2f playerPosition=player.getPlayerPosition(); // gets player position
    Vector2f topOfStack = burger.getTopOfStack(playerPosition); // gets top of stack 
    FloatRect foodBounds = getGlobalBounds(); // gets bounds of the falling food item 

    if (foodBounds.intersects(FloatRect(topOfStack.x, topOfStack.y, foodBounds.width, foodBounds.height))) { // if food does hit player
        // Add the current FoodItem to the burger        
        burger.addIngredient(create());  // creates a new ingredient and adds to stack
        setIsCaught(true);  // set to is caught
        fallSpeed = 0.0f; //stop the food from falling
    }        
}

// bool flag if the item is caught
bool FoodItem::getIsCaught() const {
    return isCaught;
}

//sets if the food item is caught
void FoodItem::setIsCaught(bool added) {
    isCaught= added;
}

FloatRect FoodItem::getGlobalBounds() const {
    return foodShape.getGlobalBounds();
}

//sets position of foodItem
void FoodItem::setPosition(const Vector2f& pos) {
    foodShape.setPosition(pos);
}

//returns 2f vector position of food item
Vector2f FoodItem:: getPosition() const{
    return foodShape.getPosition();
}

void FoodItem::setFoodColor(const Color& color) {
    foodShape.setFillColor(color);
}

 Color FoodItem:: getFoodColor() const {
        return foodShape.getFillColor();
    }
