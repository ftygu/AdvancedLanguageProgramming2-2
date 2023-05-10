#ifndef WEAPON_H
#define WEAPON_H
#include "bullet.h"
class Player;
class Weapon
{
public:
    Weapon();
    void update();
    void shoot();
    void special_shoot();
    void load_akm();
    void paint(QPainter *painter);
    QPixmap pixture;
    Player *user;
    int bullet_num;
    int bullet_speed;
    int bullet_impact_force;
    int bullet_existing_time;
    int bullet_width,bullet_height;
    int shooting_interval;
    int time_to_shooting;
    int reloading_time;
    int time_to_reloading;
    int existing_bullets_num;
    int dx,dy;
    int hx1,hx2,hy1,hy2;
};
#endif // WEAPON_H
