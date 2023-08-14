#include "peashot.h"
#include "zombie.h"

peashot::peashot(int attack, bool flag)
{
    atk = attack; // 设置豌豆射手的攻击力
    snow = flag; // 设置是否带有冰冻效果的标志
    speed = 360.0 * 33 / 1000; // 设置豌豆射手的速度（每秒360像素）
}

QRectF peashot::boundingRect() const
{
    // 设置豌豆射手的边界矩形
    return QRectF(-12, -28, 24, 24); // 矩形的左上角坐标为(-12, -28)，宽度为24，高度为24
}

bool peashot::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    Q_UNUSED(mode)
    // 当豌豆射手与僵尸碰撞时，返回true
    return other->type() == zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 15;
}

void peashot::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    // 绘制豌豆射手的图片，根据是否带有冰冻效果，选择不同的图片
    painter->drawPixmap(QRect(-12, -28, 24, 24), QPixmap(snow ? ":/new/prefix1/PeaSnow.png" : ":/new/prefix1/Pea.png"));
}

void peashot::advance(int phase)
{
    if (!phase)
        return;
    update(); // 更新豌豆射手的绘制
    // 检测豌豆射手与其他物体是否发生碰撞
    QList<QGraphicsItem *> items = collidingItems();
    if (!items.isEmpty())
    {
        // 当豌豆射手与僵尸碰撞时
        zombie *zom = qgraphicsitem_cast<zombie *>(items[qrand() % items.size()]);
        zom->hp -= atk; // 减少僵尸的生命值，受到豌豆射手的攻击

        // 如果豌豆射手带有冰冻效果，且僵尸的速度大于5.0 * 33 / 1000 / 2（初始速度的一半）
        if (snow && zom->speed > 5.0 * 33 / 1000 / 2)
            zom->speed /= 3; // 将僵尸的速度减少为原来的1/3

        delete this; // 删除豌豆射手对象
        return;
    }
    setX(x() + speed); // 更新豌豆射手的位置，让其向前移动
    // 如果豌豆射手的位置超过屏幕边界（x > 1069），则删除豌豆射手对象
    if (x() > 1069)
        delete this;
}
