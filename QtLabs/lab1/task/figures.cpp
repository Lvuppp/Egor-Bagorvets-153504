#include "figures.h"


FirstRocket::FirstRocket(const int& x,const int& y, QGraphicsScene *scene){
    _x = x;
    _y = y;
    _scene = scene;
}

SecondRocket::SecondRocket(const int& x,const int& y, QGraphicsScene *scene){
    _x = x;
    _y = y;
    _scene = scene;
}

FirstUfo::FirstUfo(const int &x, const int &y, QGraphicsScene *scene){
    _x = x;
    _y = y;
    _scene = scene;
}

SecondUfo::SecondUfo(const int &x, const int &y, QGraphicsScene *scene){
    _x = x;
    _y = y;
    _scene = scene;
}

void FirstUfo::draw(){
    QRectF head(_x - 50,_y - 50,100,100);
    _headItem = new QGraphicsEllipseItem(head);
    _headItem->setBrush(Qt::blue);

    QRectF frame(_x - 150,_y,300,50);
    _frameItem = new QGraphicsEllipseItem(frame);
    _frameItem->setBrush(Qt::lightGray);

    QRectF nozzle(_x - 75,_y+25,150,50);
    _nozzleItem = new QGraphicsEllipseItem(nozzle);
    _nozzleItem->setBrush(Qt::darkGray);

    _scene->addItem(_headItem);
    _scene->addItem(_nozzleItem);
    _scene->addItem(_frameItem);

}

void SecondUfo::draw(){
    QRectF head(_x - 100,_y - 75,200,150);
    _headItem = new QGraphicsEllipseItem(head);
    _headItem->setBrush(Qt::green);

    QRectF frame(_x - 200,_y,400,100);
    _frameItem = new QGraphicsEllipseItem(frame);
    _frameItem->setBrush(Qt::black);

    QRectF nozzle(_x - 100,_y+25,200,100);
    _nozzleItem = new QGraphicsEllipseItem(nozzle);
    _nozzleItem->setBrush(Qt::lightGray);

    _scene->addItem(_headItem);
    _scene->addItem(_nozzleItem);
    _scene->addItem(_frameItem);
}

void FirstUfo::move()
{
    _y--;

    if(_y < -300)
        _y = _scene->height();

    this->draw();
}

void SecondUfo::move()
{
    _y-=2;

    if(_y < -300)
        _y = _scene->height();

    this->draw();
}

void FirstRocket::draw(){
    QPolygon head;
    head << QPoint(_x - 50, _y) << QPoint(_x, _y - 100) << QPoint(_x + 50, _y);
    _headItem = new QGraphicsPolygonItem(head);
    _headItem->setBrush(Qt::darkGray);
    _scene->addItem(_headItem);

    QRect frame(_x - 50,_y,100,200);
    _frameItem = new QGraphicsRectItem(frame);
    _frameItem->setBrush(Qt::lightGray);
    _scene->addItem(_frameItem);

    QRectF iluminator(_x-25, _y + 50 ,50 ,50);
    auto iluminatorItem = new QGraphicsEllipseItem(iluminator);
    iluminatorItem->setBrush(Qt::blue);
    _scene->addItem(iluminatorItem);

    QPolygon nozzle;
    nozzle << QPoint(_x - 50, _y + 150) << QPoint(_x - 75, _y + 225) << QPoint(_x + 75, _y + 225) << QPoint(_x + 50 ,_y + 150);
    _nozzleItem = new QGraphicsPolygonItem(nozzle);
    _nozzleItem->setBrush(Qt::darkGray);
    _scene->addItem(_nozzleItem);


}

void SecondRocket::draw(){
    QPolygon head;
    head << QPoint(_x - 50, _y) << QPoint(_x, _y - 100) << QPoint(_x + 50, _y);
    _headItem = new QGraphicsPolygonItem(head);
    _headItem->setBrush(Qt::lightGray);
    _scene->addItem(_headItem);

    QRect frame(_x - 50,_y,100,200);
    _frameItem = new QGraphicsRectItem(frame);
    _frameItem->setBrush(Qt::black);
    _scene->addItem(_frameItem);

    QRectF iluminator(_x-25, _y + 50 ,50 ,50);
    auto iluminatorItem = new QGraphicsEllipseItem(iluminator);
    iluminatorItem->setBrush(Qt::yellow);
    _scene->addItem(iluminatorItem);

    QPolygon nozzle;
    nozzle << QPoint(_x - 50, _y + 150) << QPoint(_x - 75, _y + 225) << QPoint(_x + 75, _y + 225) << QPoint(_x + 50 ,_y + 150);
    _nozzleItem = new QGraphicsPolygonItem(nozzle);
    _nozzleItem->setBrush(Qt::lightGray);
    _scene->addItem(_nozzleItem);


}
void FirstRocket::move(){
    _y--;

    if(_y < -300)
        _y = _scene->height();

    QRectF flame(_x - 40,_y + 150, 80, 150);
    _flameItem = new QGraphicsEllipseItem(flame);
    _flameItem->setBrush(Qt::red);
    _scene->addItem(_flameItem);

    flame = QRectF(_x - 25,_y + 175, 50, QRandomGenerator::global()->bounded(75,100));
    _flameItem = new QGraphicsEllipseItem(flame);
    _flameItem->setBrush(Qt::yellow);
    _scene->addItem(_flameItem);

    this->draw();
}

void SecondRocket::move(){
    _y-=2;

    if(_y < -300)
        _y = _scene->height();

    QRectF flame(_x - 40,_y + 150, 80, 150);
    _flameItem = new QGraphicsEllipseItem(flame);
    _flameItem->setBrush(Qt::red);
    _scene->addItem(_flameItem);

    flame = QRectF(_x - 25,_y + 175, 50, QRandomGenerator::global()->bounded(75,100));
    _flameItem = new QGraphicsEllipseItem(flame);
    _flameItem->setBrush(Qt::yellow);
    _scene->addItem(_flameItem);

    this->draw();
}
