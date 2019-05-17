#include "dialog2.h"
#include "ui_dialog2.h"
#include <QMessageBox>
#include <QDebug>

dialog2::dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog2)
{
    ui->setupUi(this);
    ui->line1m->setText("100");
    ui->line2m->setText("100");
    ui->line3m->setText("100");
    ui->line1x->setText("100");
    ui->line2x->setText("200");
    ui->line3x->setText("300");
    ui->line1y->setText("100");
    ui->line2y->setText("200");
    ui->line3y->setText("300");
    ui->line1Vx->setText("0");
    ui->line2Vx->setText("0");
    ui->line3Vx->setText("0");
    ui->line1Vy->setText("0");
    ui->line2Vy->setText("0");
    ui->line3Vy->setText("0");
}

dialog2::~dialog2()
{
    delete ui;
}

std::vector<double> dialog2::getmass(){
    return mass;
}

std::vector<double> dialog2::getcoordx(){
    return coordx;
}

std::vector<double> dialog2::getcoordy(){
    return coordy;
}

std::vector<double> dialog2::getspeedx(){
    return speedx;
}

std::vector<double> dialog2::getspeedy(){
    return speedy;
}


void dialog2::on_buttonBox_accepted()
{
    if(ui->line1m->text() == "" or ui->line2m->text() == "" or ui->line3m->text() == ""
            or ui->line1x->text() == "" or ui->line2x->text() == "" or ui->line3x->text() == ""
            or ui->line1y->text() == "" or ui->line2y->text() == "" or ui->line3y->text() == ""
            or ui->line1Vx->text() == "" or ui->line2Vx->text() == "" or ui->line3Vx->text() == ""
            or ui->line1Vy->text() == "" or ui->line2Vy->text() == "" or ui->line3Vy->text() == ""){
        QMessageBox* message = new QMessageBox(this);
        message->setText("Введите значения");
        message->show();
    } else {
        mass = {ui->line1m->text().toDouble(), ui->line2m->text().toDouble(), ui->line3m->text().toDouble()};
        coordx = {ui->line1x->text().toDouble(), ui->line2x->text().toDouble(), ui->line3x->text().toDouble()};
        coordy = {ui->line1y->text().toDouble(), ui->line2y->text().toDouble(), ui->line3y->text().toDouble()};
        speedx = {ui->line1Vx->text().toDouble(), ui->line2Vx->text().toDouble(), ui->line3Vx->text().toDouble()};
        speedy = {ui->line1Vy->text().toDouble(), ui->line2Vy->text().toDouble(), ui->line3Vy->text().toDouble()};
        this->accept();
    }
}

void dialog2::on_buttonBox_rejected()
{
    this->close();
}
