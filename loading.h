#ifndef LOADING_H
#define LOADING_H

#include <QWidget>
#include <QTimer>
#include <QPainter>

class loading : public QWidget
{
    Q_OBJECT
public:
    QTimer* mqtimer;
    QPainter* mpainter_1;
    void paintEvent(QPaintEvent *event);
    explicit loading(QWidget *parent = nullptr);

signals:

};

#endif // LOADING_H
