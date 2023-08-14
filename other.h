#ifndef OTHER_H
#define OTHER_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class other : public QGraphicsItem
{
public:
    enum{Type=UserType+3};
    other();
    int type() const override;
};

#endif // OTHER_H
