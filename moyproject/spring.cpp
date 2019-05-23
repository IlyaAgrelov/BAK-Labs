#include "spring.h"
#include <QTimer>
#include <QDebug>
#include <QTransform>
#include "widget.h"
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <cmath>
#include <math.h>
#include "point.h"



Spring::Spring(const double& c, const double& x){
        setPixmap(QPixmap(":/images/spring.png"));
        k = c;
        lo = x;
        l = x;
        m1 = 0;
        m2 = 0;
        p.x = 400;
        p.y = 400;
        r.y = p.y + l;
        r.x = p.x;
        angle = 0;
        item1 = nullptr;
        item2 = nullptr;
        fixed = false;
        fixed1 = false;
        fixed2 = false;
        scaley = x/512;
        scalex = 0.25;
        fixator1 = new QGraphicsRectItem(this);
        fixator1->setRect(0,0,10/scalex,10/scaley);
        fixator1->setBrush(Qt::red);
        fixator1->setPos(240,480);
        fixator2 = new QGraphicsRectItem(this);
        fixator2->setRect(0,0,10/scalex,10/scaley);
        fixator2->setBrush(Qt::red);
        fixator2->setPos(240,5 - 30*scaley);
        setTransform(QTransform().scale(scalex,scaley));
        setFlag(QGraphicsItem::ItemIsMovable);
        //connect(timer,SIGNAL(timeout()),this,SLOT(()));
}


double Spring::length() const {
    return l;
}


double Spring::length0() const {
     return lo;
}


double Spring::Stif() const{
     return k;
}


void Spring::deform(const double &dx){
       // l += dx;
        scaley += (16 * dx);
        setTransformationMode(Qt::SmoothTransformation);
        setTransform(QTransform().scale(scalex,scaley));
        fixator1->setRect(0,0,10/scalex,10/scaley);
        fixator2->setRect(0,0,10/scalex,10/scaley);
        fixator2->setPos(240,-5 + 45*scaley);
}


void Spring::fix(const double &i, const double &j){
        Vector v(i, j);
        p = v;
        fixed1 = true;
}


bool Spring :: load(const double& m, const Vector& v) {
    if (m1 == 0.0) {
      m1 = m;
      r = v;
      r.x = p.x;
      r.y = p.y + l;
      return true;
    } else if(m2 == 0.0 && fixed == false) {
        p = v;
        r.x = p.x;
        r.y = p.y - l;
        m2 = m;
        return true;
    }
    return false;
}


Vector Spring :: force() {
    Vector f(p.x - r.x, p.y - r.y);
    f = (k * (l - lo) / l) * f;
    return f;
}


bool Spring::coll(){
    if(fixator1->collidingItems().size() !=0 and not fixed1){
        for(QGraphicsItem* j : fixator1->collidingItems()){
            if(j != this){
                fixate(j,1);
                fixed1 = true;
                item1 = j;
            }
        }
        return true;
    } else if(fixed1){
        fixate(item1,1);
    } if(this->fixator2->collidingItems().size() !=0 and not fixed2){
        for(QGraphicsItem* j : fixator2->collidingItems()){
            if(j != this){
                fixate(j,2);
                fixed2 = true;
                item2 = j;
            }
        }
        return true;
    } else if(fixed2){
        fixate(item2,2);
    }
    return false;
}


void Spring::fixate(QGraphicsItem *item, int i){
    if(i == 1){
        item->setPos(this->x()+39,this->y()+(512 - 40)*scaley);
        item->setFlag(QGraphicsItem::ItemIsMovable,false);
    } else if (i == 2){
        this->setPos(item->x()-39,item->y() + 45 - (30*scaley));
        this->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
}


void Spring::rotation(double a){
        double sina = sin(a);
        double cosa = cos(a);
        QTransform rotationTransform(cosa, sina, -sina, cosa, 0, 0);
        QTransform scalingTransform(scalex, 0, 0, scaley, 0, 0);
        //QTransform translationTransform(1, 0, 1, 0, -256, -256);
        QTransform transform = rotationTransform *  scalingTransform;
        setTransform(transform);
}


void Spring::mousePressEvent(QGraphicsSceneMouseEvent* event){
    if(event->button() == Qt::RightButton){
        rotation(45);
        //qDebug() << cos(angle*M_PI/180) << sin(angle*M_PI/180);
    }
}


void Spring::move(const Vector& v) {
        r = r + v;
        l = sqrt((p.x - r.x) * (p.x - r.x) + (p.y - r.y) * (p.y - r.y));
    }
