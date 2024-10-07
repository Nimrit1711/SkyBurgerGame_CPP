#include "FoodItem.h"
#include "Player.h"
#include "Burger.h"
#include <iostream>


FoodItem::FoodItem(int points, float speed):
    pointValue(points), fallSpeed(speed), isCaught(false) {
    foodShape.setSize(Vector2f(100.f, 20.f));
    foodShape.setFillColor(Color::Green); 
    }

void FoodItem::update(float deltaTime) {
    foodShape.move(0, fallSpeed * deltaTime);
}

void FoodItem::render(RenderWindow& window) {
    window.draw(foodShape);
}

void FoodItem::checkCollision(Player& player, Burger& burger) {
     if (getIsCaught()) {
        return; //skips if added to the burger pile
    }
    Vector2f playerPosition=player.getPlayerPosition();
    Vector2f topOfStack = burger.getTopOfStack(playerPosition);
    FloatRect foodBounds = getGlobalBounds();

    if (foodBounds.intersects(FloatRect(topOfStack.x, topOfStack.y, foodBounds.width, foodBounds.height))) {
        // Add the current FoodItem to the burger
        
        burger.addIngredient(create());
        setIsCaught(true);
        fallSpeed = 0.0f;
    }       
}


bool FoodItem::getIsCaught() const {
    return isCaught;
}

void FoodItem::setIsCaught(bool added) {
    isCaught= added;
}

FloatRect FoodItem::getGlobalBounds() const {
    return foodShape.getGlobalBounds();
}


void FoodItem::setPosition(const Vector2f& pos) {
    foodShape.setPosition(pos);
}

Vector2f FoodItem:: getPosition() const{
    return foodShape.getPosition();
}

void FoodItem::setFoodColor(const Color& color) {
    foodShape.setFillColor(color);
}

 Color FoodItem:: getFoodColor() const {
        return foodShape.getFillColor();
    }
