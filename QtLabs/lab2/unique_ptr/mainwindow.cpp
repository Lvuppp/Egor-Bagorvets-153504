#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStandardItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::updateShareTable(){
    auto model = new QStandardItemModel(shareList.length() ,4,this);

    ui->tableView_2->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        std::ostringstream oss;
        oss<<shareList[i].get();

        QString ptrValue;

        if(shareList[i].get() != nullptr)
             ptrValue= QString::number(*shareList[i].get());
        else
            ptrValue = "nullptr";

        model->setData( model->index(i,0), ptrValue);
        model->setData( model->index(i,1), shareList[i].shareCount());
        model->setData( model->index(i,2), shareList[i].uniq());
        model->setData( model->index(i,3), QString::fromStdString(oss.str()));
    }

    model->setHeaderData(0,Qt::Horizontal, "Значение");
    model->setHeaderData(1,Qt::Horizontal, "Share Count");
    model->setHeaderData(2,Qt::Horizontal, "Uniq");
    model->setHeaderData(3,Qt::Horizontal, "Get");

    ui->comboBox_3->clear();
    ui->comboBox_4->clear();
    ui->comboBox_5->clear();
    ui->comboBox_6->clear();
    ui->comboBox_12->clear();
    ui->comboBox_13->clear();


    for(int i = 0; i < model->rowCount();i++){
        ui->comboBox_3->addItem(QString::number(i+1));
        ui->comboBox_4->addItem(QString::number(i+1));
        ui->comboBox_5->addItem(QString::number(i+1));
        ui->comboBox_6->addItem(QString::number(i+1));
        ui->comboBox_12->addItem(QString::number(i+1));
        ui->comboBox_13->addItem(QString::number(i+1));
    }

}


/*share table*/

void MainWindow::on_pushButton_5_clicked()
{
    if(shareList.length() < 20) {
        shareList.push_back(SharePtr<int>(new int (rand())));
        updateShareTable();
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    if(ui->comboBox_5->currentIndex() >= 0){
        shareList.push_back(SharePtr<int>(shareList[ui->comboBox_5->currentIndex()]));
        updateShareTable();
    }
}


void MainWindow::on_pushButton_6_clicked()
{
    if(ui->comboBox_6->currentIndex() >= 0){
        shareList[ui->comboBox_6->currentIndex()].reset((new int (rand())));
        updateShareTable();
        updateWeakTable();
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    if(ui->comboBox_5->currentIndex() != ui->comboBox_4->currentIndex() && ui->comboBox_4->currentIndex() >= 0 && ui->comboBox_5->currentIndex() >=0){
        shareList[ui->comboBox_4->currentIndex()].swap(shareList[ui->comboBox_5->currentIndex()]);
        updateShareTable();
    }
}


void MainWindow::on_pushButton_14_clicked()
{
    if(ui->comboBox_12->currentIndex() >= 0){
        shareList[ui->comboBox_12->currentIndex()].reset();
        updateShareTable();
        updateWeakTable();
    }
}


void MainWindow::on_pushButton_15_clicked()
{
    if(ui->comboBox_13->currentIndex() >= 0 && weakList.length() < 20){
       weakList.push_back(WeakPtr<int>(shareList[ui->comboBox_13->currentIndex()]));
       updateWeakTable();
    }
}


/*weak table*/


void MainWindow::updateWeakTable(){
    auto model = new QStandardItemModel(weakList.length() ,3,this);

    ui->tableView_3->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){

        model->setData( model->index(i,0), weakList[i].expired());
        model->setData( model->index(i,1), weakList[i].shareCount());
        model->setData( model->index(i,2), weakList[i] .ownerBefore(weakList[0]));
    }

    model->setHeaderData(0,Qt::Horizontal, "Expired");
    model->setHeaderData(1,Qt::Horizontal, "Share Count");
    model->setHeaderData(2,Qt::Horizontal, "Owner before");

    ui->comboBox_8->clear();
    ui->comboBox_8->clear();
    ui->comboBox_9->clear();
    ui->comboBox_10->clear();
    ui->comboBox_11->clear();

    for(int i = 0; i < model->rowCount();i++){
        ui->comboBox_7->addItem(QString::number(i+1));
        ui->comboBox_8->addItem(QString::number(i+1));
        ui->comboBox_9->addItem(QString::number(i+1));
        ui->comboBox_10->addItem(QString::number(i+1));
        ui->comboBox_11->addItem(QString::number(i+1));
    }

}

void MainWindow::on_pushButton_10_clicked()
{
    if(ui->comboBox_7->currentIndex() >= 0){
        weakList.push_back(WeakPtr<int>(weakList[ui->comboBox_7->currentIndex()]));
        updateWeakTable();
    }
}


void MainWindow::on_pushButton_13_clicked()
{
    if(ui->comboBox_11->currentIndex() >= 0 && shareList.length() < 20){
        shareList.push_back(weakList[ui->comboBox_11->currentIndex()].lock());
        updateShareTable();
        updateWeakTable();
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    if(ui->comboBox_8->currentIndex() >= 0){
       weakList[ui->comboBox_8->currentIndex()].reset();
        updateWeakTable();
    }
}


void MainWindow::on_pushButton_12_clicked()
{
    if(ui->comboBox_9->currentIndex() != ui->comboBox_10->currentIndex() && ui->comboBox_10->currentIndex() >= 0 && ui->comboBox_9->currentIndex() >=0){
        weakList[ui->comboBox_10->currentIndex()].swap(weakList[ui->comboBox_9->currentIndex()]);
        updateWeakTable();
    }
}




/*uniq table*/

void MainWindow::updateUniqTable(){
    auto model = new QStandardItemModel(uniqList.size() ,2,this);

    ui->tableView->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        std::ostringstream oss;
        oss<<uniqList[i].get();

        QString ptrValue;

        if(uniqList[i].get() != nullptr)
             ptrValue= QString::number(*uniqList[i].get());
        else
            ptrValue = "nullptr";

        model->setData( model->index(i,0), ptrValue);
        model->setData( model->index(i,1), QString::fromStdString(oss.str()));
    }

    model->setHeaderData(0,Qt::Horizontal, "Значение");
    model->setHeaderData(1,Qt::Horizontal, "Get");

    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_14->clear();
    ui->comboBox_15->clear();
    ui->comboBox_16->clear();
    ui->comboBox_17->clear();

    for(int i = 0; i < model->rowCount();i++){
        ui->comboBox->addItem(QString::number(i+1));
        ui->comboBox_2->addItem(QString::number(i+1));
        ui->comboBox_14->addItem(QString::number(i+1));
        ui->comboBox_15->addItem(QString::number(i+1));
        ui->comboBox_16->addItem(QString::number(i+1));
        ui->comboBox_17->addItem(QString::number(i+1));
    }

}


void MainWindow::on_pushButton_clicked()
{
    if(uniqList.size() < 20){
        uniqList.push_back(UniqPtr<int> (new int (rand())));
        updateUniqTable();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(ui->comboBox_14->currentIndex() >= 0){
        uniqList[ui->comboBox_14->currentIndex()].reset(new int (rand()));
        updateUniqTable();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    if(ui->comboBox_15->currentIndex() >= 0 && ui->comboBox_16->currentIndex() >= 0 && ui->comboBox_15->currentIndex() != ui->comboBox_16->currentIndex()){
        uniqList[ui->comboBox_15->currentIndex()] = moveUniq(uniqList[ui->comboBox_16->currentIndex()]);
        updateUniqTable();
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(ui->comboBox->currentIndex() >= 0 && ui->comboBox_2->currentIndex() >= 0 && ui->comboBox->currentIndex() != ui->comboBox_2->currentIndex()){
        uniqList[ui->comboBox->currentIndex()].swap(moveUniq(uniqList[ui->comboBox_2->currentIndex()]));
        updateUniqTable();
    }
}




void MainWindow::on_pushButton_2_clicked()
{
    if(ui->comboBox_17->currentIndex() >= 0){
        uniqList[ui->comboBox_17->currentIndex()].realese();
        updateUniqTable();
    }
}

