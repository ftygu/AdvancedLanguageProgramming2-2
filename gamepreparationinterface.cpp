#include "gamepreparationinterface.h"
#include "ui_gamepreparationinterface.h"
#include"stackedwidgets.h"
GamePreparationInterface::GamePreparationInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePreparationInterface)
{
    stacked_widgets = static_cast<StackedWidgets*>(parent);
    ui->setupUi(this);
}

GamePreparationInterface::~GamePreparationInterface()
{
    delete ui;
}

void GamePreparationInterface::on_pushButton_clicked()
{
    stacked_widgets->setCurrentIndex(3);
    stacked_widgets->game.start();
    stacked_widgets->game.scene.setFocus();
}

void GamePreparationInterface::on_pushButton_2_clicked()
{
    stacked_widgets->setCurrentIndex(0);
}
