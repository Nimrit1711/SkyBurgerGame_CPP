#ifndef CHEESE_H
#define CHEESE_H

#include "FoodItem.h"

class Cheese : public FoodItem {
public:
    Cheese();
    unique_ptr<FoodItem> create() const override;
};

#endif 