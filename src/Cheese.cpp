#include "Cheese.h"

Cheese::Cheese() : FoodItem(5, 160.f) {
    foodShape.setFillColor(Color(243, 181, 53));
}
FoodItem* Cheese::create() const {
    return new Cheese();
}