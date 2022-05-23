#include "mainwindow.h"
#include <QApplication>
#include <memory>
#include"uniq_ptr.h"
#include"shared_ptr.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    unique_ptr<int> ptr(new int (5));
    unique_ptr<int> gg(std::move(ptr));
    w.show();
    return a.exec();

}
