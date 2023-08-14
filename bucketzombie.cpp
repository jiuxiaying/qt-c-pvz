#include "bucketzombie.h"

BucketZombie::BucketZombie()
{
    hp = 1370;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie(":/new/prefix1/BucketZombieWalk.gif");
}

void BucketZombie::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (hp <= 0)
    {
        if (state < 2)
        {
            state = 2;
            setMovie(":/new/prefix1/ZombieDie.gif");
            setHead(":/new/prefix1/ZombieHead.gif");
        }
        else if (mQMovie->currentFrameNumber() == mQMovie->frameCount() - 1)
            delete this;
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        plant *pl = qgraphicsitem_cast<plant *>(items[0]);
        pl->hp -= atk;
        if (state != 1)
        {
            state = 1;
            setMovie(":/new/prefix1/BucketZombieAttack.gif");
        }
        return;
    }
    if (state)
    {
        state = 0;
        setMovie(":/new/prefix1/BucketZombieWalk.gif");
    }
    setX(x() - speed);
}
