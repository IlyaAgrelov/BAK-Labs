#include "load.h"
#include <QBrush>

Load::Load(){
    //m = x;
    setRect(0,0,50,50);
    setFlag(QGraphicsItem::ItemIsMovable);
    setBrush(QBrush(Qt::blue, Qt::SolidPattern));
}

/*double Load::getm(){
    return m;
}*/
