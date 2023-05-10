#include "gamesetting.h"
#include<QKeyEvent>
#include"plate.h"
GameSetting::GameSetting() :
    plates_num(0),players_num(0)
{
        players_keybindings[0][0] = Qt::Key_W;
        players_keybindings[0][1] = Qt::Key_S;
        players_keybindings[0][2] = Qt::Key_A;
        players_keybindings[0][3] = Qt::Key_D;
        players_keybindings[0][4] = Qt::Key_F;
        players_keybindings[0][5] = Qt::Key_G;

        players_keybindings[1][0] = Qt::Key_Up;
        players_keybindings[1][1] = Qt::Key_Down;
        players_keybindings[1][2] = Qt::Key_Left;
        players_keybindings[1][3] = Qt::Key_Right;
        players_keybindings[1][4] = 0;
        players_keybindings[1][5] = 0;

        players_keybindings[2][0] = Qt::Key_U;
        players_keybindings[2][1] = Qt::Key_J;
        players_keybindings[2][2] = Qt::Key_H;
        players_keybindings[2][3] = Qt::Key_K;
        players_keybindings[2][4] = Qt::Key_L;
        players_keybindings[2][5] = Qt::Key_Semicolon;

        players_keybindings[3][0] = Qt::Key_Home;
        players_keybindings[3][1] = Qt::Key_End;
        players_keybindings[3][2] = Qt::Key_Delete;
        players_keybindings[3][3] = Qt::Key_PageDown;
        players_keybindings[3][4] = Qt::Key_Slash;
        players_keybindings[3][5] = Qt::Key_Minus;

        players = new Player[4];
        plates = new Plate[20];
}

void GameSetting::load_plate_test()
{
    plates_num = 3;
    plates[0].position.setX(-400);
    plates[0].position.setY(50);
    plates[0].width = 800;
    plates[0].height = 20;
    plates[1].position.setX(-900);
    plates[1].position.setY(150);
    plates[1].width = 1800;
    plates[1].height = 20;
    plates[2].position.setX(-960);
    plates[2].position.setY(250);
    plates[2].width = 1920;
    plates[2].height = 20;
}
