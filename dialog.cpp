#include "dialog.h"
#include "ui_dialog.h"
#include"player.h"
Dialog::Dialog(QColor *color, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->color = color;
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    color->setRgb(219,107,92);
}

void Dialog::on_pushButton_5_clicked()
{
    color->setRgb(242,180,118);
}

void Dialog::on_pushButton_7_clicked()
{
    color->setRgb(240,215,148);
}

void Dialog::on_pushButton_3_clicked()
{
    color->setRgb(104,149,129);
}

void Dialog::on_pushButton_4_clicked()
{
    color->setRgb(105,140,192);
}

void Dialog::on_pushButton_8_clicked()
{
    color->setRgb(47,111,168);
}

void Dialog::on_pushButton_2_clicked()
{
    color->setRgb(96,45,143);
}

void Dialog::on_pushButton_6_clicked()
{
    color->setRgb(20,20,20);
}

void Dialog::on_pushButton_9_clicked()
{
    color->setRgb(200,200,200);
}
