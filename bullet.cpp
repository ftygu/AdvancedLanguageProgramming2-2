#include "bullet.h"
#include<QPainter>
#include<QtDebug>
#include<player.h>
Bullet::Bullet()
{
    is_appear = false;
    is_gravity = false;
    color.setRgb(255,164,0);
}

void Bullet::update()
{
    if(is_appear){
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
            is_appear = false;
        }
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
    is_appear = false;
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
    if(is_appear){
        painter->drawRect(position.x(), position.y(), width, height);
    }
}
