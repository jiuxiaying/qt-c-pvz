#ifndef BUCKETZOMBIE_H
#define BUCKETZOMBIE_H

#include "zombie.h"
#include "plant.h"

class BucketZombie : public zombie
{
public:
    BucketZombie();
    void advance(int phase) override;
};

#endif // BUCKETZOMBIE_H
