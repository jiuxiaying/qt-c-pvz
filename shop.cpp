#include "shop.h"

shop::shop()
{
    sunnum = 200;
    counter = 0;
    time = int(7.0 * 1000 / 33);
    card *car = nullptr;
    for (int i = 0; i < card::name.size(); ++i)
    {
        car = new card(card::name[i]);
        car->setParentItem(this);
        car->setPos(-157 + 65 * i, -2);
    }
}

QRectF shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}

void shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/new/prefix1/Shop.png"));
    QFont font;
    font.setPointSizeF(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sunnum));
}

void shop::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new sun);
    }
}

void shop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
        if (item->type() == plant::Type)
            return;
    sunnum -= card::cost[card::map[s]];
    plant *pl = nullptr;
    switch (card::map[s])
    {
    case 0:
        pl = new sunflower; break;
    case 1:
        pl = new pea; break;
    case 2:
        pl = new cherry; break;
    case 3:
        pl = new wallnut; break;
    case 4:
        pl = new snowpea; break;
    case 5:
        pl = new potato; break;
    case 6:
        pl = new repeater; break;
    }
    pl->setPos(pos);
    scene()->addItem(pl);
    QList<QGraphicsItem *> child = childItems();
    foreach (QGraphicsItem *item, child)
    {
        card *car = qgraphicsitem_cast<card *>(item);
        if (car->text == s)
            car->counter = 0;
    }
    counter = 0;
}

