#ifndef CANVAS_H
#define CANVAS_H

#include<QGraphicsView>
#include<QGraphicsItem>
#include<QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include<QTimer>

#include"figures.h"
#include"abstractfactory.h"

class Canvas : public QGraphicsView
{
    Q_OBJECT

public:
    Canvas(QWidget *parent = nullptr);
    ~Canvas(){};

private:
    QGraphicsScene *scene;
    QTimer *timer;
    Rocket *_rocket = nullptr;
    Ufo *_ufo = nullptr;
    int x1 = 350, x2 = 750, y = 300;
private slots:
    void startTimer();
    void swapToSecondFactories();
    void swapToFirstFactories();
    void move();
};
#endif // CANVAS_H
