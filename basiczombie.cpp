#include "basiczombie.h"


basiczombie::basiczombie()
{
    hp = 270; // 设置基础僵尸的生命值为270
    atk = 100 * 33 / 1000; // 设置基础僵尸的攻击力为100（每秒攻击100点）
    speed = 5.0 * 33 / 1000; // 设置基础僵尸的速度为5.0像素/秒（33毫秒为帧间隔）
    setMovie(":/new/prefix1/ZombieWalk1.gif"); // 设置基础僵尸的行走动画
}

void basiczombie::advance(int phase)
{
    if (!phase)
        return;
    update(); // 更新基础僵尸的绘制
    if (hp <= 0) // 如果基础僵尸的生命值小于等于0，表示已经被击败
    {
        if (state < 2) // 如果基础僵尸的状态小于2，表示处于死亡状态
        {
            state = 2; // 将状态设置为2（死亡）
            setMovie(":/new/prefix1/ZombieDie.gif"); // 设置基础僵尸的死亡动画
            setHead(":/new/prefix1/ZombieHead.gif"); // 设置基础僵尸的头部掉落动画
        }
        else if (mQMovie->currentFrameNumber() == mQMovie->frameCount() - 1)
            delete this; // 如果基础僵尸的死亡动画播放完毕，删除基础僵尸对象
        return;
    }
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty()) // 如果基础僵尸与其他图形项发生碰撞
    {
        plant *pl = qgraphicsitem_cast<plant *>(items[0]);
        pl->hp -= atk; // 减少植物的生命值，受到基础僵尸的攻击
        if (state != 1) // 如果基础僵尸的状态不为1（攻击状态）
        {
            state = 1; // 将状态设置为1（攻击）
            setMovie(":/new/prefix1/ZombieAttack.gif"); // 设置基础僵尸的攻击动画
        }
        return;
    }
    if (state) // 如果基础僵尸的状态不为0（行走状态）
    {
        state = 0; // 将状态设置为0（行走）
        setMovie(":/new/prefix1/ZombieWalk1.gif"); // 设置基础僵尸的行走动画
    }
    setX(x() - speed); // 更新基础僵尸的位置，让其向左移动
}
