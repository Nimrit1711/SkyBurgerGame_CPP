#include "Lettuce.h"

Lettuce::Lettuce() : FoodItem("Lettuce.png", 1, 100.f) {
    
}

unique_ptr<FoodItem> Lettuce::create() const {
    return make_unique<Lettuce>();
}
