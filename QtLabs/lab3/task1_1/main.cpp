#include "mainwindow.h"

#include <QApplication>
#include"list.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    std::vector<int> f;
    f.push_back(2);
    f.resize(3);

    return a.exec();
}
