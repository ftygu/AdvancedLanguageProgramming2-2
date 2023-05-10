#include "stackedwidgets.h"
#include"game.h"
#include"QGraphicsView"
StackedWidgets::StackedWidgets():
    game_setting(),
    game(&game_setting,this),
    mui(this),sti(this,&this->game_setting),gpi(this)
{
    //将所有界面均添加至主界面
    this->addWidget(&this->mui);
    this->addWidget(&this->sti);
    this->addWidget(&this->gpi);
    this->addWidget(&game.view);
    this->setFixedSize(1920,1080);
    setWindowFlags(Qt::FramelessWindowHint);
    //显示主菜单
    this->setCurrentIndex(0);
}
