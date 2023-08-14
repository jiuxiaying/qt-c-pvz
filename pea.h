#ifndef PEA_H
#define PEA_H

#include "plant.h"

class pea : public plant
{
public:
    pea();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
};

#endif // PEA_H
