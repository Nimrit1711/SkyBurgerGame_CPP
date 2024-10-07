#include "Tomato.h"

Tomato::Tomato() : FoodItem(2, 80.f) {
    foodShape.setFillColor(Color(203, 67, 48));
}

unique_ptr<FoodItem> Tomato::create() const {
    return std::make_unique<Tomato>();
}
