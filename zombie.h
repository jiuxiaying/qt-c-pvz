#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPainter>
#include <QMovie>

class zombie : public QGraphicsItem
{
public:
    enum { Type = UserType + 2};
    int hp;
    int state;
    int atk;
    qreal speed;
    QMovie* mQMovie;
    QMovie* mhead;
    zombie();
    ~zombie();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget )override;
    QRectF boundingRect()const override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const override;
    void setMovie(QString path);
    void setHead(QString path);
    int type()const override;

};

#endif // ZOMBIE_H
