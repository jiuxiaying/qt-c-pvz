#ifndef BASICZOMBIE_H
#define BASICZOMBIE_H

#include "zombie.h"
#include "plant.h"

class basiczombie : public zombie
{
public:
    basiczombie();
    void advance(int phase) override;
};

#endif // BASICZOMBIE_H
