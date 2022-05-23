#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include<QFile>
#include<QFileDialog>
#include<QStandardItemModel>
#include<QAbstractTableModel>
#include"QMessageBox"
#include<QTableView>
#include"list.h"
#include"emploee.h"

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
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_13_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

private:
    Ui::MainWindow *ui;
    List list;
    QString filePath = "C:/Users/User/Documents/lab3/test1_1.txt";
    QString dataStatement = "ADD";

    void readFile();
    void saveFile();
    void updateTable();
    void updateEmployeeTable(const List &Employees, QTableView *table);
    void closeFrames();
};
#endif // MAINWINDOW_H
