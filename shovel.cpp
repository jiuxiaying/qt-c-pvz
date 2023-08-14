#include "shovel.h"
#include "plant.h"

shovel::shovel()
{

}
QRectF shovel::boundingRect() const
{
    return QRectF(-40, -40, 80, 80);
}
void shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->drawPixmap(QRect(-40, -40, 80, 80),QPixmap(":/new/prefix1/ShovelBank.png"));
    painter->drawPixmap(QRect(-35,-35,70,70),QPixmap(":/new/prefix1/Shovel.png"));
}
void shovel::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}
void shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QDrag* drag=new QDrag(event->widget());
    //为了确保拖动操作在正确的范围内有效，并且与应用程序的其他部分进行适当的交互。
    QMimeData* data=new QMimeData;
    data->setText("shovel");
    data->setImageData(":/new/prefix1/Shovel.png");
    drag->setMimeData(data);
    drag->setPixmap(QPixmap(":/new/prefix1/Shovel.png"));
    drag->setHotSpot(QPoint(30,30));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}
void shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::ArrowCursor);
}
void shovel::removePlant(QPointF pos)
{
    QList<QGraphicsItem*> items = scene()->items(pos);
    foreach(QGraphicsItem* item,items)
    {
        if(item->type()==plant::Type)
        {
            delete item;
            return;
        }
    }

}
