#include "pea.h"
#include "zombie.h"
#include "peashot.h"

pea::pea()
{
    hp = 200; // 设置豌豆射手的生命值为200
    atk = 25; // 设置豌豆射手的攻击力为25
    time = int(1.4 * 1000 / 33); // 计算豌豆射手攻击间隔的帧数，1.4秒对应的帧数（33毫秒为帧间隔）
    setMovie(":/new/prefix1/Peashooter.gif"); // 设置豌豆射手的动画
}

void pea::advance(int phase)
{
    if (!phase)
        return;
    update(); // 更新豌豆射手的绘制
    if (hp <= 0)
        delete this; // 如果豌豆射手的生命值小于等于0，删除豌豆射手对象
    else if (++counter >= time) // 每过一个攻击间隔的帧数
    {
        counter = 0; // 重置计数器
        // 如果豌豆射手与其他图形项发生碰撞（即僵尸在豌豆射手的攻击范围内）
        if (!collidingItems().isEmpty())
        {
            peashot *newshot = new peashot(atk); // 创建一个豌豆射手的子弹对象
            newshot->setX(x() + 30); // 设置子弹的初始位置在豌豆射手的右侧30像素处
            newshot->setY(y()); // 设置子弹的高度与豌豆射手相同
            scene()->addItem(newshot); // 将子弹添加到场景中
            return; // 返回，不进行移动
        }
    }
}

bool pea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    // 当豌豆射手与僵尸在同一纵坐标上（y相等）发生碰撞时，返回true
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y());
}
