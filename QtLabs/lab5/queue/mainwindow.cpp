#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QRandomGenerator rand;
    for(auto i = 0; i < 20; i++){
        numQueue.push(rand.bounded(-100,100));
    }

    updateTable();
}

void MainWindow::updateTable(){
    auto model = new QStandardItemModel(numQueue.size() ,1,this);

        ui->tableView->setModel(model);

        for(int i = 0; i < model->rowCount(); i++){
            model->setData( model->index(i,0), numQueue.front());
            numQueue.push(numQueue.front());
            numQueue.pop();
        }

        model->setHeaderData(0,Qt::Horizontal, "Значение");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int tmp = 1001, index = 0;
    for(auto i = 0; i < numQueue.size(); i++){
        if(tmp > numQueue.front()){
            tmp = numQueue.front();
            index = i;
        }

        numQueue.push(numQueue.front());
        numQueue.pop();
    }
    numQueue.push(tmp);

    for(auto i = 0; i < numQueue.size(); i++){
        if(i == index){
            continue;
        }
        numQueue.push(numQueue.front());
        numQueue.pop();
    }

    updateTable();
}

