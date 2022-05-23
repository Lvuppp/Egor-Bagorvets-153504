#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
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
    auto str = ui->plainTextEdit->toPlainText().toStdString();

    Parser pars(std::move(str));
    ui->variables->clear();
    ui->complexStructs->clear();
    ui->functions->clear();
    ui->chagePosition->clear();
    ui->branches->clear();
    ui->mistakes->clear();

    for(auto v : pars.getVariables()){
        ui->variables->addItem(QString::fromStdString(v.getType() + " " + v.getName() + " = " +
                                                      v.getDefaulValue() + " " + v.getVisibilityArea() + "\n" + v.getPositions()));
    }

    for(auto v : pars.getFunctions()){
        ui->functions->addItem(QString::fromStdString(v.getPrototype() + "\nOverloads:\n " + v.getOverloadsFunc()));
    }

    for(auto v : pars.getChangePosition()){
        ui->chagePosition->addItem("Row :" + QString::number(v.first) + " ,Line :" + QString::number(v.second) + "\n");
    }

    for(auto v : pars.getBranches()){
        ui->branches->addItem("Branch pos:"+QString::number(v.first) + " " + ",branch deep: "+ QString::number(v.second) + "\n");
    }

    ui->complexStructs->addItem("Classes :" +QString::number(pars.getComplexStructs()[0]) + "\n" +
            "Structs :" +QString::number(pars.getComplexStructs()[1]) + "\n" +
            "Dinamyc arrrays :" +QString::number(pars.getComplexStructs()[2]) + "\n" +
            "Static arrrays :" +QString::number(pars.getComplexStructs()[3]) + "\n");



    QString inp=ui->plainTextEdit->toPlainText();
    bool existStart=inp.contains("#ifndef");
    bool existEnd=inp.contains("#endif");
    QString msg("#ifdnef, #endif: ");

    if(existStart){
        if(existEnd){
            msg+="Ошибка не найдена\n";

        }
        else{
            msg+="Отсутствует #endif\n";
        }
    }
    else {
        if(existEnd){
            msg+="Отсутствует #ifndef\n";
        }
        else{
            msg+="Ошибка не найдена\n";
        }
    }

    smatch sm;

    regex reg("(while)\\s*(\\()\\s*(false)\\s*(\\))");

    string inp2=ui->plainTextEdit->toPlainText().toStdString();
    std::vector<int> positions;
    int posit=0;

    msg+="while(false) ошибка: ";

    while(regex_search(inp2,sm,reg)){
        positions.push_back(posit+sm.position(0));

        posit += sm.prefix().length() + sm.length();

        inp2 = sm.suffix();
    }

    int row=0;
    int column=0;
    int counter=0;
    inp2 = ui->plainTextEdit->toPlainText().toStdString();

    if(positions.size()==0){
        msg+="Ошибки не найдены";
    }

    else{
        for(int i=0;i<inp2.length();i++){

            if(i==positions[counter]){
                msg+="Строка "+ QString::number(row)+"  ";
                counter++;
            }

            column++;
            if(inp2[i]=='\n'){
                row++;
                column=0;
            }
        }
    }

    ui->mistakes->addItem(msg);
}


void MainWindow::on_pushButton_2_clicked()
{
    QString currentText;
    auto fileName=QFileDialog::getOpenFileName(0,"Выберите файл");
    QFile file(fileName);

    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);

        currentText.clear();

        string line;
        while(!stream.atEnd()){
            line=stream.readLine().toStdString();
            currentText+=QString::fromStdString(line);
            currentText+='\n';
        }
    }

    else{
        qDebug()<<"file not opened";
    }

    file.close();

    ui->plainTextEdit->setPlainText(currentText);
}

