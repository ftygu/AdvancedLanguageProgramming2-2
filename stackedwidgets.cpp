#include "stackedwidgets.h"
#include"game.h"
#include"QGraphicsView"
StackedWidgets::StackedWidgets():
    game_setting(),
    game(&game_setting,this),
    mui(this),sti(this,&this->game_setting),gpi(this)
{
    this->addWidget(&this->mui);
    this->addWidget(&this->sti);
    this->addWidget(&this->gpi);
    this->addWidget(&game.view);
    this->setFixedSize(1920,1080);
    setWindowFlags(Qt::FramelessWindowHint);
    this->setCurrentIndex(0);
}
