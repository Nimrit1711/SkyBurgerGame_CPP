#ifndef BURGER_H
#define BURGER_H

#include "FoodItem.h"
#include <vector>
#include <memory>


class Burger {
private:
    vector<unique_ptr<FoodItem>> burgerPile;
    vector<Color> originalColors;
    int totalPoints;
    //for flashing animation
    bool isFlashing;
    Clock flashTimer;
    float flashDuration;
    float flashInterval;
    Color flashColor;
  

public:
    Burger();
    void addIngredient(unique_ptr<FoodItem> ingredient);
    void render(RenderWindow& window, const Vector2f& playerPosition, const Player& player);
    int getTotalPoints() const;
    Vector2f getTopOfStack(const Vector2f& playerPosition) const;
    void moveDown(float distance);
    //void startFlashing(float duration); 
    //void updateFlash();
    
};

#endif
