#include "FoodItem.h"
#include "Player.h"
#include "Burger.h"



FoodItem::FoodItem(const string& textureFile, int points, float speed)
    : pointValue(points), fallSpeed(speed), isCaught(false) {
    foodTexture.loadFromFile(textureFile);
    sprite.setTexture(foodTexture);
    sprite.setScale(0.5f, 0.5f);
}

void FoodItem::update(float deltaTime) {
    sprite.move(0, fallSpeed * deltaTime);
}

void FoodItem::render(RenderWindow& window) {
    window.draw(sprite);
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
    return sprite.getGlobalBounds();
}


void FoodItem::setPosition(const Vector2f& pos) {
    sprite.setPosition(pos);
}

Vector2f FoodItem:: getPosition() const{
    return sprite.getPosition();
}