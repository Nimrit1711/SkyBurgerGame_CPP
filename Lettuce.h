#ifndef LETTUCE_H
#define LETTUCE_H

#include "FoodItem.h"

class Lettuce : public FoodItem {
public:
    Lettuce();
    unique_ptr<FoodItem> create() const override;
};

#endif 
