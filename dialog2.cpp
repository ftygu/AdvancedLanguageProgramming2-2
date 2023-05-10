#include "dialog2.h"
#include "ui_dialog2.h"
#include"weapon.h"
#include"player.h"
Dialog2::Dialog2(Weapon **weapon, Player *player, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    this->weapon = weapon;
    this->player = player;
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    delete *weapon;
    *weapon = new Akm;
    (*weapon)->user = player;
    player->weapen = *weapon;
}

void Dialog2::on_pushButton_2_clicked()
{
    delete *weapon;
    *weapon = new M4;
    (*weapon)->user = player;
    player->weapen = *weapon;
}

void Dialog2::on_pushButton_3_clicked()
{
    delete *weapon;
    *weapon = new Awm;
    (*weapon)->user = player;
    player->weapen = *weapon;
}

void Dialog2::on_pushButton_4_clicked()
{
    delete *weapon;
    *weapon = new Ump45;
    (*weapon)->user = player;
    player->weapen = *weapon;
}

void Dialog2::on_pushButton_5_clicked()
{
    delete *weapon;
    *weapon = new sawed_off;
    (*weapon)->user = player;
    player->weapen = *weapon;
}
