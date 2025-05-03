#include "Patty.h"

Patty::Patty() : FoodItem(3, 120.f) {
    foodShape.setFillColor(Color(125, 60, 17));
    
}

FoodItem* Patty::create() const {
    return new Patty();
}
