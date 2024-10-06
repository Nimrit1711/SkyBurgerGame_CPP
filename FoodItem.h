#ifndef FOODITEM_H
#define FOODITEM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "FallingObjects.h"
#include "Player.h"
#include "Burger.h"

using namespace sf;
using namespace std;


class FoodItem: public FallingObjects{
    protected:
    int pointValue;
    float fallSpeed;
    
    public:
    FoodItem(float fallSpeed, const Vector2f& startingPosition, const string textureFile, int points);
    
    void updateObjectPosition(float Time) override;
    void renderObject(RenderWindow& window) override;
    void checkCollision(Player& player, Burger& burger) override;    
    int getPointValue() const;
};

#endif
