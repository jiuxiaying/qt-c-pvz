#ifndef CONEZOMBIE_H
#define CONEZOMBIE_H

#include "zombie.h"
#include "plant.h"

class ConeZombie : public zombie
{
public:
    ConeZombie();
    void advance(int phase) override;
};

#endif // CONEZOMBIE_H
