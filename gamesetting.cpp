#include "gamesetting.h"
#include<QKeyEvent>
#include"plate.h"
#include"bullet.h"
#include<QtDebug>
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
        player1_bullets = new Bullet[100];
        player2_bullets = new Bullet[100];
        player3_bullets = new Bullet[100];
        player4_bullets = new Bullet[100];
        players[0].bullets = player1_bullets;
        players[1].bullets = player2_bullets;
        players[2].bullets = player3_bullets;
        players[3].bullets = player4_bullets;
        player1_weapen.user = &players[0];
        player2_weapen.user = &players[1];
        player3_weapen.user = &players[2];
        player4_weapen.user = &players[3];
        players[0].weapen = &player1_weapen;
        players[1].weapen = &player2_weapen;
        players[2].weapen = &player3_weapen;
        players[3].weapen = &player4_weapen;
        for(int i = 0; i < 4; i++){
            players[i].weapen->load_akm();
        }
}

void GameSetting::load_plate_test()
{
    plates_num = 5;

        plates[0].position.setX(-890);
        plates[0].position.setY(-200);
        plates[0].width = 285;
        plates[0].height = 100;
        plates[0].pixture.load("://resource/cloud_1.png");
        plates[0].pix_width = 0;
        plates[0].pix_height = 70;

        plates[1].position.setX(-166);
        plates[1].position.setY(-200);
        plates[1].width = 285;
        plates[1].height = 100;
        plates[1].pixture.load("://resource/cloud_1.png");
        plates[1].pix_width = 0;
        plates[1].pix_height = 70;

        plates[2].position.setX(563);
        plates[2].position.setY(-200);
        plates[2].width = 285;
        plates[2].height = 100;
        plates[2].pixture.load("://resource/cloud_1.png");
        plates[2].pix_width = 0;
        plates[2].pix_height = 70;

        plates[3].position.setX(-563);
        plates[3].position.setY(0);
        plates[3].width = 285;
        plates[3].height = 100;
        plates[3].pixture.load("://resource/cloud_1.png");
        plates[3].pix_width = 0;
        plates[3].pix_height = 70;

        plates[4].position.setX(166);
        plates[4].position.setY(0);
        plates[4].width = 285;
        plates[4].height = 100;
        plates[4].pixture.load("://resource/cloud_1.png");
        plates[4].pix_width = 0;
        plates[4].pix_height = 70;
}
