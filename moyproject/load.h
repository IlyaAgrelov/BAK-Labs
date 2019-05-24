#ifndef LOAD_H
#define LOAD_H

#include <QGraphicsRectItem>

class Load: public QGraphicsRectItem{

public:
    Load();
    bool fixed1;
    bool fixed2;
    //double getm();

private:
    //double m;
    int type() const;
};



#endif // LOAD_H
