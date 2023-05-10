#include "weapon.h"
#include"player.h"
#include<qpainter.h>
#include<QtDebug>
#include<QString>
Weapon::Weapon()
{

}

void Weapon::update()
{
    if(time_to_shooting > 0){
        time_to_shooting--;
    }
    if(time_to_reloading > 0){
        time_to_reloading--;
    }
    if(existing_bullets_num <= 0){
        time_to_reloading = reloading_time;
        existing_bullets_num = bullet_num;
    }
}

void Weapon::shoot()
{
    if(time_to_shooting == 0 && time_to_reloading == 0){
        for(int i = 0; i < 100; i++){
            if(user->bullets[i].is_appear == false){
                user->bullets[i].x = user->x+user->width;
                user->bullets[i].y = user->y+user->height/2;
                user->bullets[i].vx = bullet_speed*user->face;
                user->bullets[i].vy = 0;
                user->bullets[i].impact_force = bullet_impact_force;
                user->bullets[i].damage = bullet_damage;
                user->bullets[i].width = bullet_width;
                user->bullets[i].height = bullet_height;
                user->bullets[i].existing_time = bullet_existing_time;
                user->bullets[i].is_appear = true;
                user->bullets[i].is_gravity = false;
                time_to_shooting = shooting_interval;
                existing_bullets_num--;
                break;
            }
        }
    }
}

void Weapon::special_shoot()
{

}

void Weapon::paint(QPainter *painter)
{
    painter->save();
    painter->translate(user->position.x()+user->width/2,user->position.y()+user->height/2+user->adjusted_y);
    QString text = QString::number(existing_bullets_num);
    painter->setRenderHint(QPainter::Antialiasing);
    QFont font("Arial", 15);
    painter->setFont(font);
    painter->setPen(Qt::black);
    painter->drawText(0, -user->height*9/10, text);
    text = QString::number(user->remaining_lives);
    painter->setPen(Qt::red);
    painter->drawText(-user->width*11/20, -user->height*9/10, text);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    painter->drawRect(-user->width*11/20,-user->height*17/20,user->width*5/4,user->width/4);
    painter->setBrush(Qt::red);
    painter->drawRect(-user->width*11/20,-user->height*17/20,user->width*5/4*user->health/100,user->width/4);
    painter->scale(user->face,1);
    if(time_to_shooting == 0 && time_to_reloading == 0){
    }
    else{
        if(time_to_reloading != 0){
            painter->rotate((abs(reloading_time/2 - time_to_reloading)-reloading_time/2)*80/reloading_time);
        }
        else{
            painter->rotate((abs(shooting_interval/2 - time_to_shooting)-shooting_interval/2)*20/shooting_interval);
        }
    }
    painter->drawPixmap(-pixture.width()/2+dx,-pixture.height()/2+dy,pixture);
    painter->setBrush(user->body_color);
    painter->drawEllipse(hx1,hy1,user->width/5,user->width/5);
    painter->drawEllipse(hx2,hy2,user->width/5,user->width/5);
    painter->restore();
}

Akm::Akm()
{
    bullet_num = 30;
    bullet_speed = 20;
    bullet_impact_force = 10;
    bullet_damage = 10;
    bullet_existing_time = -1;
    bullet_width = 10;
    bullet_height = 8;
    shooting_interval = 10;
    reloading_time =50;
    time_to_shooting = 0;
    time_to_reloading = 0;
    existing_bullets_num = bullet_num;
    pixture.load("://resource/akm.png");
    dx = 10;
    dy = 10;
    hx1 = -2;
    hy1 = 4;
    hx2 = 16;
    hy2 = 4;
}

void Akm::special_shoot()
{
    if(time_to_shooting == 0 && time_to_reloading == 0){
        for(int i = 0; i < 100; i++){
            if(user->bullets[i].is_appear == false){
                user->bullets[i].x = user->x+user->width;
                user->bullets[i].y = user->y+user->height/2;
                user->bullets[i].vx = bullet_speed*user->face;
                user->bullets[i].vy = existing_bullets_num % 4 - 2;
                user->bullets[i].impact_force = bullet_impact_force;
                user->bullets[i].width = bullet_width;
                user->bullets[i].height = bullet_height;
                user->bullets[i].existing_time = bullet_existing_time;
                user->bullets[i].is_appear = true;
                user->bullets[i].is_gravity = false;
                time_to_shooting = shooting_interval;
                existing_bullets_num--;
                break;
            }
        }
    }
}

M4::M4()
{
    bullet_num = 30;
    bullet_speed = 20;
    bullet_impact_force = 10;
    bullet_damage = 10;
    bullet_existing_time = -1;
    bullet_width = 15;
    bullet_height = 5;
    shooting_interval = 10;
    reloading_time =50;
    time_to_shooting = 0;
    time_to_reloading = 0;
    existing_bullets_num = bullet_num;
    pixture.load("://resource/M4.png");
    dx = 10;
    dy = 12;
    hx1 = 1;
    hy1 = 8;
    hx2 = 17;
    hy2 = 11;
}

void M4::special_shoot()
{
    if(time_to_shooting == 0 && time_to_reloading == 0){
        for(int i = 0; i < 100; i++){
            if(user->bullets[i].is_appear == false){
                user->bullets[i].x = user->x+user->width;
                user->bullets[i].y = user->y+user->height/2;
                user->bullets[i].vx = bullet_speed*user->face/2;
                user->bullets[i].vy = 0;
                user->bullets[i].impact_force = bullet_impact_force;
                user->bullets[i].width = bullet_width;
                user->bullets[i].height = bullet_height*2;
                user->bullets[i].existing_time = bullet_existing_time;
                user->bullets[i].is_appear = true;
                user->bullets[i].is_gravity = true;
                time_to_shooting = shooting_interval * 3;
                existing_bullets_num -= 5;
                break;
            }
        }
    }
}
