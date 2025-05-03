#include "Sock.h"

Sock::Sock() : Hazards("assets/images/Sock.png", 100.f) {
    hazardSprite.setScale(0.5f, 0.5f); 
}

Hazards* Sock:: create() const{
    return new Sock();
}