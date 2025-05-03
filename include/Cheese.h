#ifndef CHEESE_H
#define CHEESE_H

#include "FoodItem.h"

class Cheese : public FoodItem {
public:
    Cheese();
    FoodItem* create() const override;
};

#endif 