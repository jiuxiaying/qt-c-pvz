#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "loading.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(900,600);
    this->setWindowTitle("PlantsVsZombies Plus Version 95 to rebuild project");
    this->setWindowIcon(QIcon(":/new/prefix1/WallNut.png")); // 设置窗口图标
    mpainter_1 = new QPainter(this); // 创建 QPainter 对象
    mqtimer = new QTimer(this); // 创建 QTimer 对象
    mqtimer->setInterval(4000); // 设置定时器时间间隔为 4000 毫秒
    mqtimer->start(); // 启动定时器
    connect(mqtimer, &QTimer::timeout, [this]() {
        mqtimer->stop(); // 定时器触发后停止
        loading* load = new loading; // 创建 loading 对象
        load->show(); // 显示 loading 窗口
        this->hide(); // 隐藏当前主窗口
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{
    mpainter_1->begin(this); // 开始绘制
    QImage img(":/new/prefix1/init.png"); // 加载图片资源
    mpainter_1->drawImage(QRect(0, 0, 900, 600), img); // 在主窗口绘制图片
    mpainter_1->end(); // 结束绘制
}


