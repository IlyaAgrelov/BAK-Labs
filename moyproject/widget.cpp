#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QPainter>
#include "spring.h"
#include <QDebug>
#include "load.h"
#include "dialog.h"
#include <iostream>
#include <string>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setInteractive(true);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
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
    QTimer* timer = new QTimer();
    if(scene->items().size() != 0)
    {
        Spring* spring = dynamic_cast<Spring*>(ui->graphicsView->scene()->items().last());
        connect(timer,SIGNAL(timeout()),spring ,SLOT(move()));
        timer->start(50);
   }
}



void Widget::on_pushButton_2_clicked() //отрисовка
{
    Dialog* dialog = new Dialog();
    if(dialog->exec() == 1){
        scene->setSceneRect(0,0,ui->graphicsView->rect().width(),ui->graphicsView->rect().height());
        Spring *object = new Spring(dialog->text1.toDouble(), dialog->text2.toDouble());
        scene->addItem(object);
        object->setPos(100*amount,0);
        amount++;
        Load *load1 = new Load(10);
        Load *load2 = new Load(10);
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





