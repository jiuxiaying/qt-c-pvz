#include "Mainwindow.h"
#include <QApplication>
#include <loading.h>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    game w;
//    w.show();
    return a.exec();
}
