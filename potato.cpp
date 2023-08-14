#include "potato.h"
#include "zombie.h"


potato::potato()
{
    atk = 1800;
    hp = 300;
    time = int(15.0 * 1000 / 33);
    setMovie(":/new/prefix1/PotatoMine1.gif");
}

QRectF potato::boundingRect() const
{
    return state == 2 ? QRectF(-75, -75, 150, 150) : plant::boundingRect();
}

void potato::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
        delete this;
    else if (state == 0 && ++counter >= time)
    {
        state = 1;
        counter = 0;
        time = int(1.0 * 1000 / 33);
        setMovie(":/new/prefix1/PotatoMine.gif");
    }
    else if (state == 1 && ++counter >= time)
    {
        counter = 0;
        QList<QGraphicsItem *> items = collidingItems();
        if (!items.isEmpty())
        {
            state = 2;
            setMovie(":/new/prefix1/PotatoMineBomb.gif");
            foreach (QGraphicsItem *item, items)
            {
                zombie *zom = qgraphicsitem_cast<zombie *>(item);
                zom->hp -= atk;
                if (zom->hp <= 0)
                    delete zom;
            }
        }
    }
    else if (state == 2 && mQMovie->currentFrameNumber() == mQMovie->frameCount() - 1)
        delete this;
}

bool potato::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 50;
}
