#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::updateTables(){
    ui->listWidget->clear();
    ui->listWidget_2->clear();
    ui->listWidget_3->clear();


    for(int i = 0; i < keys.size(); i++){
        ui->listWidget->addItem("Key: " + QString::number(keys[i]) + "; Value: " +QString::number(table.search(keys[i])));
        if(keys[i] < 0)
           ui->listWidget_2->addItem("Key: " + QString::number(keys[i]) + "; Value: " +QString::number(table.search(keys[i])));
        else
           ui->listWidget_3->addItem("Key: " + QString::number(keys[i]) + "; Value: " +QString::number(table.search(keys[i])));
    }

}

void MainWindow::on_pushButton_clicked()
{
    QRandomGenerator rand;

    for(int i = 0; i < ui->lineEdit->text().toInt(); i++){
        keys.push_back(rand.bounded(-50,50));
        table.insert(keys[i],rand.bounded(-33000,33000));
    }
    updateTables();
}

