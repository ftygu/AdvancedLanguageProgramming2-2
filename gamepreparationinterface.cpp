#include "gamepreparationinterface.h"
#include "ui_gamepreparationinterface.h"
#include"stackedwidgets.h"
#include"dialog.h"
#include"dialog2.h"
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
        game_setting->players_num++;
        game_setting->players[0].is_apperaed = true;
    }
    else{
        game_setting->players_num--;
        game_setting->players[0].is_apperaed = false;
    }
}

void GamePreparationInterface::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        game_setting->players_num++;
        game_setting->players[1].is_apperaed = true;
    }
    else{
        game_setting->players_num--;
        game_setting->players[1].is_apperaed = false;
    }
}

void GamePreparationInterface::on_checkBox_3_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        game_setting->players_num++;
        game_setting->players[2].is_apperaed = true;
    }
    else{
        game_setting->players_num--;
        game_setting->players[2].is_apperaed = false;
    }
}

void GamePreparationInterface::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked){
        game_setting->players_num++;
        game_setting->players[3].is_apperaed = true;
    }
    else{
        game_setting->players_num--;
        game_setting->players[3].is_apperaed = false;
    }
}

void GamePreparationInterface::on_pushButton_3_clicked()
{
    game_setting->load_plate1();
}

void GamePreparationInterface::on_pushButton_4_clicked()
{
    Dialog dialog(&game_setting->players[0].body_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_5_clicked()
{
    Dialog dialog(&game_setting->players[0].head_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_6_clicked()
{
    Dialog dialog(&game_setting->players[1].body_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_7_clicked()
{
    Dialog dialog(&game_setting->players[1].head_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_8_clicked()
{
    Dialog dialog(&game_setting->players[2].head_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_9_clicked()
{
    Dialog dialog(&game_setting->players[2].body_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_10_clicked()
{
    Dialog dialog(&game_setting->players[3].head_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_11_clicked()
{
    Dialog dialog(&game_setting->players[3].body_color,this);
    dialog.exec();
}

void GamePreparationInterface::on_spinBox_valueChanged(int arg1)
{
    game_setting->lives_num = arg1;
}

void GamePreparationInterface::on_pushButton_12_clicked()
{
    Dialog2 dialog(&game_setting->player1_weapen,&game_setting->players[0],this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_13_clicked()
{
    Dialog2 dialog(&game_setting->player2_weapen,&game_setting->players[1],this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_14_clicked()
{
    Dialog2 dialog(&game_setting->player3_weapen,&game_setting->players[2],this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_15_clicked()
{
    Dialog2 dialog(&game_setting->player4_weapen,&game_setting->players[3],this);
    dialog.exec();
}

void GamePreparationInterface::on_pushButton_16_clicked()
{
    game_setting->load_plate2();
}

void GamePreparationInterface::on_pushButton_17_clicked()
{
    game_setting->load_plate3();
}

void GamePreparationInterface::on_pushButton_18_clicked()
{
    game_setting->load_plate4();
}

void GamePreparationInterface::on_pushButton_19_clicked()
{
    game_setting->load_plate5();
}
