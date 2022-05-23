#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_2->setValidator(new QRegularExpressionValidator(QRegularExpression("[0-9]{8}"),NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTable(){
    ui->label_10->clear();

    auto model = new QStandardItemModel(dataContainer.size(),2,this);
    ui->tableView->setModel(model);

    auto model_2 = new QStandardItemModel(dataContainer_2.size(),2,this);

    ui->tableView_2->setModel(model_2);

    for(int i = 0; i < dataContainer.size(); i++){
        model->setData( model->index(i,0),dataContainer[i].first);
        model->setData( model->index(i,1),dataContainer[i].second);
        model_2->setData( model_2->index(i,0),dataContainer_2[i].first);
        model_2->setData( model_2->index(i,1),dataContainer_2[i].second);
    }

    model->setHeaderData(0,Qt::Horizontal, "Passport");
    model->setHeaderData(1,Qt::Horizontal, "FIO");
    model_2->setHeaderData(0,Qt::Horizontal, "Passport");
    model_2->setHeaderData(1,Qt::Horizontal, "FIO");

    int number=0;
    thisTree.getPregnant(thisTree.getNode(),number);
    ui->label_10->setText(QString::number(number));

}
void MainWindow::updateContainers(){

    dataContainer.clear();
    dataContainer_2.clear();

    thisTree.preorderTraversal(thisTree.getNode(),dataContainer);
    thisTree.postorderTraversal(thisTree.getNode(),dataContainer_2);
}

void MainWindow::on_pushButton_clicked()
{
    QPair<int, QString> temp(ui->lineEdit_2->text().toInt(), ui->lineEdit->text());
    thisTree.insert(temp);

    updateContainers();

    updateTable();
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();

}


void MainWindow::on_pushButton_2_clicked()
{
    QString tempStr;

    bool exist=false;

    for(int i=0;i<dataContainer.size();i++){
        if(dataContainer[i].first==ui->lineEdit_3->text().toInt()){
            exist=true;
            tempStr=dataContainer[i].second;

            break;
        }
    }

    if(!exist){

        QMessageBox msgBox;
        msgBox.setText("Key not found!");
        msgBox.exec();
        return;
    }

    QPair<int,QString> tempPair(ui->lineEdit_3->text().toInt(), tempStr);

    thisTree.remove(tempPair);
    updateContainers();
    updateTable();

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label_8->clear();
    QString tempStr;

    bool exist=false;
    for(int i=0;i<dataContainer.size();i++){
        if(dataContainer[i].first==ui->lineEdit_3->text().toInt()){
            exist=true;
            tempStr=dataContainer[i].second;
            break;
        }
    }
    if(!exist){

        QMessageBox msgBox;
        msgBox.setText("Key not found!");
        msgBox.exec();
        return;
    }

    QPair<int,QString> tempPair(ui->lineEdit_3->text().toInt(), tempStr);
    ui->label_8->setText(thisTree.search(tempPair)->data.second);

}

