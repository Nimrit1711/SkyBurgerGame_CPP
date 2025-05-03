#ifndef BOMB_H
#define BOMB_H

#include "Hazards.h"

class Bomb: public Hazards{

    public:
    Bomb();
    Hazards* create() const override;
};

#endif