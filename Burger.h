#ifndef BURGER_H
#define BURGER_H

#include "FoodItem.h"
#include <vector>
#include <memory>


class Burger {
private:
    vector<unique_ptr<FoodItem>> burgerPile;
    int totalPoints;

public:
    Burger();
    void addIngredient(unique_ptr<FoodItem> ingredient);
    void render(RenderWindow& window, const Vector2f& playerPosition);
    int getTotalPoints() const;
};

#endif
