#include "dialog1.h"
#include "ui_dialog1.h"
#include"game.h"
#include"stackedwidgets.h"
Dialog1::Dialog1(Game *game, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    this->game = game;
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_pushButton_clicked()
{
    game->continue_game();
    this->hide();
}

void Dialog1::on_pushButton_2_clicked()
{
    game->stop();
    game->stackedwidgets->setCurrentIndex(0);
    this->hide();
}
