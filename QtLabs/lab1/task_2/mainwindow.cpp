#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "figure.h"
#include<QValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scene->setSceneRect(0,0,562,312);

    ui->lineEdit_3->setValidator(new QIntValidator(0,100,ui->lineEdit_3));

    ui->lineEdit->setValidator(new QIntValidator(0,100,ui->lineEdit));

    ui->lineEdit_2->setValidator(new QIntValidator(0,100,ui->lineEdit_2));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new Triangle(x,y,scene,scale/100,ui->horizontalSlider->value());
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_2_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new Rectangle(x,y,scene,scale/100,ui->horizontalSlider->value(),2);
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_6_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new Rhombus(x,y,scene,scale/100,ui->horizontalSlider->value());
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_3_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new Square(x,y,scene,scale/100,ui->horizontalSlider->value());
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_4_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new Ellipse(x,y,scene,scale/100,ui->horizontalSlider->value(),2);
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_5_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new Circle(x,y,scene,scale/100,ui->horizontalSlider->value());
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_7_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new Star(x,y,scene,scale/100,ui->horizontalSlider->value(),5);
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_8_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new SixFigureedStar(x,y,scene,scale/100,ui->horizontalSlider->value());
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_pushButton_9_clicked()
{

    scale = ui->horizontalSlider_2->value();
    figure = new EightFigureedStar(x,y,scene,scale/100,ui->horizontalSlider->value());
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    if(figure == nullptr)
        return;
    scene->clear();
    figure->turn(value);
    updateInfo();
}



void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if(figure == nullptr)
        return;
    scene->clear();
    scale = value;
    figure->changeScale(scale / 100);
    updateInfo();
}


void MainWindow::on_pushButton_10_clicked()
{
    if(figure == nullptr)
        return;
    scene->clear();
    figure->rotate(ui->lineEdit->text().toInt(),ui->lineEdit_2->text().toInt());
    updateInfo();
}

void MainWindow::on_pushButton_11_clicked()
{
    scale = ui->horizontalSlider_2->value();
    figure = new NFigureedStar(x,y,scene,scale/100,ui->horizontalSlider->value(),ui->lineEdit_3->text().toInt());
    scene->clear();
    figure->createFigure();
    updateInfo();
}


void MainWindow::updateInfo(){
    ui->perimetr->setText(QString::number(figure->perimetr()));
    ui->square->setText(QString::number(figure->square()));
    ui->xCoordinate->setText(QString::number(figure->centerOfMass().y()));
    ui->yCoordinate->setText(QString::number(figure->centerOfMass().y()));
}

void MainWindow::on_pushButton_12_clicked()
{
   scene->clear();

}

