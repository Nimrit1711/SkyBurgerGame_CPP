#ifndef BANANAPEEL_H
#define BANANAPEEL_H

#include "Hazards.h"

class BananaPeel: public Hazards{

    public:
    BananaPeel();
    
    Hazards* create() const override;

};

#endif