#include "Cheese.h"

Cheese::Cheese() : FoodItem(5, 100.f) {
    foodShape.setFillColor(Color(243, 181, 53));
}
unique_ptr<FoodItem> Cheese::create() const {
    return make_unique<Cheese>();
}