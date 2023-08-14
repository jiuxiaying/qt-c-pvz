#include "startpage.h"
#include <QIcon>
#include <QPushButton>
#include "game.h"

startpage::startpage(QWidget *parent)
    : QWidget{parent}
{
    this->resize(900,600);
    this->setWindowTitle("PlantsVsZombies Plus Version 95 to rebuild project");
    this->setWindowIcon(QIcon(":/new/prefix1/WallNut.png"));
    mpainter_1=new QPainter(this);
    QPushButton* btn_1=new QPushButton(this);
    QPushButton* btn_2=new QPushButton(this);
    QPushButton* btn_3=new QPushButton(this);
    QPushButton* btn_4=new QPushButton(this);
    btn_1->setGeometry(450,60,340,120);
    btn_1->setStyleSheet("QPushButton{"
                         "border:none;" // 设置无边框
                         "padding:0px;" // 设置无内边距
                         "background:transparent;" // 设置背景透明
                         "border-image:url(:/new/prefix1/mx1.png);" // 设置按钮样式，包括背景图片
                         "}"
                         "QPushButton:hover{"
                         "border-image:url(:/new/prefix1/mx.png);" // 鼠标悬停样式
                         "}"
                         );
    btn_2->setGeometry(450,150,320,130);
    btn_2->setStyleSheet("QPushButton{"
                         "border:none;"
                         "padding:0px;"
                         "background:transparent;"
                         "border-image:url(:/new/prefix1/play1.png);"
                         "}"
                         "QPushButton:hover{"
                         "border-image:url(:/new/prefix1/play.png);"
                         "}"
                         );
    btn_3->setGeometry(460,230,290,130);
    btn_3->setStyleSheet("QPushButton{"
                         "border:none;"
                         "padding:0px;"
                         "background:transparent;"
                         "border-image:url(:/new/prefix1/yizi1.png);"
                         "}"
                         "QPushButton:hover{"
                         "border-image:url(:/new/prefix1/yizi.png);"
                         "}"
                         );
    btn_4->setGeometry(460,320,280,120);
    btn_4->setStyleSheet("QPushButton{"
                         "border:none;"
                         "padding:0px;"
                         "background:transparent;"
                         "border-image:url(:/new/prefix1/mini1.png);"
                         "}"
                         "QPushButton:hover{"
                         "border-image:url(:/new/prefix1/mini.png);"
                         "}"
                         );
     // 连接按钮点击事件，启动游戏窗口，并隐藏当前窗口
    connect(btn_1,&QPushButton::clicked,[this](){
        game* ga=new game;
        ga->show();
        this->hide();
    });


}
void startpage::paintEvent(QPaintEvent *event)
{
    mpainter_1->begin(this); // 开始绘制
    QImage img(":/new/prefix1/Surface.png"); // 加载图片资源
    mpainter_1->drawImage(QRect(0, 0, 900, 600), img); // 在主窗口绘制图片
    mpainter_1->end(); // 结束绘制
}
