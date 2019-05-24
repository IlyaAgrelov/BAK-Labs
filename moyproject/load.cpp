#include "load.h"
#include <QBrush>

Load::Load(){
    //m = x;
    setRect(0,0,50,50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setBrush(QBrush(Qt::blue, Qt::SolidPattern));
    bool fixed1 = false;
    bool fixed2 = false;
}

int Load::type()const{
    return UserType+1;
}

/*double Load::getm(){
    return m;
}*/
