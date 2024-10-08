#ifndef PATTY_H
#define PATTY_H

#include "FoodItem.h"

class Patty : public FoodItem {
public:
    Patty();
    FoodItem* create() const override;
};

#endif 
