#include "map.h"
#include "shop.h"
#include "shovel.h"

Map::Map()
{
    dragover=false;
    setAcceptDrops(true);
}

QRectF Map::boundingRect() const
{
    return QRectF(-369, -235, 738, 470);
}
void Map::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter)
    Q_UNUSED(option)
    Q_UNUSED(widget)

}
void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if(event->mimeData()->hasText())
    {
        dragover=false;
        setAcceptDrops(true);
    }
    else
    {
        setAcceptDrops(false);
    }

}
void Map::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    dragover=false;
}
void Map::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragover=true;
    if(event->mimeData()->hasText())
    {
        QString s=event->mimeData()->text().toUtf8();
        QPointF pos=mapToScene(event->pos());
        //QPointF pos=event->pos();
        pos.setX((int(pos.x())-245)/85 * 85 +290);
        pos.setY((int(pos.y())-80)/95 * 95 +120);
        if(s=="shovel")
        {
            shovel* sho = qgraphicsitem_cast<shovel*>(scene()->items(QPointF(830, 15))[0]);
            sho->removePlant(pos);
        }
        else
        {
            shop* sh =qgraphicsitem_cast<shop *>(scene()->items(QPointF(300, 15))[0]);
            sh->addPlant(s, pos);
        }

    }
    update();


}
