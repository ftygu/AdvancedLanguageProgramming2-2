#ifndef WEAPON_H
#define WEAPON_H
#include "bullet.h"
class Player;
class Weapon
{
public:
    Weapon();
    QPixmap pixture;
    QPixmap fire;
    Player *user;
    int bullet_num;
    int bullet_speed;
    int bullet_impact_force;
    int bullet_damage;
    int bullet_existing_time;
    int bullet_width,bullet_height;
    int shooting_interval;
    int time_to_shooting;
    int reloading_time;
    int time_to_reloading;
    int existing_bullets_num;
    int dx,dy;
    int hx1,hx2,hy1,hy2,fx,fy;
    void update();
    void shoot();
    virtual void special_shoot();
    void paint(QPainter *painter);
};
class Akm : public Weapon{
public:
    Akm();
    void special_shoot() override;
};
class M4 : public Weapon{
public:
    M4();
    void special_shoot() override;
};
class Awm : public Weapon{
public:
    Awm();
    void special_shoot() override;
};
class Ump45 : public Weapon{
public:
    Ump45();
    void special_shoot() override;
};
class sawed_off : public Weapon{
public:
    sawed_off();
    void special_shoot() override;
};
#endif // WEAPON_H
