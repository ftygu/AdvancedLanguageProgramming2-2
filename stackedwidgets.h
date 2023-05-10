#ifndef STACKEDWIDGETS_H
#define STACKEDWIDGETS_H
#include <QStackedWidget>
#include"gamepreparationinterface.h"
#include"settinginterface.h"
#include"menuinterface.h"
#include"gamesetting.h"
#include"game.h"
class StackedWidgets : public QStackedWidget
{
public:
    //构造函数
    StackedWidgets();
    //成员列表
    //游戏设置
    GameSetting game_setting;
    //游戏画面
    Game game;
    //主菜单
    MenuInterface mui;
    //游戏准备界面
    GamePreparationInterface gpi;
    //设置界面
    SettingInterface sti;

};

#endif // STACKEDWIDGETS_H
