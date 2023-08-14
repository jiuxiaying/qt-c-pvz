#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H

#include "zombie.h"
#include "plant.h"

class FootballZombie : public zombie
{
public:
    FootballZombie();
    void advance(int phase) override;
};

#endif // FOOTBALLZOMBIE_H
