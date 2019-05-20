#include "body.h"
#include <QBrush>


void Body::SetCoordinates(Vector r){
    x = r.x;
    y = r.y;
    setPos(x - 10, y - 10);
}


void Body::SetSpeed(Vector v){
    v_x = v.x;
    v_y = v.y;
}


Vector Body::GetCoordinates(){
    Vector v;
    v.x = x;
    v.y = y;
    return v;
}


Vector Body::GetSpeed(){
    Vector v;
    v.x = v_x;
    v.y = v_y;
    return v;
}


Body::Body(double x1, double y1, double v1_1, double v2_1, double m1, QColor c){
    x = x1;
    y = y1;
    v_x = v1_1;
    v_y = v2_1;
    m = m1;
    color = c;
    setPos(x - 10, y - 10);
    setRect(0,0,20,20);
    setBrush(QBrush(c));
    setFlag(QGraphicsItem::ItemIsMovable);
}


double Body::mass() const{
    return m;
}


Vector GravForce (Body& b1, Body& b2){
    Vector r12;
    r12 = b2.GetCoordinates() - b1.GetCoordinates();
    Vector F21;
    F21.x = b1.mass() * b2.mass() * r12.x / (r12.Length()*r12.Length()*r12.Length());
    F21.y = b1.mass() * b2.mass() * r12.y / (r12.Length()*r12.Length()*r12.Length());
    return F21;
}

void Movement(Vector& R, Body& b){
    if(b.collidingItems().size() == 0){
        Vector v, v_0, dv;
        v_0 = b.GetSpeed();
        dv = (1.0/b.mass()) * R;
        v = v_0 + dv;
        Vector r, r_0, dr;
        r_0 = b.GetCoordinates();
        dr = v;
        r = r_0 + dr;
        b.SetSpeed(v);
        b.SetCoordinates(r);
        return;
    }
}
