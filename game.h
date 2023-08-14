#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QSound>


class game : public QWidget
{
    Q_OBJECT
public:
    QSound* mQSound;
    QTimer* mQTimer;
    QGraphicsView* view;
    QGraphicsScene* scene;
    explicit game(QWidget *parent = nullptr);
    ~game() override;
    void addZombie();
    void check();

signals:

};

#endif // GAME_H
