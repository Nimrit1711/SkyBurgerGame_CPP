#ifndef TOMATO_H
#define TOMATO_H

#include "FoodItem.h"

class Tomato : public FoodItem {
public:
    Tomato();
    FoodItem* create() const override;
};

#endif 
