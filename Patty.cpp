#include "Patty.h"

Patty::Patty() : FoodItem(3, 120.f) {
    foodShape.setFillColor(Color(125, 60, 17));
    
}

unique_ptr<FoodItem> Patty::create() const {
    return std::make_unique<Patty>();
}
