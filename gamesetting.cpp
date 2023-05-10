#include<QKeyEvent>
#include "gamesetting.h"
#include"plate.h"
#include"bullet.h"
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
        player1_weapen = new M4;
        player2_weapen = new Akm;
        player3_weapen = new Akm;
        player4_weapen = new Akm;
        player1_weapen->user = &players[0];
        player2_weapen->user = &players[1];
        player3_weapen->user = &players[2];
        player4_weapen->user = &players[3];
        players[0].weapen = player1_weapen;
        players[1].weapen = player2_weapen;
        players[2].weapen = player3_weapen;
        players[3].weapen = player4_weapen;
        lives_num = 1;
}

void GameSetting::load_plate1()
{
    plates_num = 7;
    background_color.setRgb(30,75,106);
    for(int i = 0; i < 7; i++){
        plates[i].test_mode=false;
    }
        plates[0].position.setX(-900);
        plates[0].position.setY(-300);
        plates[0].width = 575;
        plates[0].height = 200;
        plates[0].pixture.load("://resource/cloud_1.png");
        plates[0].pix_width = 10;
        plates[0].pix_height = 80;
        plates[1].position.setX(-700);
        plates[1].position.setY(-100);
        plates[1].width = 595;
        plates[1].height = 200;
        plates[1].pixture.load("://resource/cloud_2.png");
        plates[1].pix_width = 10;
        plates[1].pix_height = 70;
        plates[2].position.setX(250);
        plates[2].position.setY(-300);
        plates[2].width = 500;
        plates[2].height = 100;
        plates[2].pixture.load("://resource/cloud_3.png");
        plates[2].pix_width = 10;
        plates[2].pix_height = 100;
        plates[3].position.setX(-900);
        plates[3].position.setY(100);
        plates[3].width = 520;
        plates[3].height = 100;
        plates[3].pixture.load("://resource/cloud_4.png");
        plates[3].pix_width = 15;
        plates[3].pix_height = 130;
        plates[4].position.setX(200);
        plates[4].position.setY(100);
        plates[4].width = 520;
        plates[4].height = 100;
        plates[4].pixture.load("://resource/cloud_5.png");
        plates[4].pix_width = 20;
        plates[4].pix_height = 90;
        plates[5].position.setX(-350);
        plates[5].position.setY(250);
        plates[5].width = 660;
        plates[5].height = 100;
        plates[5].pixture.load("://resource/cloud_6.png");
        plates[5].pix_width = 15;
        plates[5].pix_height = 140;
        plates[6].position.setX(166);
        plates[6].position.setY(-100);
        plates[6].width = 595;
        plates[6].height = 100;
        plates[6].pixture.load("://resource/cloud_7.png");
        plates[6].pix_width = 5;
        plates[6].pix_height = 70;
}

void GameSetting::load_plate2()
{
    plates_num = 4;
    background_color.setRgb(255,255,255);
    for(int i = 0; i < 4; i++){
        plates[i].test_mode = true;
        plates[i].position.setX(-900);
        plates[i].position.setY(-300+i*150);
        plates[i].width = 1800;
        plates[i].height = 50;
        plates[i].color.setRgb(134,179,211);
        plates[i].pixture.fill(Qt::transparent);
    }
}

void GameSetting::load_plate3()
{
    plates_num = 4;
    background_color.setRgb(255,255,255);
    for(int i = 0; i < 4; i++){
        plates[i].test_mode = true;
        plates[i].position.setX(-900+i*200);
        plates[i].position.setY(-300+i*150);
        plates[i].width = 1800-i*400;
        plates[i].height = 50;
        plates[i].color.setRgb(141,244,165);
        plates[i].pixture.fill(Qt::transparent);
    }
}

void GameSetting::load_plate4()
{
    plates_num = 4;
    background_color.setRgb(255,255,255);
    for(int i = 0; i < 4; i++){
        plates[i].test_mode = true;
        plates[i].position.setX(-300-i*200);
        plates[i].position.setY(-300+i*150);
        plates[i].width = 600+i*400;
        plates[i].height = 50;
        plates[i].color.setRgb(195,79,206);
        plates[i].pixture.fill(Qt::transparent);
    }
}

void GameSetting::load_plate5()
{
    plates_num = 1;
    background_color.setRgb(255,255,255);
        plates[0].test_mode = true;
        plates[0].position.setX(-900);
        plates[0].position.setY(200);
        plates[0].width = 1800;
        plates[0].height = 50;
        plates[0].color.setRgb(124,117,218);
        plates[0].pixture.fill(Qt::transparent);
}
