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
    ui->destination->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{20}$"),ui->destination));

    ui->destination_2->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{20}$"),ui->destination_2));

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

    auto dateTmp = tmp.date.toString(Qt::DateFormat::ISODate).split('-');
    auto timeTmp = tmp.dispatchTime.toString(Qt::DateFormat::ISODate).split(':');

    ui->dateLine->setText(dateTmp.at(2)+dateTmp.at(1) + dateTmp.at(0));
    ui->tieLine->setText(timeTmp.at(0)+timeTmp.at(1));
    ui->number->setText(tmp.number);
    ui->destination->setText(tmp.destination);
    ui->freePlaces->setText(QString::number(tmp.freePlaces));
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


void MainWindow::on_pushButton_2_clicked()
{
    closeFrames();

    if(list.length() ==0 ){
        return;
    }
    dataStatement = "BUY";
    ui->frame_4->show();

    auto tmp = list.at(ui->comboBox->currentIndex());

    ui->label_9->setText(tmp.number);
    ui->label_7->setText(QString::number(tmp.freePlaces));
}

void MainWindow::closeFrames()
{
    ui->frame->hide();
    ui->frame_2->hide();
    ui->frame_3->hide();
    ui->frame_4->hide();

    ui->label_3->setText("");
}


void MainWindow::on_pushButton_10_clicked()
{
    saveFile();
}


void MainWindow::on_pushButton_8_clicked()
{
    auto dateTmp = ui->dateLine->text().split('.');
    auto timeTmp = ui->tieLine->text().split(':');

    if(QDate::isValid(dateTmp.at(2).toInt(),dateTmp.at(1).toInt(),dateTmp.at(0).toInt()) &&
            QTime::isValid(timeTmp.at(0).toInt(),timeTmp.at(1).toInt(),0))
    {

        if(dataStatement == "ADD"){
            QDate date(dateTmp.at(2).toInt(),dateTmp.at(1).toInt(),dateTmp.at(0).toInt());
            QTime time(timeTmp.at(0).toInt(),timeTmp.at(1).toInt(),0);
            Flight tmp{date,time,ui->number->text(),ui->destination->text(),ui->freePlaces->text().toInt()};
            list.addInTail(tmp);

            ui->dateLine->clear();
            ui->number->clear();
            ui->destination->clear();
            ui->freePlaces->clear();
            ui->tieLine->clear();

            ui->label_3->setText("Данные успешно добавлены");
        }
        else if(dataStatement == "EDIT"){
            QDate date(dateTmp.at(2).toInt(),dateTmp.at(1).toInt(),dateTmp.at(0).toInt());
            QTime time(timeTmp.at(0).toInt(),timeTmp.at(1).toInt(),0);
            Flight tmp{date,time,ui->number->text(),ui->destination->text(),ui->freePlaces->text().toInt()};

            list.at(ui->comboBox->currentIndex()) = tmp;

            ui->dateLine->clear();
            ui->numberLine->clear();
            ui->destination->clear();
            ui->freePlaces->clear();
            ui->timeLine->clear();

            ui->label_3->setText("Данные успешно изменены");
        }
    }
    else
    {
        ui->label_3->setText("Введите корректные данные");
        return;
    }

    updateTable();
    saveFile();
}

void MainWindow::updateTable(){

    auto model = new QStandardItemModel(list.length() ,5,this);

    ui->tableView->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        model->setData( model->index(i,0), list.at(i).date.toString());
        model->setData( model->index(i,1), list.at(i).dispatchTime);
        model->setData( model->index(i,2), list.at(i).number);
        model->setData( model->index(i,3), list.at(i).destination);
        model->setData( model->index(i,4), list.at(i).freePlaces);
    }

    model->setHeaderData(0,Qt::Horizontal, "Дата");
    model->setHeaderData(1,Qt::Horizontal, "Время прибытия");
    model->setHeaderData(2,Qt::Horizontal, "Номер рейса");
    model->setHeaderData(3,Qt::Horizontal, "Место прибытия");
    model->setHeaderData(4,Qt::Horizontal, "Свободные места");

    ui->comboBox->clear();
    ui->comboBox_2->clear();
    ui->comboBox_3->clear();

    for(int i = 0; i < model->rowCount();i++){
        ui->comboBox->addItem(QString::number(i+1));
        ui->comboBox_2->addItem(QString::number(i+1));
        ui->comboBox_3->addItem(QString::number(i+1));
    }
}

void MainWindow::updateFlightTable(const List<Flight> &flights,QTableView *table){

    auto model = new QStandardItemModel(flights.length() ,5,this);

    table->setModel(model);

    for(int i = 0; i < model->rowCount(); i++){
        model->setData( model->index(i,0), flights.at(i).date.toString());
        model->setData( model->index(i,1), flights.at(i).dispatchTime);
        model->setData( model->index(i,2), flights.at(i).number);
        model->setData( model->index(i,3), flights.at(i).destination);
        model->setData( model->index(i,4), flights.at(i).freePlaces);
    }

    model->setHeaderData(0,Qt::Horizontal, "Дата");
    model->setHeaderData(1,Qt::Horizontal, "Время прибытия");
    model->setHeaderData(2,Qt::Horizontal, "Номер рейса");
    model->setHeaderData(3,Qt::Horizontal, "Место прибытия");
    model->setHeaderData(4,Qt::Horizontal, "Свободные места");

}

void MainWindow::saveFile(){
    QFile file(filePath);

    if(!file.open(QIODevice::ReadWrite)){
        ui->fileStatment->setText("Can't save this file!");
        return;
    }

    QTextStream stream(&file);

    file.resize(0);

    for (std::size_t i = 0; i < list.length(); i++) {
        qDebug() << i;
        stream << list.at(i).date.toString(Qt::DateFormat::ISODate) << " ";
        stream << list.at(i).dispatchTime.toString(Qt::DateFormat::ISODate) << " ";
        stream << list.at(i).number << " ";
        stream << list.at(i).destination << " ";
        stream << list.at(i).freePlaces << "\n";
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

    List<Flight> listTmp;

    while(!stream.atEnd()){
        auto tmp = stream.readLine().split(' ');

        if(tmp.length() != 5 || !QDate::fromString(tmp.at(0),Qt::DateFormat::ISODate).isValid() ||
                !QTime::fromString(tmp.at(1),Qt::DateFormat::ISODate).isValid() ||
                tmp.at(2).length() > 21 || tmp.at(2).length() < 0 ||
                tmp.at(3).toInt() > 10000 || tmp.at(3).toInt() < 0 ||
                tmp.at(4).toInt() > 1000 || tmp.at(4).toInt() < 0)
        {
            ui->fileStatment->setText("Некоректные данные в файле");
            return;
        }    // проверка на корректность введённых даннных

        Flight flight{QDate::fromString(tmp.at(0),Qt::DateFormat::ISODate),
                    QTime::fromString(tmp.at(1),Qt::DateFormat::ISODate),
                    tmp.at(2),
                    tmp.at(3),
                    tmp.at(4).toInt()};



        listTmp.addInTail(flight);
    }


    ui->fileStatment->setText("File open");

    file.close();

    list = listTmp;
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
    auto dateTmp = ui->dateLine_2->text().split('.');


    QDate date(dateTmp.at(2).toInt(),dateTmp.at(1).toInt(),dateTmp.at(0).toInt());
    List<Flight> tmp;

    if(!QDate::isValid(dateTmp.at(2).toInt(),dateTmp.at(1).toInt(),dateTmp.at(0).toInt())){
        ui->label_4->setText("Некоректно введены данные");
        updateFlightTable(tmp,ui->tableView_2);
        return;
    }

    for(std::size_t i = 0; i < list.length(); i++){
        if(date == list.at(i).date && ui->numberLine->text().toInt() == list.at(i).number.toInt()){
            tmp.addInTail(list.at(i));
        }
    }

    if(tmp.length() == 0){
        ui->label_4->setText("Рейсов не найден");
        return;
    }

    updateFlightTable(tmp,ui->tableView_2);
}


void MainWindow::on_pushButton_12_clicked()
{

    if(list.length() ==0 ){
        return;
    }
    auto timeTmp = ui->timeLine->text().split(':');
    QTime time(timeTmp.at(0).toInt(),timeTmp.at(1).toInt(),0);
    List<Flight> tmp;

    if(!time.isValid()){
        ui->label_4->setText("Некоректно введены данные");
        updateFlightTable(tmp,ui->tableView_3);
        return;
    }

    for(std::size_t i = 0; i < list.length(); i++){
        if(time < list.at(i).dispatchTime && ui->destination_2->text() == list.at(i).destination){
            tmp.addInTail(list.at(i));
        }
    }

    if(tmp.length() == 0){
        ui->label_4->setText("Рейс не найден");
        return;
    }

    updateFlightTable(tmp,ui->tableView_3);
}





void MainWindow::on_pushButton_14_clicked()
{

    if(list.length() ==0 ){
        return;
    }
    int buyingPlaces = ui->freePlaces_2->text().toInt();
    int index = ui->comboBox_2->currentIndex();

    if(buyingPlaces > 1000 || buyingPlaces <= 0){
        ui->label_10->setText("Некорректно введены данные");
        return;
    }

    if(buyingPlaces > list.at(index).freePlaces){
        ui->label_10->setText("Невозможно выполнить заказ");
        return;
    }
    list.at(index).freePlaces -= buyingPlaces;

    ui->label_7->setText(QString::number(list.at(index).freePlaces));

    saveFile();
    updateTable();
}



void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    if(index == -1)
        return;

    auto tmp = list.at(index);

    ui->label_9->setText(tmp.number);
    ui->label_7->setText(QString::number(tmp.freePlaces));
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index == -1 || dataStatement != "EDIT")
        return;
    auto tmp = list.at(index);

    auto dateTmp = tmp.date.toString(Qt::DateFormat::ISODate).split('-');
    auto timeTmp = tmp.dispatchTime.toString(Qt::DateFormat::ISODate).split(':');

    ui->dateLine->setText(dateTmp.at(2)+dateTmp.at(1) + dateTmp.at(0));
    ui->tieLine->setText(timeTmp.at(0)+timeTmp.at(1));
    ui->number->setText(tmp.number);
    ui->destination->setText(tmp.destination);
    ui->freePlaces->setText(QString::number(tmp.freePlaces));
}


void MainWindow::on_pushButton_13_clicked()
{
    if(list.length() ==0 ){
        return;
    }
    auto deleteIndex = ui->comboBox_3->currentIndex();
    list.erase(deleteIndex);
    saveFile();
    updateTable();
}

