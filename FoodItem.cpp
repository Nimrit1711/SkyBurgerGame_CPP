#include "FoodItem.h"
#include "Player.h"
#include "Burger.h"


FoodItem::FoodItem(const string& textureFile, int points, float speed)
    : pointValue(points), fallSpeed(speed) {
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
    if (player.getPlayerBounds().intersects(getGlobalBounds())) {
        // Add the current FoodItem to the burger
        burger.addIngredient(make_unique<FoodItem>(*this));
    }
}

FloatRect FoodItem::getGlobalBounds() const {
    return sprite.getGlobalBounds();
}


void FoodItem::setPosition(const Vector2f& pos) {
    sprite.setPosition(pos);
}