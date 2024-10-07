#ifndef FOODITEM_H
#define FOODITEM_H

#include "FallingObjects.h"
#include <SFML/Graphics.hpp>
class Player; // Forward declaration
class Burger; 


class FoodItem : public FallingObjects {
protected:
    RectangleShape foodShape;
    int pointValue;
    float fallSpeed;
    bool isCaught;
    

public:
    FoodItem(int points, float speed);
    virtual void setPosition(const Vector2f& pos) override; 
    virtual void update(float deltaTime) override;
    virtual void render(RenderWindow& window) override;
    virtual void checkCollision(Player& player, Burger& burger) override;
    virtual FloatRect getGlobalBounds() const override;
    int getPointValue() const { return pointValue; }
    Vector2f getPosition() const;
    bool getIsCaught() const;
    void setIsCaught(bool added);
    virtual unique_ptr<FoodItem> create() const = 0;
    void changeTexture();  // changes the texture of the food item if its been caught

    

};

#endif 
