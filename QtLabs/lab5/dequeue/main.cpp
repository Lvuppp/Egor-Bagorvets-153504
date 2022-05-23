#include "mainwindow.h"
#include"dequeue.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    dequeue<int> d;
    d.push_back(5);
    d.push_back(5);
    d.push_back(5);
    d.push_back(5);
    d.push_back(5);
    d.print();
    for (auto i = 0;i < d.size(); i++){
        d.pop_front();
        d.print();
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();


}
