#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <node.h>
#include <QPair>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateTable();
    void updateContainers();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Tree<QPair<int,QString>> thisTree;
    vector<QPair<int,QString>> dataContainer,dataContainer_2;

};
#endif // MAINWINDOW_H
