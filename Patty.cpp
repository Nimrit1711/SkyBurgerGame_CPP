#include "Patty.h"

Patty::Patty() : FoodItem("Patty.png", 3, 90.f) {
    
}

unique_ptr<FoodItem> Patty::create() const {
    return std::make_unique<Patty>();
}
