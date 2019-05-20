#include "widget.h"
#include "ui_dialog.h"
#include <QGraphicsScene>
#include <QPainter>
#include "spring.h"
#include <QDebug>
#include "load.h"
#include "dialog.h"
#include <QString>
#include <QMessageBox>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog(){
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    if(ui->lineEdit->text() == "" or ui->lineEdit_2->text() == "" or ui->lineEdit_3->text() == ""){
        QMessageBox* message = new QMessageBox(this);
        message->setText("Введите значения");
        message->show();
    } else {
        text1 = ui->lineEdit->text();
        text2 = ui->lineEdit_2->text();
        this->accept();
    }
}

void Dialog::on_buttonBox_rejected()
{
    this->close();
}


