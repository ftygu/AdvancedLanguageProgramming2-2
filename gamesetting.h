#ifndef GAMESETTING_H
#define GAMESETTING_H
#include "player.h"
#include"plate.h"
#include"weapon.h"
class GameSetting
{
public:
    GameSetting();
    int players_keybindings [4][6]; 
    Plate *plates;
    Player *players;
    Bullet *player1_bullets, *player2_bullets, *player3_bullets, *player4_bullets;
    Weapon *player1_weapen, *player2_weapen, *player3_weapen, *player4_weapen;
    int plates_num,players_num;
    void load_plate_test();
};

#endif // GAMESETTING_H
