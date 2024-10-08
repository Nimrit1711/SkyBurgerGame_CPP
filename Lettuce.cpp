#include "Lettuce.h"

Lettuce::Lettuce() : FoodItem(1, 80.f) {
    foodShape.setFillColor(Color(156, 170, 53));
}

FoodItem* Lettuce::create() const {
    return new Lettuce();
}
