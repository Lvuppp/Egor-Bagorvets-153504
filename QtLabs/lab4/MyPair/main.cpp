#include "mainwindow.h"
#include"pair.h"
#include <QApplication>

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    Pair<Pair<int,int>,Pair<int,int>> a;
    qDebug() << a.first.first;
    return 0;
}
