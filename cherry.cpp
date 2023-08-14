#include "cherry.h"
#include "zombie.h"


cherry::cherry()
{
    atk = 1800;
    hp = 800;
    setMovie(":/new/prefix1/CherryBomb.gif");
}
QRectF cherry::boundingRect() const
{
    return state ? QRectF(-150, -150, 300, 300) : plant::boundingRect();
}
void cherry::advance(int phase)
{
    if(!phase)
        return;
    update();
    if(hp<=0)
        delete this;
    else if (state == 0 && mQMovie->currentFrameNumber() == mQMovie->frameCount() - 1)
    {
        state = 1;
        setMovie(":/new/prefix1/Boom.gif");
        QList<QGraphicsItem *> items = collidingItems();
        foreach (QGraphicsItem *item, items)
        {
            zombie *zom = qgraphicsitem_cast<zombie*>(item);
            zom->hp -= atk;
            if (zom->hp <= 0)
            {
                zom->state = 3;
                zom->setMovie(":/new/prefix1/Burn.gif");
            }
        }
    }
    else if (state == 1 && mQMovie->currentFrameNumber() == mQMovie->frameCount() - 1)
        delete this;
}
bool cherry::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    return other->type() == zombie::Type && QLineF(pos(), other->pos()).length() < 160;
}
