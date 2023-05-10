#ifndef GAMESETTING_H
#define GAMESETTING_H
#include "player.h"
#include"plate.h"
class GameSetting
{
public:
    GameSetting();
    int players_keybindings [4][6]; 
    Plate *plates;
    Player *players;
    int plates_num,players_num;
};

#endif // GAMESETTING_H
