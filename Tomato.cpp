#include "Tomato.h"

Tomato::Tomato() : FoodItem(2, 80.f) {
    foodShape.setFillColor(Color(203, 67, 48));
}

FoodItem* Tomato::create() const {
    return new Tomato();
}
