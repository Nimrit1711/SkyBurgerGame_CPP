#ifndef GOLDENINGREDIENT_H
#define GOLDENINGREDIENT_H

#include "FoodItem.h"

class GoldenIngredient: public FoodItem{
    private:
    Texture goldenTexture;
    public:
    GoldenIngredient();
    FoodItem* create() const override;
};






#endif