#include "gamepreparationinterface.h"
#include "ui_gamepreparationinterface.h"
#include"stackedwidgets.h"

GamePreparationInterface::GamePreparationInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePreparationInterface)
{
    stacked_widgets = static_cast<StackedWidgets*>(parent);
    game_setting = &stacked_widgets->game_setting;
    ui->setupUi(this);
}

GamePreparationInterface::~GamePreparationInterface()
{
    delete ui;
}
//开始游戏按钮
void GamePreparationInterface::on_pushButton_clicked()
{
    stacked_widgets->setCurrentIndex(3);
    stacked_widgets->game.start();
    stacked_widgets->game.view.setFocus();
}
//返回菜单按钮
void GamePreparationInterface::on_pushButton_2_clicked()
{
    stacked_widgets->setCurrentIndex(0);
}

void GamePreparationInterface::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        game_setting->Players_num++;
        game_setting->players[0].is_apperaed = true;
    }
    else{
        game_setting->Players_num--;
        game_setting->players[0].is_apperaed = false;
    }
}

void GamePreparationInterface::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        game_setting->Players_num++;
        game_setting->players[1].is_apperaed = true;
    }
    else{
        game_setting->Players_num--;
        game_setting->players[1].is_apperaed = false;
    }
}

void GamePreparationInterface::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        game_setting->Players_num++;
        game_setting->players[2].is_apperaed = true;
    }
    else{
        game_setting->Players_num--;
        game_setting->players[2].is_apperaed = false;
    }
}

void GamePreparationInterface::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        game_setting->Players_num++;
        game_setting->players[3].is_apperaed = true;
    }
    else{
        game_setting->Players_num--;
        game_setting->players[3].is_apperaed = false;
    }
}

void GamePreparationInterface::on_pushButton_3_clicked()
{
    game_setting->load_plate_test();
}
