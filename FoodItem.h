#ifndef FOODITEM_H
#define FOODITEM_H

#include "FallingObjects.h"
#include <SFML/Graphics.hpp>
class Player; // Forward declaration
class Burger; 


class FoodItem : public FallingObjects {
protected:
    Sprite sprite;
    Texture foodTexture;
    int pointValue;
    float fallSpeed;

public:
    FoodItem(const string& textureFile, int points, float speed);
    virtual void setPosition(const Vector2f& pos) override; 
    virtual void update(float deltaTime) override;
    virtual void render(RenderWindow& window) override;
    virtual void checkCollision(Player& player, Burger& burger) override;
    virtual FloatRect getGlobalBounds() const override;
    int getPointValue() const { return pointValue; }
};

#endif 
