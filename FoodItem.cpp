#include "FoodItem.h"


FoodItem:: FoodItem(float fallSpeed, const Vector2f& startingPosition, const string textureFile, int points)
: FallingObjects(startingPosition), pointValue(points), fallSpeed(fallSpeed) {
    setTexture(textureFile);     
}

void FoodItem:: updateObjectPosition(float Time) {
    positionOfObject.y += fallSpeed* Time;
    objectShape.setPosition(positionOfObject);
}

void FoodItem:: renderObject(RenderWindow& window) {
    window.draw(objectShape);

}

void FoodItem:: checkCollision(Player& player, Burger& burger) {
    if (objectShape.getGlobalBounds().intersects(player.getPlayerBounds()))
        {burger.addIngredient(*this);
        //score.addPoints(pointValue);
        isCaught=true;
    }
}
    
int FoodItem:: getPointValue() const{
    return pointValue;
}



