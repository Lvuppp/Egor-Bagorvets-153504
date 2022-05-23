#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"functions.h"
#include"member.h"
#include<QFile>
#include<QValidator>
#include<QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    _file.setFileName(_storage);

    ui->setupUi(this);
    ui->frame_2->hide();
    ui->frame_3->hide();
    drawTable();
    ui->name->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{20}$"),ui->name));
    ui->aboutYourself->setValidator(new QRegularExpressionValidator(QRegularExpression("^[A-z]{50}$"),ui->aboutYourself));
    ui->age->setValidator(new QIntValidator(0,10,ui->age));
    ui->growth->setValidator(new QIntValidator(0,300,ui->growth));
    ui->weight->setValidator(new QIntValidator(0,300,ui->weight));
    ui->partnerAgeMin->setValidator(new QIntValidator(0,10,ui->partnerAgeMin));
    ui->partnerAgeMax->setValidator(new QIntValidator(0,10,ui->partnerAgeMax));
    ui->partnerGrowthMax->setValidator(new QIntValidator(0,300,ui->partnerGrowthMax));
    ui->partnerGrowthMin->setValidator(new QIntValidator(0,300,ui->partnerGrowthMin));
    ui->partnerWeightMax->setValidator(new QIntValidator(0,300,ui->partnerWeightMax));
    ui->partnerWeightMin->setValidator(new QIntValidator(0,300,ui->partnerWeightMin));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_5_clicked()
{
    if(isFormCorrect()){

        Member member(ui->name->text(),ui->age->text(),ui->growth->text(),ui->weight->text(),ui->sex->currentText(),
                      ui->partnerAgeMin->text(),ui->partnerAgeMax->text(),ui->partnerGrowthMin->text(),ui->partnerAgeMax->text(),
                      ui->partnerWeightMin->text(),ui->partnerWeightMax->text(),ui->aboutYourself->text());

        if(_operationType == "Add"){
            _listOfMembers.push_back(member);
            writeInfo(_listOfMembers,_file);

            drawTable();
        }
        else if(_operationType == "Edit")
        {
            _listOfMembers[ui->membersList->currentIndex().row()] = member;
            writeInfo(_listOfMembers,_file);

            drawTable();
        }

        ui->label_10->clear();

    }
    else{
        ui->label_10->setText("Enter corect value");
    }
}

void MainWindow::on_membersList_clicked(const QModelIndex &index){
    QVector<QString> memberInfo = _listOfMembers.data()[index.row()].getInfo();

    ui->nameInfo->setText("Имя: " + memberInfo.at(0));
    ui->ageInfo->setText("Возраст: :" + memberInfo.at(1));
    ui->growthInfo->setText("Рост: " + memberInfo.at(2));
    ui->weightInfo->setText("Вес" + memberInfo.at(3));
    ui->sexInfo->setText("Пол: " + memberInfo.at(4));
    ui->aboutYourselfInfo->setText("Об участнике: " + memberInfo.at(11));

}


void MainWindow::on_pushButton_3_clicked(){
    if(ui->membersList->currentIndex().row() == -1 )
        return;

    if(_listOfMembers.length()>0){
        _operationType = "Edit";
        ui->frame_2->show();
        ui->frame_3->hide();


    QVector<QString> memberInfo = _listOfMembers.data()[ui->membersList->currentIndex().row()].getInfo();

    ui->name->setText(memberInfo[0]);
    ui->age->setText(memberInfo[1]);
    ui->growth->setText(memberInfo[2]);
    ui->weight->setText(memberInfo[3]);
    ui->sex->setCurrentText(memberInfo[4]);
    ui->partnerAgeMin->setText(memberInfo[5]);
    ui->partnerAgeMax->setText(memberInfo[6]);
    ui->partnerGrowthMin->setText(memberInfo[7]);
    ui->partnerGrowthMax->setText(memberInfo[8]);
    ui->partnerWeightMin->setText(memberInfo[9]);
    ui->partnerWeightMax->setText(memberInfo[10]);
    ui->aboutYourself->setText(memberInfo[11]);
    }
}


void MainWindow::on_pushButton_7_clicked()
{
    _operationType = "Add";
    ui->frame_2->show();
    ui->frame_3->hide();
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->pairList->clear();
    _pairs = findPair(_listOfMembers,_pairsIndex);
    for(int i = 0; i <_pairs.length(); i++){
        ui->pairList->addItem(_pairs[i].first.getInfo()[0] + " + " + _pairs[i].second.getInfo()[0] );
    }
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->pairList->currentIndex().row() == -1 )
        return;
    if(_pairs.length() > 0 ){

    if(_pairsIndex[ui->pairList->currentRow()].first >  _pairsIndex[ui->pairList->currentRow()].second - 1)
        qSwap(_pairsIndex[ui->pairList->currentRow()].first, _pairsIndex[ui->pairList->currentRow()].second);

    auto iter = &_listOfMembers[_pairsIndex[ui->pairList->currentRow()].first];
    _listOfMembers.erase(iter);
    iter = &_listOfMembers[ _pairsIndex[ui->pairList->currentRow()].second-1];
    _listOfMembers.erase(iter);


    writeInfo(_listOfMembers,_file);

    ui->pairList->clear();
    _pairs = findPair(_listOfMembers,_pairsIndex);

    for(int i = 0; i <_pairs.length(); i++){
        ui->pairList->addItem(_pairs[i].first.getInfo()[0] + " + " + _pairs[i].second.getInfo()[0] );
    }

    drawTable();
    }
}


void MainWindow::on_pushButton_9_clicked()
{
    ui->frame_3->show();
    ui->frame_2->hide();
}


void MainWindow::on_pushButton_10_clicked()
{
    _storage = QFileDialog::getOpenFileName(0,"Выберите файл","","*.txt");
    drawTable();
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->membersList->currentIndex().row() == -1 )
        return;

    if(_listOfMembers.length()){
        auto iter = &_listOfMembers[ui->membersList->currentIndex().row()];
        _listOfMembers.erase(iter);

        writeInfo(_listOfMembers,_file);
        drawTable();
    }
}


void MainWindow::on_pushButton_8_clicked()
{
    for(int i=1;i<_listOfMembers.length();i++)
        for(int j=i;j>0 && _listOfMembers[j-1].getInfo()[1].toInt()>_listOfMembers[j].getInfo()[1].toInt();j--)
            qSwap(_listOfMembers[j-1],_listOfMembers[j]);

    writeInfo(_listOfMembers,_file);

    ui->membersList->clear();

    for(int i = 0; i <_listOfMembers.length(); i++){
        ui->membersList->addItem(_listOfMembers[i].getInfo()[0] + ", " + _listOfMembers[i].getInfo()[1] + "ages");
    }

}

void MainWindow::on_sex_currentIndexChanged(int index)
{
    sexValueIsCorrect(ui->sex,index);
}


void MainWindow::on_name_editingFinished()
{
    strValueIsCorrect(ui->name,1,30);
}


void MainWindow::on_age_editingFinished()
{
    intValueIsCorrect(ui->age,0,300);
}


void MainWindow::on_growth_editingFinished()
{
    intValueIsCorrect(ui->growth,0,300);
}

void MainWindow::on_weight_editingFinished()
{
    intValueIsCorrect(ui->weight,0,300);
}

void MainWindow::on_aboutYourself_editingFinished()
{
    strValueIsCorrect(ui->aboutYourself,0,300);
}

void MainWindow::on_partnerAgeMin_editingFinished()
{
    ////intValueIsCorrect(ui->partnerAgeMin,0,ui->partnerAgeMax->text().toInt());
}

void MainWindow::on_partnerAgeMax_editingFinished()
{
    //intValueIsCorrect(ui->partnerAgeMax,ui->partnerAgeMin->text().toInt(),300);
}


void MainWindow::on_partnerGrowthMin_editingFinished()
{
    //    intValueIsCorrect(ui->partnerGrowthMin,0,ui->partnerGrowthMax->text().toInt());
}


void MainWindow::on_partnerWeightMin_editingFinished()
{
    //intValueIsCorrect(ui->partnerWeightMin,0,ui->partnerWeightMax->text().toInt());
}


void MainWindow::on_partnerGrowthMax_editingFinished()
{
    //intValueIsCorrect(ui->partnerGrowthMax,ui->partnerGrowthMin->text().toInt(),300);
}


void MainWindow::on_partnerWeightMax_editingFinished()
{
    //intValueIsCorrect(ui->partnerWeightMax,ui->partnerWeightMin->text().toInt(),300);
}



bool MainWindow::intValueIsCorrect(QLineEdit *widget,const int &minValue, const int &maxValue){
    int value = widget->text().toInt();
    if(value && value > minValue - 1 && value < maxValue + 1){
        widget->setStyleSheet(QString("QLineEdit {border-width: 1px;"
                                      "  border-style: solid; "
                                      "border-color: green;}"));
        return true;
    }
    else{
        widget->setStyleSheet(QString("QLineEdit {border-width: 1px;"
                                      "  border-style: solid; "
                                      "border-color: red;}"));
        return false;
    }
}

bool MainWindow::sexValueIsCorrect(QComboBox *widget,const int &index){
    if(index < 2){
        widget->setStyleSheet(QString("QComboBox {border-width: 1px;"
                                      "  border-style: solid; "
                                      "border-color: green;}"));
        return true;
    }
    else{
        widget->setStyleSheet(QString("QLineEdit {border-width: 1px;"
                                      "  border-style: solid; "
                                      "border-color: red;}"));
        return false;
    }
}

bool MainWindow::strValueIsCorrect(QLineEdit *widget,const int &minValue, const int &maxValue){
    int value = widget->text().length();
    if(value > minValue - 1 && value < maxValue + 1){
        widget->setStyleSheet(QString("QLineEdit {border-width: 1px;"
                                      "  border-style: solid; "
                                      "border-color: green;}"));
        return true;
    }
    else{
        widget->setStyleSheet(QString("QLineEdit {border-width: 1px;"
                                      "  border-style: solid; "
                                      "border-color: red;}"));
        return false;
    }
}

bool MainWindow::isFormCorrect(){
    sexValueIsCorrect(ui->sex,ui->sex->currentIndex());
    strValueIsCorrect(ui->name,1,30);
    intValueIsCorrect(ui->age,0,300);
    intValueIsCorrect(ui->growth,0,300);
    intValueIsCorrect(ui->weight,0,300);
    strValueIsCorrect(ui->aboutYourself,0,300);
    intValueIsCorrect(ui->partnerAgeMin,0,ui->partnerAgeMax->text().toInt());
    intValueIsCorrect(ui->partnerAgeMax,ui->partnerAgeMin->text().toInt(),300);
    intValueIsCorrect(ui->partnerGrowthMin,0,ui->partnerGrowthMax->text().toInt());
    intValueIsCorrect(ui->partnerWeightMin,0,ui->partnerWeightMax->text().toInt());
    intValueIsCorrect(ui->partnerGrowthMax,ui->partnerGrowthMin->text().toInt(),300);
    intValueIsCorrect(ui->partnerWeightMax,ui->partnerWeightMin->text().toInt(),300);

    if(sexValueIsCorrect(ui->sex,ui->sex->currentIndex())&&
            strValueIsCorrect(ui->name,1,30)&&
            intValueIsCorrect(ui->age,0,300)&&
            intValueIsCorrect(ui->growth,0,300)&&
            intValueIsCorrect(ui->weight,0,300)&&
            strValueIsCorrect(ui->aboutYourself,0,300)&&
            intValueIsCorrect(ui->partnerAgeMin,0,ui->partnerAgeMax->text().toInt())&&
            intValueIsCorrect(ui->partnerAgeMax,ui->partnerAgeMin->text().toInt(),300)&&
            intValueIsCorrect(ui->partnerGrowthMin,0,ui->partnerGrowthMax->text().toInt())&&
            intValueIsCorrect(ui->partnerWeightMin,0,ui->partnerWeightMax->text().toInt())&&
            intValueIsCorrect(ui->partnerGrowthMax,ui->partnerGrowthMin->text().toInt(),300)&&
            intValueIsCorrect(ui->partnerWeightMax,ui->partnerWeightMin->text().toInt(),300))
        return true;
    return false;
}

void MainWindow::drawTable()
{
    ui->membersList->clear();
    _file.setFileName(_storage);

    if(readInfo(_file,_listOfMembers ) == 1){
          ui->error->setText("Uncorrect file");
    }

    for(int i = 0; i <_listOfMembers.length(); i++){
        ui->membersList->addItem(_listOfMembers[i].getInfo()[0] + ", " + _listOfMembers[i].getInfo()[1] + "ages");
    }
}


void MainWindow::on_membersList_activated(const QModelIndex &index)
{

}

