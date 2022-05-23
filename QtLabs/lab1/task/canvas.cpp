#include "canvas.h"

Canvas::Canvas(QWidget *parent)
{
    scene = new QGraphicsScene(0, 0, 1500, 750, parent);
    scene->addRect(scene->sceneRect());
    setScene(scene);

    FirstAbstractFactory factory;

    _rocket = factory.createRocket(x1,y,scene);
    _rocket->draw();

    _ufo = factory.createUfo(x2,y,scene);
    _ufo->draw();

    QPushButton *startButton = new QPushButton("Старт", this);
    startButton->setGeometry(50, 40, 75, 30);
    scene->addWidget(startButton);

    QPushButton *firstFactoryButton = new QPushButton("Первая фабрика", this);
    firstFactoryButton->setGeometry(1000, 40, 100, 30);
    scene->addWidget(firstFactoryButton);

    QPushButton *secondFactoryButton = new QPushButton("Вторая фабрика", this);
    secondFactoryButton->setGeometry(1200, 40, 100, 30);
    scene->addWidget(secondFactoryButton);

    connect(startButton,&QPushButton::clicked,this, &Canvas::startTimer);
    connect(firstFactoryButton,&QPushButton::clicked,this, &Canvas::swapToFirstFactories);
    connect(secondFactoryButton,&QPushButton::clicked,this, &Canvas::swapToSecondFactories);
}

void Canvas::startTimer(){
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this,SLOT(move()));
    timer->start(1000/1000);
}


void Canvas::move(){
    scene->clear();
    _rocket->move();
    _ufo->move();
}

void Canvas::swapToFirstFactories(){
    scene->clear();

    FirstAbstractFactory factory;

    _rocket = factory.createRocket(x1,y,scene);
    _rocket->draw();

    _ufo = factory.createUfo(x2,y,scene);
    _ufo->draw();
}

void Canvas::swapToSecondFactories(){
    scene->clear();

    SecondAbstractFactory factory;

    _rocket = factory.createRocket(x1,y,scene);
    _rocket->draw();

    _ufo = factory.createUfo(x2,y,scene);
    _ufo->draw();
}
