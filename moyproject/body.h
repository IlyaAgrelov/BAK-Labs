#ifndef BODY_H
#define BODY_H

#include <QColor>
#include "vector.h"
#include <QGraphicsItem>
#include <QObject>


class Body : public QGraphicsEllipseItem {
public:
    void SetCoordinates(Vector r);
    void SetSpeed(Vector v);// установка скорости
    Vector GetCoordinates();
    Vector GetSpeed();
    Body(double x1, double y1, double v1_1, double v2_1, double m1, QColor col);// конструктор
    double mass() const;// получить массу
private:
    double x; // координаты
    double y;
    double m; // масса
    double v_x; // скорости
    double v_y;
    QColor color; // цвет на изображении
};//тело

Vector GravForce (Body& b1, Body& b2);//

void Movement(Vector& R, Body& b);



#endif // BODY_H
