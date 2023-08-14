#ifndef PLANT_H
#define PLANT_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPainter>
#include <QMovie>
#include <QPainter>

class plant : public QGraphicsItem
{
public:
    enum { Type = UserType + 1};
    int hp;
    int state;
    int atk;
    int counter;
    int time;
    QMovie* mQMovie;
    int type()const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0)override;
    void setMovie(QString path);
    QRectF boundingRect()const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape)const override;
    plant();
    ~plant();
};

#endif // PLANT_H
