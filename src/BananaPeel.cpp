#include "BananaPeel.h"

BananaPeel::BananaPeel() : Hazards("assets/images/bananaPeel.png", 100.f) {
    hazardSprite.setScale(0.5f, 0.5f);
}

Hazards* BananaPeel:: create() const{
    return new BananaPeel();
}