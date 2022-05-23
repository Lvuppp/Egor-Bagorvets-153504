#ifndef FIGURES_H
#define FIGURES_H

#include<QGraphicsItem>
#include<QGraphicsView>
#include<QWidget>
#include<QHBoxLayout>
#include<QPoint>
#include<QRandomGenerator>
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QWidget>
#include<QHBoxLayout>
#include<QTimer>
#include<QObject>

class Rocket{
public:
    virtual ~Rocket(){};
    virtual void draw() = 0;
    virtual void move() = 0;

};

class FirstRocket : public Rocket
{
public:
    FirstRocket(const int &x,const int &y,QGraphicsScene *scene);
    void draw() override;
    void move() override;
    ~FirstRocket(){};
private:
    QGraphicsPolygonItem *_headItem;
    QGraphicsRectItem *_frameItem;
    QGraphicsPolygonItem *_nozzleItem;
    QGraphicsEllipseItem *_flameItem;
    QGraphicsScene *_scene;
    QTimer *_timer;
    int _x, _y;
public slots:
    void moveSlot();
};


class SecondRocket : public Rocket
{
public:
    SecondRocket(const int &x,const int &y,QGraphicsScene *scene);
    void draw() override;
    void move() override;
    ~SecondRocket(){};
private:
    QGraphicsPolygonItem *_headItem;
    QGraphicsRectItem *_frameItem;
    QGraphicsPolygonItem *_nozzleItem;
    QGraphicsEllipseItem *_flameItem;
    QGraphicsScene *_scene;
    QTimer *_timer;
    int _x, _y;
};



class Ufo
{
public:
    virtual ~Ufo(){};
    virtual void draw() = 0;
    virtual void move() = 0;
};

class FirstUfo : public Ufo
{
public:
    FirstUfo(const int &x,const int &y,QGraphicsScene *scene);
    void draw() override;
    void move() override;
    ~FirstUfo(){};
private:
    QGraphicsEllipseItem *_headItem;
    QGraphicsEllipseItem *_frameItem;
    QGraphicsEllipseItem *_nozzleItem;
    QGraphicsScene *_scene;
    QTimer *_timer;
    int _x, _y;
};

class SecondUfo : public Ufo
{
public:
    SecondUfo(const int &x,const int &y,QGraphicsScene *scene);
    void draw() override;
    void move() override;
    ~SecondUfo(){};
private:
    QGraphicsEllipseItem *_headItem;
    QGraphicsEllipseItem *_frameItem;
    QGraphicsEllipseItem *_nozzleItem;
    QGraphicsScene *_scene;
    QTimer *_timer;
    int _x, _y;
};
#endif // FIGURES_H
