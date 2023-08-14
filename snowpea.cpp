#include "snowpea.h"
#include "peashot.h"
#include "zombie.h"

snowpea::snowpea()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/new/prefix1/SnowPea.gif");
}
void snowpea::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        if (!collidingItems().isEmpty())
        {
            peashot *pe = new peashot(atk, true);
            pe->setX(x() + 30);
            pe->setY(y());
            scene()->addItem(pe);
            return;
        }
    }
}
bool snowpea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y());
}
