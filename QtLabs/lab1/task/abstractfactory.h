#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

#include<figures.h>

class AbstractFactory
{
public:
    virtual Rocket *createRocket(const int &x, const int &y,QGraphicsScene *scene) const;
    virtual Ufo *createUfo(const int &x, const int &y,QGraphicsScene *scene) const;
};

class FirstAbstractFactory : public AbstractFactory
{
public:
    Rocket *createRocket(const int &x, const int &y,QGraphicsScene *scene)const override{
        return new FirstRocket(x,y,scene);
    }
    Ufo *createUfo(const int &x, const int &y,QGraphicsScene *scene) const override{
        return new FirstUfo(x,y,scene);
    }
};

class SecondAbstractFactory : public AbstractFactory
{
public:
    Rocket *createRocket(const int &x, const int &y,QGraphicsScene *scene)const override{
        return new SecondRocket(x,y,scene);
    }
    Ufo *createUfo(const int &x, const int &y,QGraphicsScene *scene) const override{
        return new SecondUfo(x,y,scene);
    }
};


#endif // ABSTRACTFACTORY_H
