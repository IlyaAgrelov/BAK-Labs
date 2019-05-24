
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
#include <vector.h>
#include <set>


class Spring: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Spring(const double& c, const double& x); //конструктор
    void deform (const double& dx); //деформация
    double length() const; //возвращение текущей длины
    double length0() const; //возвращение начальной длины
    double Stif() const; //возвращение коэффициента жесткости
    void fix(const double& i, const double& j); //фиксация пружины
    bool load(const double& m, const Vector& v); //загрузка пружины???
    void move(const Vector& dr);
    Vector force();
    void fixate(QGraphicsItem* item, int i); //фиксация груза
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void rotation(double a);
    QGraphicsItem* item1;
    QGraphicsItem* item2;
    bool fixed1;
    bool fixed2;
    bool coll();
public slots:
    //void move(); //движение пружинки

private:
    double k; //Жесткость пружины
    double lo, l; // длина и начальная длина
    Vector p, r;
    double m1, m2; //массы грузов
    bool fixed;

    double scaley; //масштаб по y
    double scalex; //масштаб по x
    QGraphicsRectItem* fixator1;
    QGraphicsRectItem* fixator2;
    int angle;
    std::set<QGraphicsItem*>* s;
};



#endif // MYOBJECT_H
