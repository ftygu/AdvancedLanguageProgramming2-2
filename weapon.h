#ifndef WEAPON_H
#define WEAPON_H
#include "bullet.h"
class Player;
class Weapon
{
public:
    Weapon(Player *user);
    Player *user;
    int bullet_num;
    int bullet_speed;
    int bullet_impact_force;
    int bullet_width,bullet_height;
    int shooting_interval;
    int reload_time;
};
#endif // WEAPON_H
