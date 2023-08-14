#include "repeater.h"

repeater::repeater()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/new/prefix1/Repeater.gif");
}

void repeater::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!collidingItems().isEmpty())
        {
            peashot *pe = new peashot(atk);
            pe->setX(x() + 32);
            pe->setY(y());
            scene()->addItem(pe);
            pe = new peashot(atk);
            pe->setX(x() + 64);
            pe->setY(y());
            scene()->addItem(pe);
            return;
        }
    }
}

bool repeater::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y());
}
