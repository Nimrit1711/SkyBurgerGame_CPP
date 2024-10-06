#include "Tomato.h"

Tomato::Tomato() : FoodItem("Tomato.png", 2, 80.f) {}

unique_ptr<FoodItem> Tomato::create() const {
    return std::make_unique<Tomato>();
}
