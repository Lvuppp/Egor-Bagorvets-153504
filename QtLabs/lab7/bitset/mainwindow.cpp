#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_6_clicked()
{
    BitSet<20> tmp(ui->lineEdit->text().toInt());
    bitset=tmp;
    printBits();
}

void MainWindow::printBits(){
    ui->label_3->clear();
    ui->label_4->clear();
    ui->label_6->clear();
    ui->label_7->clear();
    ui->label_8->clear();

    ui->lineEdit_2->setText(QString::fromStdString(bitset.toString()));
}

void MainWindow::on_pushButton_clicked()
{
    if (bitset.any()){
        ui->label_4->setText("True");
    }
    else{
        ui->label_4->setText("False");
    }

}


void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit_3->text().isEmpty()){
        bitset.set();
    }
    else if(ui->lineEdit_3->text().toInt()>20 ||ui->lineEdit_3->text().toInt()<0){
        return;
    }
    else{
        bitset.set(ui->lineEdit_3->text().toInt());
    }
    printBits();
}


void MainWindow::on_pushButton_3_clicked()
{
    if (bitset.all()){
        ui->label_3->setText("True");
    }
    else{
        ui->label_3->setText("False");
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    if(ui->lineEdit_4->text().isEmpty()){
        bitset.reset();
    }
    else if(ui->lineEdit_4->text().toInt()>20 ||ui->lineEdit_4->text().toInt()<0){
        return;
    }
    else{
        bitset.reset(ui->lineEdit_4->text().toInt());
    }
    printBits();
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->label_6->setText(QString::number(bitset.size()));
}


void MainWindow::on_pushButton_10_clicked()
{
    if(bitset.test(ui->lineEdit_5->text().toInt())){

        ui->label_7->setText("True");

    }
    else{
        ui->label_7->setText("False");

    }
}


void MainWindow::on_pushButton_5_clicked()
{
    bitset.flip();
    printBits();
}


void MainWindow::on_pushButton_7_clicked()
{
    if (bitset.none()){
        ui->label_8->setText("True");
    }
    else{
        ui->label_8->setText("False");
    }
}


void MainWindow::on_pushButton_11_clicked()
{
    BitSet<20> tmp(ui->lineEdit_6->text().toInt());
    bitset &= tmp;
    ui->lineEdit_2->setText(QString::fromStdString(bitset.toString()));
}


void MainWindow::on_pushButton_12_clicked()
{
    BitSet<20> tmp(ui->lineEdit_7->text().toInt());
    bitset|=tmp;
    ui->lineEdit_2->setText(QString::fromStdString(bitset.toString()));
}



void MainWindow::on_pushButton_14_clicked()
{
    BitSet<20> tmp(ui->lineEdit_9->text().toInt());
    bitset ^= tmp;
    ui->lineEdit_2->setText(QString::fromStdString(bitset.toString()));

}

