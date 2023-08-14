#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QWidget>
#include <QPainter>

class startpage : public QWidget
{
    Q_OBJECT
public:
    QPainter* mpainter_1;
    void paintEvent(QPaintEvent *event);
    explicit startpage(QWidget *parent = nullptr);


signals:

};

#endif // STARTPAGE_H
