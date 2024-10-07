#include "Onion.h"

Onion::Onion() : FoodItem(4, 115.f) {
    foodShape.setFillColor(Color(185, 108, 147));
    
}

unique_ptr<FoodItem> Onion::create() const {
    return std::make_unique<Onion>();
}
