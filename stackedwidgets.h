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
    StackedWidgets();
    GameSetting game_setting;
    Game game;
    MenuInterface mui;
    GamePreparationInterface gpi;
    SettingInterface sti;
};

#endif // STACKEDWIDGETS_H
