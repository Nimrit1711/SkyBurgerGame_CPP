#ifndef BURGER_H
#define BURGER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "FoodItem.h"

class Burger {

private:
vector<unique_ptr<FoodItem>> burgerPile;
int stackHeight;

public:
Burger();
void addIngredient(unique_ptr<FoodItem> ingredient);
void clearStack();
void renderBurger(sf::RenderWindow& window, const sf::Vector2f& playerPosition);
void setStackHeight(int height);
int getStackHeight();
};
#endif