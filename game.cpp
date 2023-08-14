#include "game.h"
#include "shop.h"
#include "map.h"
#include "shovel.h"
#include "basiczombie.h"
#include "conezombie.h"
#include "bucketzombie.h"
#include "screenzombie.h"
#include "footballzombie.h"
#include "zombie.h"
#include "mower.h"
#include <QPixmap>

game::game(QWidget *parent)
    : QWidget{parent}
{
    mQSound=new QSound(":/new/prefix2/Grazy.wav");
    mQSound->play();
    mQTimer=new QTimer(this);

    scene=new QGraphicsScene(this);
    scene->setSceneRect(150,0,900,600);//控制img需要截取部分
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    //视图显示的坐标，注意所有的坐标都是基于未被裁剪图片的坐标
    //(290,120,10,10);(1,1)坐标(中心坐标)
    //245,175->330,270->>>>格子85 95
    shop *sh = new shop;
    sh->setPos(520, 45);
    scene->addItem(sh);
    shovel *sho = new shovel;
    sho->setPos(830, 40);
    scene->addItem(sho);
    Map *map = new Map;
    map->setPos(618, 326);
    scene->addItem(map);
    for (int i = 0; i < 5; ++i)
    {
        Mower *mower = new Mower;
        mower->setPos(215, 120 + 95 * i);
        scene->addItem(mower);
    }

    // 创建视图对象并设置属性
    view = new QGraphicsView(scene, this);
    view->resize(900, 600);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(QPixmap(":/new/prefix1/Background.jpg")); // 设置背景图片
    view->setCacheMode(QGraphicsView::CacheBackground);
    view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);

    // 连接计时器的timeout信号到场景的advance槽，实现场景中物体的动画效果
    connect(mQTimer, &QTimer::timeout, scene, &QGraphicsScene::advance);
    // 连接计时器的timeout信号到游戏的addZombie槽，添加僵尸
    connect(mQTimer, &QTimer::timeout, this, &game::addZombie);
    // 连接计时器的timeout信号到游戏的check槽，检查游戏是否结束
    connect(mQTimer, &QTimer::timeout, this, &game::check);
    mQTimer->start(33); // 启动计时器，每33毫秒触发一次timeout信号，驱动游戏动画效果

    view->show(); // 显示视图
}
game::~game()
{
    delete mQSound;
    delete mQTimer;
    delete view;
    delete scene;
}
void game::addZombie()
{
    //10秒（10000m秒）一只僵尸，33毫秒，
    static int low = 4;
    static int high = 8;
    static int maxtime = 20 * 1000 / 33;
    static int time = maxtime / 2;
    static int counter = 0;
    if (++counter >= time)
    {
        if (++low > high)
        {
            maxtime /= 1.3;
            high *= 2;
        }
        counter = 0;
        time = qrand() % (2 * maxtime / 3) + maxtime / 3;
        int type = qrand() % 100;
        int i = qrand() % 5;
        zombie *zom;
        if (type < 40)
            zom = new basiczombie;
        else if (type < 70)
            zom = new ConeZombie;
        else if (type < 80)
            zom = new BucketZombie;
        else if (type < 90)
            zom = new ScreenZombie;
        else
            zom = new FootballZombie;
        zom->setPos(1028, 120 + 95 * i);
        scene->addItem(zom);
    }

}
void game::check()
{
    // 检查游戏是否结束，是否有僵尸到达屏幕最左边
    const QList<QGraphicsItem *> items = scene->items();
    foreach (QGraphicsItem *item, items)
    {
        if (item->type() == zombie::Type && item->x() < 150)
        {
            // 如果有僵尸到达屏幕最左边，游戏结束
            scene->addPixmap(QPixmap(":/new/prefix1/ZombiesWon.png"))->setPos(336, 92);
            scene->advance();
            mQTimer->stop(); // 停止计时器，结束游戏
            return;
        }
    }
}
