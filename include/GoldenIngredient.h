#ifndef GOLDENINGREDIENT_H
#define GOLDENINGREDIENT_H

#include "FoodItem.h"
#include "Player.h"
#include "Burger.h"

class GoldenIngredient: public FoodItem{
    private:
    Texture goldenTexture;
    public:
    GoldenIngredient();
    FoodItem* create() const override;
    //overrides as GoldenIngredient does not need to be added on burgerpile
    virtual void checkCollision(Player& player, Burger& burger) override; 
};







#endif