#include "Onion.h"

Onion::Onion() : FoodItem(4, 115.f) {
    foodShape.setFillColor(Color(185, 108, 147));
    
}

FoodItem* Onion::create() const {
    return new Onion();
}
