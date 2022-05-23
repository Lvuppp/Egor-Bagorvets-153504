#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QRandomGenerator>
#include <QMainWindow>
#include<QStandardItemModel>

#include"queue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    void updateTable();

    Ui::MainWindow *ui;
    queue<int> numQueue;
};
#endif // MAINWINDOW_H
