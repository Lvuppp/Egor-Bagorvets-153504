#include "figure.h"
Triangle::Triangle(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle){
    _x = x;
    _y = y;
    _scene = scene;
    _scale = scale;
    _angle = angle;

}

void Triangle::createFigure(){
    QPolygon triangle;
    triangle << QPoint(_x,_y - 25 * _scale) << QPoint(_x - 25 * _scale,_y + 25 * _scale) << QPoint(_x + 25 * _scale,_y + 25 * _scale);
    _triangleItem = new QGraphicsPolygonItem(triangle);
    _triangleItem->setTransformOriginPoint(_x,_y);
    _triangleItem->setRotation(_angle);
    _scene->addItem(_triangleItem);
}

double Triangle::square() const
{
    return 50 * _scale * 50 * _scale / 2;
}

double Triangle::perimetr() const
{
    return sqrt(50 * _scale * 50 * _scale + 25 * _scale * 25 * _scale) + 50;
}

QPoint Figure::centerOfMass() const
{
    return QPoint(_x,_y);
}

void Figure::rotate(const int &x, const int &y)
{
    _x = x;
    _y = y;
    this->createFigure();
}

void Figure::turn(const double &angle)
{
    _angle = angle;
    this->createFigure();
}


void Figure::changeScale(const double &scale)
{
    _scale = scale;
    this->createFigure();
}

Rectangle::Rectangle(const int &x, const int &y,QGraphicsScene *scene,const double &scale,const double &angle, const int &exp){
    _x = x;
    _y = y;
    _scene = scene;
    _scale = scale;
    _angle = angle;
    _exp = exp;
}

void Rectangle::createFigure(){
    QRect rectangle(_x - 25 * _exp * _scale,_y - 25 * _scale, 50 * _exp * _scale, 50 * _scale);
    _rectangleItem = new QGraphicsRectItem(rectangle);
    _rectangleItem->setTransformOriginPoint(_x,_y);
    _rectangleItem->setRotation(_angle);
    _scene->addItem(_rectangleItem);
}

double Rectangle::square() const
{
    return 50 * _exp * _scale * 50 * _scale;
}

double Rectangle::perimetr() const
{
    return 50 * _exp * _scale + 50 * _scale;
}

Rhombus::Rhombus(const int &x, const int &y, QGraphicsScene *scene, const double &scale,const double &angle)
{
    _x = x;
    _y = y;
    _scene = scene;
    _scale = scale;
    _angle = angle;
}

void Rhombus::createFigure()
{
    QPolygon rhombus;
    rhombus << QPoint(_x ,_y - 50 * _scale) << QPoint(_x - 25 * _scale,_y ) << QPoint(_x ,_y + 50 * _scale) << QPoint(_x + 25 * _scale ,_y );
    _rhombusItem = new QGraphicsPolygonItem(rhombus);
    _rhombusItem->setTransformOriginPoint(_x,_y);
    _rhombusItem->setRotation(_angle);
    _scene->addItem(_rhombusItem);
}

double Rhombus::square() const
{
    return 50 * _scale * 25 * _scale / 2;
}

double Rhombus::perimetr() const
{
    return 4 *  sqrt(50 * _scale * 50 * _scale + 25 * _scale * 25 * _scale);
}

Ellipse::Ellipse(const int &x, const int &y, QGraphicsScene *scene, const double &scale,const double &angle ,const int &exp){
    _x = x;
    _y = y;
    _scene = scene;
    _scale = scale;
    _angle = angle;
    _exp = exp;
}

void Ellipse::createFigure()
{
    QRectF ellipse(_x - 25 * _exp * _scale, _y - 25 * _scale, 50 * _exp * _scale, 50 * _scale);
    _ellipseItem = new QGraphicsEllipseItem(ellipse);
    _ellipseItem->setTransformOriginPoint(_x,_y);
    _ellipseItem->setRotation(_angle);
    _scene->addItem(_ellipseItem);
}

double Ellipse::square() const
{
    return M_PI *  100 * _scale + 50 * _scale;
}

double Ellipse::perimetr() const
{
    return 2 * M_PI * sqrt((50 * _exp  * _scale* 50 * _exp * _scale + 50 * _scale* 50 * _scale) / 8);
}

Star::Star(const int &x, const int &y, QGraphicsScene *scene, const double &scale, const double &angle, const int &polygons)
{
    _x = x;
    _y = y;
    _scene =scene;
    _scale = scale;
    _angle = angle;
    _polygons = polygons;
}

void Star::createFigure()
{
    QPolygon polygon;
    int radius = 50;
    for(int i = 1; i < _polygons + 1; i++){
        polygon << QPoint(_x + radius * _scale * cos(2 * M_PI * i / _polygons), _y + radius * _scale * sin(2 * M_PI * i / _polygons));
    }
    _starItem = new QGraphicsPolygonItem(polygon);
    _starItem->setTransformOriginPoint(_x,_y);
    _starItem->setRotation(_angle);
    _scene->addItem(_starItem);
}

double Star::square() const
{
    return _polygons * 50 * 50 * _scale * _scale / 2 * sin(M_PI / (2 * _polygons));
}

double Star::perimetr() const
{
    return _polygons * 50 * _scale * 2 * sin(M_PI / _polygons);
}
