#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    closeFrames();
    ui->frame->show();

    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->secondName->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{20}$"),ui->secondName));
    ui->firstName->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{20}$"),ui->firstName));


    ui->secondName_2->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{20}$"),ui->secondName_2));
    ui->firstName_2->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{20}$"),ui->firstName_2));

    readFile();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_9_clicked()
{
    QString tmp = filePath;
    filePath = QFileDialog::getOpenFileName(0,"Выберите файл","","*.txt");

    if(filePath.isEmpty()){
        filePath = tmp;
    }

    readFile();
}

void MainWindow::on_pushButton_3_clicked()
{
    auto reply = QMessageBox::question(this,"Очищение файла", "Хотите очистить файл",QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes){
        list.clear();
        saveFile();
        updateTable();
        ui->label_3->setText("Файл очищен");
    }
    else{
        return;
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    closeFrames();
    dataStatement = "ADD";
    ui->label_2->setText("Добавления информации рейса");
    ui->frame->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    closeFrames();
    if(list.length() ==0 ){
        return;
    }
    dataStatement = "EDIT";
    ui->label_2->setText("Изменение информации рейса");
    ui->frame->show();

    auto tmp = list.at(ui->comboBox->currentIndex());

    ui->firstName->setText(tmp.data.firstName);
    ui->secondName->setText(tmp.data.secondName);
    ui->number->setText(tmp.data.number);
    ui->payment->setText(QString::number(tmp.data.payment));
    ui->hours->setText(QString::number(tmp.data.workHours));
}


void MainWindow::on_pushButton_7_clicked()
{
    closeFrames();
    if(list.length() ==0 ){
        return;
    }
    dataStatement = "FIND";
    ui->frame_2->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    closeFrames();
    if(list.length() ==0 ){
        return;
    }
    dataStatement = "GET";
    ui->frame_3->show();
}



void MainWindow::closeFrames()
{
    ui->frame->hide();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->frame_5->hide();
    ui->frame_6->hide();

    ui->label_3->setText("");
}


void MainWindow::on_pushButton_10_clicked()
{
    saveFile();
}


void MainWindow::on_pushButton_8_clicked()
{
    int salary = ui->payment->text().toInt()*(ui->hours->text().toInt());
    int extraSalary = ui->payment->text().toInt()*(ui->hours->text().toInt() - 144);

    if(extraSalary > 0)
        salary += extraSalary;
    Employee tmp(ui->firstName->text(),ui->secondName->text(),ui->number->text(),ui->payment->text().toInt(),ui->hours->text().toInt(),salary);

    if(tmp.firstName.length() < 21 && tmp.firstName.length() > 0 &&
            tmp.secondName.length() < 21 && tmp.secondName.length() > 0 &&
            tmp.number.length() < 4 && tmp.number.length() > 0 &&
            tmp.payment < 10000 && tmp.payment > 0 &&
            tmp.workHours < 1000 && tmp.workHours > 0 &&
            tmp.salary < 1000000 && tmp.salary > 0)
    {
        if(dataStatement == "ADD"){
            Employee tmp{ui->firstName->text(),ui->secondName->text(),ui->number->text(),ui->payment->text().toInt(),ui->hours->text().toInt(),salary};
            list.addInTail(tmp);

            ui->firstName->clear();
            ui->number->clear();
            ui->payment->clear();
            ui->hours->clear();
            ui->secondName->clear();

            ui->label_3->setText("Данные успешно добавлены");
        }
        else if(dataStatement == "EDIT"){
            Employee tmp(ui->firstName->text(),ui->secondName->text(),ui->number->text(),ui->payment->text().toInt(),ui->hours->text().toInt(),salary);

            list.at(ui->comboBox->currentIndex()).data = tmp;

            ui->firstName->clear();
            ui->secondName->clear();
            ui->payment->clear();
            ui->hours->clear();
            ui->number->clear();

            ui->label_3->setText("Данные успешно изменены");
        }
    }
    else{
        ui->label_3->setText("Данные некорректны");
    }

    updateTable();
    saveFile();
}

void MainWindow::updateTable(){

    auto model = new QStandardItemModel(list.length() ,6,this);

    ui->tableView->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        model->setData( model->index(i,0), list.at(i).data.firstName);
        model->setData( model->index(i,1), list.at(i).data.secondName);
        model->setData( model->index(i,2), list.at(i).data.number);
        model->setData( model->index(i,3), list.at(i).data.payment);
        model->setData( model->index(i,4), list.at(i).data.workHours);
        model->setData( model->index(i,5), list.at(i).data.salary);
    }

    model->setHeaderData(0,Qt::Horizontal, "Имя");
    model->setHeaderData(1,Qt::Horizontal, "Фамилия");
    model->setHeaderData(2,Qt::Horizontal, "Номер");
    model->setHeaderData(3,Qt::Horizontal, "Плата за час");
    model->setHeaderData(4,Qt::Horizontal, "Рабочее время");
    model->setHeaderData(5,Qt::Horizontal, "Зарплата");

    ui->comboBox->clear();
    ui->comboBox_3->clear();

    for(int i = 0; i < model->rowCount();i++){
        ui->comboBox->addItem(QString::number(i+1));
        ui->comboBox_3->addItem(QString::number(i+1));
    }
}

void MainWindow::updateEmployeeTable(const List &Employees,QTableView *table){


    auto model = new QStandardItemModel(Employees.length() ,6,this);

    table->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        model->setData( model->index(i,0), list.at(i).data.firstName);
        model->setData( model->index(i,1), list.at(i).data.secondName);
        model->setData( model->index(i,2), list.at(i).data.number);
        model->setData( model->index(i,3), list.at(i).data.payment);
        model->setData( model->index(i,4), list.at(i).data.workHours);
        model->setData( model->index(i,5), list.at(i).data.salary);
    }

    model->setHeaderData(0,Qt::Horizontal, "Имя");
    model->setHeaderData(1,Qt::Horizontal, "Фамилия");
    model->setHeaderData(2,Qt::Horizontal, "Номер");
    model->setHeaderData(3,Qt::Horizontal, "Плата за час");
    model->setHeaderData(4,Qt::Horizontal, "Рабочее время");
    model->setHeaderData(5,Qt::Horizontal, "Зарплата");

}

void MainWindow::saveFile(){
    QFile file(filePath);

    if(!file.open(QIODevice::ReadWrite)){
        ui->fileStatment->setText("Can't save this file!");
        return;
    }

    QTextStream stream(&file);

    file.resize(0);

    for (int i = 0; i < list.length(); i++) {
        qDebug() << i;
        stream << list.at(i).data.firstName<< " ";
        stream << list.at(i).data.secondName<< " ";
        stream << list.at(i).data.number << " ";
        stream << list.at(i).data.payment << " ";
        stream << list.at(i).data.workHours << " ";
        stream << list.at(i).data.salary << "\n";
    }

    ui->fileStatment->setText("Файл сохранён");

    file.close();
}


void MainWindow::readFile(){
    QFile file(filePath);
    QTextStream stream(&file);

    if(!file.open(QIODevice::ReadWrite)){
        ui->fileStatment->setText("Не получаеться открыть этот файл");
        return;
    }

    if(file.size() == 0){
        ui->fileStatment->setText("Вы открыли пустой файл");
        return;
    }

    List listTmp;



    while(!stream.atEnd()){
        auto tmp = stream.readLine().split(' ');

        if(tmp.length() != 6 || tmp.at(0).length() > 21 || tmp.at(0).length() < 0 ||
                tmp.at(1).toInt() > 21 || tmp.at(1).toInt() < 0 ||
                tmp.at(2).length() > 21 || tmp.at(2).length() < 0 ||
                tmp.at(3).toInt() > 10000 || tmp.at(3).toInt() < 0 ||
                tmp.at(4).toInt() > 1000 || tmp.at(4).toInt() < 0 ||
                tmp.at(5).toInt() > 1000000 || tmp.at(5).toInt() < 0)
        {
            ui->fileStatment->setText("Некоректные данные в файле");

            file.close();
            return;
        }    // проверка на корректность введённых даннных
    }

    QFile file1(filePath);
    QTextStream stream1(&file1);

    list.clear();
    file1.open(QIODevice::ReadWrite);

    while(!stream1.atEnd()){
        auto tmp = stream1.readLine().split(' ');

        if(tmp.length() != 6 || tmp.at(0).length() > 21 || tmp.at(0).length() < 0 ||
                tmp.at(1).toInt() > 21 || tmp.at(1).toInt() < 0 ||
                tmp.at(2).length() > 21 || tmp.at(2).length() < 0 ||
                tmp.at(3).toInt() > 10000 || tmp.at(3).toInt() < 0 ||
                tmp.at(4).toInt() > 1000 || tmp.at(4).toInt() < 0 ||
                tmp.at(5).toInt() > 1000000 || tmp.at(5).toInt() < 0)
        {
            ui->fileStatment->setText("Некоректные данные в файле");
            return;
        }    // проверка на корректность введённых даннных

        Employee Employee(tmp.at(0),
                          tmp.at(1),
                          tmp.at(2),
                          tmp.at(3).toInt(),
                          tmp.at(4).toInt(),
                          tmp.at(5).toInt());



        list.addInTail(Employee);
    }

    ui->fileStatment->setText("File open");

    list.print();

    file.close();

    updateTable();
}

void MainWindow::on_pushButton_clicked()
{

}


void MainWindow::on_pushButton_11_clicked()
{
    if(list.length() ==0 ){
        return;
    }
    List tmp;

    for(int i = 0; i < list.length(); i++){
        if(ui->firstName_2->text() == list.at(i).data.firstName && ui->secondName_2->text() == list.at(i).data.secondName){
            tmp.addInTail(list.at(i).data);
        }
    }


    updateEmployeeTable(tmp,ui->tableView_2);

    if(tmp.length() == 0){
        ui->label_4->setText("Работников не найденов");
        return;
    }

}


void MainWindow::on_pushButton_12_clicked()
{
    if(list.length() ==0 ){
        return;
    }
    List tmp;

    for(int i = 0; i < list.length(); i++){
        if(ui->salary->text().toInt() < list.at(i).data.salary){
            tmp.addInTail(list.at(i).data);
            ui->label_4->setText("");
        }
    }


    updateEmployeeTable(tmp,ui->tableView_3);
    if(tmp.length() == 0){
        ui->label_5->setText("Сотрудники не найдены");
        return;
    }


    ui->label_5->setText("");
}







void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == -1 || dataStatement != "EDIT")
        return;
    auto tmp = list.at(index);

    ui->firstName->setText(tmp.data.firstName);
    ui->secondName->setText(tmp.data.secondName);
    ui->number->setText(tmp.data.number);
    ui->payment->setText(QString::number(tmp.data.payment));
    ui->hours->setText(QString::number(tmp.data.workHours));
}


void MainWindow::on_pushButton_13_clicked()
{
    if(list.length() ==0 ){
        return;
    }
    auto deleteIndex = ui->comboBox_3->currentIndex();
    list.erase(deleteIndex);

    closeFrames();
    saveFile();
    updateTable();
}


void MainWindow::on_pushButton_16_clicked()
{
    if(list.length() ==0 ){
        return;
    }
    List tmp;

    for(int i = 0; i < list.length(); i++){
        if(ui->salary->text().toInt() < list.at(i).data.salary){
            tmp.addInTail(list.at(i).data);
        }
    }


    updateEmployeeTable(tmp,ui->tableView_3);

    if(tmp.length() == 0){
        ui->label_5->setText("Сотрудники не найдены");
        return;
    }


    ui->label_5->setText("");

}


void MainWindow::on_pushButton_17_clicked()
{
    closeFrames();
    ui->frame_6->show();

    if(list.length() == 0){
        return;
    }

    List tmp;

    for(int i = 0; i < list.length(); i++){
        if(144 < list.at(i).data.workHours){
            tmp.addInTail(list.at(i).data);
            ui->label_12->setText("");
        }
    }

    updateEmployeeTable(tmp,ui->tableView_5);

    if(tmp.length() == 0){
        ui->label_12->setText("Сотрудники не найдены");
        return;
    }

    ui->label_12->setText("");

}

