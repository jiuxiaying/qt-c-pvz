#include "loading.h"
#include <QIcon>
#include <QPushButton>
#include "startpage.h"


loading::loading(QWidget *parent)
    : QWidget{parent}
{
    this->resize(900,600);
    this->setWindowTitle("PlantsVsZombies Plus Version 95 to rebuild project");
    this->setWindowIcon(QIcon(":/new/prefix1/WallNut.png")); // 设置窗口图标
    mpainter_1 = new QPainter; // 创建 QPainter 对象
    QPixmap img(":/new/prefix1/floor.png"); // 加载图片资源
    QPushButton *btn = new QPushButton(this); // 创建 QPushButton 对象
    btn->setGeometry(237, 433, 450, 115); // 设置按钮位置和大小
    btn->setStyleSheet("QPushButton {"
                       "border-image: url(:/new/prefix1/floor.png) center center no-repeat;" // 设置按钮样式，包括背景图片
                       "font-size: 16px;" // 设置字体大小
                       "color: white;" // 设置字体颜色
                       "padding-top: 40px;" // 设置文字距离按钮顶部的距离
                       "}"
                       "QPushButton:hover {" // 鼠标悬停样式
                       "color: yellow;" // 设置鼠标悬停时的字体颜色
                       "}"
                       "QPushButton:pressed {" // 按钮按下样式
                       "color: purple;" // 设置按钮按下时的字体颜色
                       "}");
    btn->setText(QString("start")); // 设置按钮文本
        connect(btn, &QPushButton::clicked, [this]() {
            startpage *mstartpage = new startpage; // 创建开始页面对象
            mstartpage->show(); // 显示开始页面
            this->hide(); // 隐藏当前窗口
        });

}
void loading::paintEvent(QPaintEvent *event)
{
    mpainter_1->begin(this); // 开始绘制
    QImage img(":/new/prefix1/StartScreen.jpg"); // 加载图片资源
    mpainter_1->drawImage(QRect(0, 0, 900, 600), img); // 在主窗口绘制图片
    mpainter_1->drawImage(QRect(123, 20, 555, 115), QImage(":/new/prefix1/LogoWord.jpg"), QRect(0, 0, 555, 115)); // 绘制图片，指定位置和大小
    mpainter_1->end(); // 结束绘制
}

