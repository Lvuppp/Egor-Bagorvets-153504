#ifndef FIGURE_H
#define FIGURE_H

#include<QGraphicsView>
#include<QGraphicsItem>
#include<QtMath>

class Figure
{
public:
    virtual void createFigure() = 0;
    virtual double square() const = 0;
    virtual double perimetr() const = 0;
    QPoint centerOfMass() const;

    void rotate(const int &x, const int &y);
    void turn(const double &angle);
    void changeScale(const double &scale);
    virtual ~Figure(){};
protected:
    int _x,_y;
    double _scale,_angle;
    QGraphicsScene *_scene;
};


class Triangle : public Figure
{
public:
    Triangle(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle);
    ~Triangle(){};
    void createFigure() override;
    double square() const override;
    double perimetr() const override;

private:
    QGraphicsPolygonItem *_triangleItem;
};


class Rectangle: public Figure
{
public:
    Rectangle(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle,const int &exp);
    ~Rectangle(){};
    void createFigure() override;
    double square() const override;
    double perimetr() const override;

protected:
    int _exp;
    QGraphicsRectItem *_rectangleItem;
};

class Rhombus: public Figure
{
public:
    Rhombus(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle);
    ~Rhombus(){};
    void createFigure() override;
    double square() const override;
    double perimetr() const override;

private:
    QGraphicsPolygonItem *_rhombusItem;
};

class Square : public Rectangle
{
public:
    Square(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle) : Rectangle(x,y,scene,scale,angle,1)
    {};
};


class Ellipse : public Figure
{
public:
    Ellipse(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle, const int &exp) ;
    ~Ellipse(){};
    void createFigure() override;
    double square() const override;
    double perimetr() const override;

protected:
    int _exp = 2;
    QGraphicsEllipseItem *_ellipseItem;
};

class Circle : public Ellipse{
public:
    Circle(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle) : Ellipse(x,y,scene,scale,angle,1)
    {};
};

class Star :public Figure{
public:
    Star(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle,const int &polygons);
    void createFigure() override;
    double square() const override;
    double perimetr() const override;

protected:
    QGraphicsPolygonItem *_starItem;
    int _polygons;
};

class SixFigureedStar : public Star{
public:
    SixFigureedStar(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle):Star(x,y,scene,scale,angle,6){

    };
};


class EightFigureedStar : public Star{
public:
    EightFigureedStar(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle):Star(x,y,scene,scale,angle,8){

    };
};


class NFigureedStar : public Star{
public:
    NFigureedStar(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle, const int &polygons):Star(x,y,scene,scale,angle,polygons){

    };
};


class YourFigure : public Figure{

};

#endif // FIGURE_H
