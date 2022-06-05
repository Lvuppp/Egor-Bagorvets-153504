#include "mainwindow.h"
#include "BitSet.h"
#include<bitset>
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    BitSet<7> b = 123;
    qDebug() << QString::fromStdString(b.toString());
    b.flip();
    qDebug() << QString::fromStdString(b.toString());
    b.reset();
    qDebug() << QString::fromStdString(b.toString());
    return a.exec();
}
