#include "Bomb.h"

Bomb::Bomb() : Hazards("Bomb.png", 100.f) {}

Hazards* Bomb:: create() const{
    return new Bomb();
}