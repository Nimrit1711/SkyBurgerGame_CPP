#ifndef SOCK_H
#define SOCK_H

#include "Hazards.h"

class Sock: public Hazards{

    public:
    Sock();
    Hazards* create() const override;
};

#endif