#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>
#include <QGraphicsScene>
#include "body.h"
#include <vector>
#include <QList>
#include "dialog2.h"

namespace Ui {
class Widget2;
}

class Widget2 : public QWidget
{
    Q_OBJECT

public:
    explicit Widget2(QWidget *parent = nullptr);
    ~Widget2();

public slots:
    void move();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Widget2 *ui;
    QGraphicsScene* scene;
    QList<Body*> bodies;
};

#endif // WIDGET2_H
