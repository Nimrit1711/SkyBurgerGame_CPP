#include "Lettuce.h"

Lettuce::Lettuce() : FoodItem(1, 80.f) {
    foodShape.setFillColor(Color(156, 170, 53));
}

unique_ptr<FoodItem> Lettuce::create() const {
    return make_unique<Lettuce>();
}
