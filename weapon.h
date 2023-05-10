#ifndef WEAPON_H
#define WEAPON_H
#include "bullet.h"
class Weapon
{
public:
    Weapon();
    int bullet_num;
    int bullet_speed;
    int bullet_impact_force;
    int bullet_width,bullet_height;
    int shooting_interval;
    int reload_time;
};

class TheGun : public Weapon{
    TheGun();
};

#endif // WEAPON_H
