#ifndef ONION_H
#define ONION_H

#include "FoodItem.h"

class Onion : public FoodItem {
public:
    Onion();
    FoodItem* create() const override;
};

#endif 