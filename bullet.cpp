#include "bullet.h"
#include<QPainter>
#include<QtDebug>
#include<player.h>
Bullet::Bullet()
{
    is_appear = false;
    is_gravity = false;
    is_existing = false;
    is_hitting = false;
    color.setRgb(255,164,0);
    hit.load(":/resource/hit.png");
    setZValue(2);
}

void Bullet::update()
{
    if(is_existing){
        if(is_gravity == true){
            vy += 0.06;
        }
        x += vx;
        y += vy;
        position.setX(x);
        position.setY(y);
        if(existing_time > 0){
            existing_time--;
        }
        if(x >= 1440 || x <= -1440 || existing_time == 0){
            is_existing = false;
        }
    }
    else{
        if(is_hitting){
            hitting_counter++;
            if(hitting_counter >= 15){
                is_hitting = false;
                hitting_counter = 0;
            }
        }
    }
    if(is_existing == false && is_hitting == false){
        is_appear = false;
    }
    else{
        is_appear = true;
    }
}

void Bullet::action(Player *player)
{
    if(vx > 0)
    player->ax += impact_force;
    else{
    player->ax -= impact_force;
    }
    player->health -= damage;
    is_existing = false;
    is_hitting = true;
    player->sound3.play();
}

QRectF Bullet::boundingRect() const
{
    return QRectF(this->position.x(),this->position.y(),this->height,this->width);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);
    painter->setBrush(color);
    if(is_existing){
        painter->drawRect(position.x(), position.y(), width, height);
    }
    if(is_hitting){
        painter->drawPixmap(position.x(),position.y(),hit);
    }
}
