#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include "load.h"
#include "dialog.h"
#include <iostream>
#include <string>

#include <set>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setInteractive(true);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    timer = new QTimer();
    amount = 0;
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing | QPainter::SmoothPixmapTransform);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_clicked() //движение
{
    timer -> stop();
    springs[0]->fix(500, 500);
    //points[0]->hook(springs[0]);
    for(Point* point: points) {
        if(scene->items().size() != 0)
        {
            connect(timer, SIGNAL(timeout()), point, SLOT(move()));
            timer->start(0);

       }
    }

}



void Widget::on_pushButton_2_clicked() //отрисовка
{
    Dialog* dialog = new Dialog();
    if(dialog->exec() == 1){
        scene->setSceneRect(0,0,ui->graphicsView->rect().width(), ui->graphicsView->rect().height());
        Spring *object = new Spring(dialog->text1.toDouble(), dialog->text2.toDouble());
        springs.push_back(object);
        scene->addItem(object);
        object->setPos(100*amount, 0);
        amount++;
        Point *load1 = new Point(0.2, 500, 500, 0, 0);
        Point *load2 = new Point(0.2, 500, 500, 0, 0);
        load1->springs.push_back(object);
        points.push_back(load1);
        points.push_back(load2);
        scene->addItem(load1);
        scene->addItem(load2);
        load1->setPos(500,500);
        load2->setPos(400,400);
        ui->graphicsView->update();
    }
}



void Widget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::RightButton){
        qDebug() << event->x() << ' ' << event->y();
    }
}




