#include "Bomb.h"

Bomb::Bomb() : Hazards("assets/images/Bomb.png", 100.f) {}

Hazards* Bomb:: create() const{
    return new Bomb();
}