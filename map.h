#ifndef MAP_H
#define MAP_H

#include "other.h"
#include "plant.h"
#include "shop.h"
#include "shovel.h"
#include <QGraphicsSceneDragDropEvent>

class Map : public other
{
public:
    Map();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void dragEnterEvent(QGraphicsSceneDragDropEvent *event)override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *event)override;
    void dropEvent(QGraphicsSceneDragDropEvent *event)override;
private:
    bool dragover;
};

#endif // MAP_H
