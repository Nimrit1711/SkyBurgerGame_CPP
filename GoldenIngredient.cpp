#include "GoldenIngredient.h"
#include <iostream>

GoldenIngredient::GoldenIngredient() : FoodItem(50, 190.f) {
    
    if (!goldenTexture.loadFromFile("goldCoin.png")){
            std::cout<<"file not loaded"<<endl;
        }
        foodShape.setTexture(&goldenTexture);
        foodShape.setScale(1.5f, 1.5f);
}


FoodItem* GoldenIngredient::create() const {
    return new GoldenIngredient();
}
