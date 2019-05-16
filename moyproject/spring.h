#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <iostream>
#include <vector>
#include <cmath>
#include <QMouseEvent>

class Spring: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spring(const double& c, const double& x); //конструктор

    void deform (const double& dx); //деформация

    double length() const; //возвращение текущей длины

    double length0() const; //возвращение начальной длины

    double Stif() const; //возвращение коэффициента жесткости

    void fix(const double& i, const double& j); //фиксация пружины

    bool load(const double& m); //загрузка пружины???

    void fixate(QGraphicsItem* item, int i); //фиксация груза

    void mousePressEvent(QGraphicsSceneMouseEvent* event);

public slots:
    void move(); //движение пружинки
    void col();

private:
    double k; //Жесткость пружины
    double lo, l; // длина и начальная длина
    double x1, y1; //Координаты подвеса
    double m1, m2; //массы грузов
    bool fixed1;
    bool fixed2;
    double scaley; //масштаб по y
    double scalex; //масштаб по x
    QGraphicsItem* item1;
    QGraphicsItem* item2;
    QGraphicsRectItem* fixator1;
    QGraphicsRectItem* fixator2;
    int angle;

    void rotation(int angle);
};



#endif // MYOBJECT_H