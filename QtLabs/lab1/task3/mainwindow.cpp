#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QFile file(getWay());
    file.open(QIODevice::ReadWrite);

    createTable(file);
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QString str = ui->lineEdit->text();

    if(inputIsCorrect(str)){
        auto parts = str.split(".");
        Date birthday(parts[0].toInt(),parts[1].toInt(),parts[2].toInt()),date;

        ui->label_5->setText("days to your birthday:" + QString::number(date.daysTillYourBirthday(birthday)));
    }
    else{
        ui->label_5->setText("date isn`t correct");
    }

}

void MainWindow::createTable(QFile &file){

    int length = 0;

    Date *listOfDates = new Date[length];
    QTextStream stream(&file);

    stream.seek(0);

    while(!stream.atEnd()){

        Date *updateList = new Date[length+1];
        QString str = stream.readLine();
        if(!inputIsCorrect(str)){
            ui->label_3->setText("Broken file");
            delete[] listOfDates;
            return;
        }
        auto parts = str.split(".");

        for(int i = 0; i < length; i++){
            updateList[i] = listOfDates[i];
        }

        delete[] listOfDates;

        listOfDates = updateList;
        length++;

        Date date(parts[0].toInt(),parts[1].toInt(),parts[2].toInt());
        listOfDates[length - 1] = date;

    }

    file.close();

    auto model = new QStandardItemModel(length ,3,this);

    ui->tableView->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        Date currentDate;
        model->setData( model->index(i,0), listOfDates[i].getString());
        model->setData( model->index(i,1), listOfDates[i].nextDay().getString());
        model->setData( model->index(i,2), listOfDates[i].duration(currentDate));
    }

    model->setHeaderData(0,Qt::Horizontal, "date");
    model->setHeaderData(1,Qt::Horizontal, "next date");
    model->setHeaderData(2,Qt::Horizontal, "different");

    ui->comboBox->clear();

    for(int i = 0; i < model->rowCount();i++){
        ui->comboBox->addItem(QString::number(i+1));
    }

    delete[] listOfDates;
}

void MainWindow::on_pushButton_3_clicked(){
    QString date = ui->lineEdit_2->text();
    if(inputIsCorrect(date)){

        QFile file(getWay());
        file.open(QIODevice::ReadWrite);

        QTextStream stream(&file);

        qDebug() <<file.size();

        stream.seek(file.size());
        stream << date << '\n';

        file.flush();
        file.close();


        createTable(file);
    }
    return ;
}

void MainWindow::on_pushButton_4_clicked()
{
    int index = ui->comboBox->currentText().toInt() - 1;
    QString date = ui->lineEdit_4->text();
    if(inputIsCorrect(date)){
        ui->label_5->setText("");


        QFile file(getWay());
        file.open(QIODevice::ReadWrite);

        QTextStream stream(&file);

        stream.seek(11*(index));

        QString tmp= date;

        stream<<tmp;

        file.close();

        createTable(file);
    }
    else{
        ui->label_5->setText("date isn`t correct");
    }
    return ;

}


bool MainWindow::inputIsCorrect(const QString &str){
    auto parts = str.split(".");

    if(str.isEmpty() || parts.length() < 3){
        return false;
    }

    Date date(parts[0].toInt(),parts[1].toInt(),parts[2].toInt());

    if(!date.isCorrect())
        return false;

    return true;
}

QString MainWindow::getWay(){
    QString way = storage;

    QFile file(way);
    if(way != "C:/Users/User/Documents/lab1/dates.txt"){
    if(!file.exists()){
        ui->label_3->setText("Cant use this file");
        return "";
    }

    if(!file.open(QIODevice::ReadWrite)){
        ui->label_3->setText("Cant use this file");
        return "";
    }
    }
    ui->label_3->setText("");

    return way;
}

void MainWindow::on_pushButton_5_clicked()
{
    storage = QFileDialog::getOpenFileName(0,"Выберите файл","","*.txt");

    QFile file(getWay());
    file.open(QIODevice::ReadWrite);

    createTable(file);
    file.close();
}

