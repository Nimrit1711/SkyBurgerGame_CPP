#ifndef LETTUCE_H
#define LETTUCE_H

#include "FoodItem.h"

class Lettuce : public FoodItem {
public:
    Lettuce();
    FoodItem* create() const override;
};

#endif 
