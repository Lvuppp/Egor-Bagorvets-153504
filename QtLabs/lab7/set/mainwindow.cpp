#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <sstream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{


    for(int i=0;i<keys.size();i++){
        if(keys[i]==ui->key->text().toInt()){
            return;

        }
    }

    keys.push_back(ui->key->text().toInt());

    testMap.InsertNode(ui->key->text().toInt());
    updateTable();

}

void MainWindow::updateTable(){

    auto model = new QStandardItemModel(keys.size(),2,this);
    ui->tableView->setModel(model);

    auto it=testMap.begin();
    auto endit=testMap.end();

    std::ostringstream oss,ass;
    oss<<&it;
    ass<<&endit;

    ui->label_5->setText(QString::fromStdString(oss.str()));

    ui->label_6->setText(QString::fromStdString(ass.str()));

    for(int i = 0; i < keys.size(); i++){
        model->setData( model->index(i,0),keys[i]);
        model->setData( model->index(i,1),testMap[keys[i]]);

    }

    model->setHeaderData(0,Qt::Horizontal, "Ключ");
    model->setHeaderData(1,Qt::Horizontal, "Значение");

}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->removeKey->text() == "")
        return;

        testMap.Remove(ui->removeKey->text().toInt());

    for(int i =0; i<keys.size();i++){
        if(keys[i]==ui->removeKey->text().toInt()){
            keys.erase(keys.cbegin()+i);
            break;
        }
    }
    updateTable();
}


void MainWindow::on_pushButton_3_clicked()
{
    QString tmp;
    auto it = testMap.begin();
    for(int i =0; it!=testMap.end();++it,i++){
        tmp+=QString::number((*it))+" ";
    }
    ui->label_8->setText(tmp);
}


void MainWindow::on_pushButton_4_clicked()
{
    if(ui->findKey->text() == "")
        return;
    bool flag = false;

    for(int i = 0; i < keys.size(); i++){
        if(ui->findKey->text().toInt() == keys[i])
            flag = true;
    }
    if(!flag){
        ui->label_10->setText("Key doesnt exist");
        return ;
    }
    ui->label_10->setText(QString::number(testMap[ui->findKey->text().toInt()]));
}


void MainWindow::on_pushButton_5_clicked()
{
    if(ui->setKey->text() == "")
        return;

    testMap[ui->setKey->text().toInt()]=ui->setValue->text().toInt();
    updateTable();
}

