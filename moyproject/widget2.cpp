#include "widget2.h"
#include "ui_widget2.h"
#include "body.h"
#include <QTimer>
#include <QDebug>
#include "dialog2.h"
#include "vector.h"

Widget2::Widget2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget2)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setRenderHints(QPainter::Antialiasing | QPainter::HighQualityAntialiasing | QPainter::SmoothPixmapTransform);
}

Widget2::~Widget2()
{
    delete ui;
}

void Widget2::move(){
    Vector F21, F31, F23, F32, F12, F13;
    F21 = GravForce(*bodies[0], *bodies[1]);
    F31 = GravForce(*bodies[0], *bodies[2]);
    F32 = GravForce(*bodies[1], *bodies[2]);
    Vector nul(0,0);
    F12 = nul - F21;
    F13 = nul - F31;
    F23 = nul - F32;
    Vector R1, R2, R3; // равнодействующие сил
    R1 = F21 + F31;
    R2 = F12 + F32;
    R3 = F13 + F23;
    Movement(R1, *bodies[0]);
    Movement(R2, *bodies[1]);
    Movement(R3, *bodies[2]);
    //qDebug() << bodies[0]->GetCoordinates().x << bodies[0]->GetCoordinates().y;
    //qDebug() << bodies[1]->GetCoordinates().x << bodies[1]->GetCoordinates().y;
    //qDebug() << bodies[2]->GetCoordinates().x << bodies[2]->GetCoordinates().y;
}

void Widget2::on_pushButton_clicked()
{
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,ui->graphicsView->width(),ui->graphicsView->height());
    dialog2* dialog = new dialog2();
    if (dialog->exec() == 1){
        Body* body1 = new Body(dialog->getcoordx()[0], dialog->getcoordy()[0],
                dialog->getspeedx()[0],dialog->getspeedy()[0],dialog->getmass()[0],Qt::red);
        Body* body2 = new Body(dialog->getcoordx()[1], dialog->getcoordy()[1],
                dialog->getspeedx()[1],dialog->getspeedy()[1],dialog->getmass()[1],Qt::blue);
        Body* body3 = new Body(dialog->getcoordx()[2], dialog->getcoordy()[2],
                dialog->getspeedx()[2],dialog->getspeedy()[2],dialog->getmass()[2],Qt::green);
        bodies.push_back(body1);
        bodies.push_back(body2);
        bodies.push_back(body3);
        scene->addItem(body1);
        scene->addItem(body2);
        scene->addItem(body3);
        ui->graphicsView->update();
        dialog->close();
    }
}

void Widget2::on_pushButton_2_clicked()
{
    QTimer* timer = new QTimer();
    if(scene->items().size() != 0)
    {
        connect(timer,SIGNAL(timeout()),this,SLOT(move()));
        timer->start(50);
   }
    for(auto& i : scene->items()){
        i->setFlag(QGraphicsItem::ItemIsMovable, false);
        Body* body = dynamic_cast<Body*>(i);
        body->SetCoordinates(Vector(i->x() + 10, i->y() + 10));
    }
}

void Widget2::on_pushButton_3_clicked()
{
    for(auto&i : scene->items()){
        if(i->x() > this->width()){
            this -> resize(int(i->x() + 50), this->height());
        }
        if(i->y() > this->ui->graphicsView->height()){
            this -> resize(this->width(), int(i->y() + 150));
        }
    }
}
