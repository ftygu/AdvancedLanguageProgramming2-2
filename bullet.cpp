#include "bullet.h"
#include<QPainter>
#include<QtDebug>
Bullet::Bullet()
{
    is_appear = false;
    vx = 0;
    x = 0;
    y = 0;
    height = 3;
    width = 10;
    bullet_impact_force = 4;
}

void Bullet::update()
{
    if(is_appear){
        x += vx;
        position.setX(x);
        position.setY(y);
        if(x >= 1440 || x <= -1440){
            is_appear = false;
        }
    }
}

QRectF Bullet::boundingRect() const
{
    return QRectF(this->position.x(),this->position.y(),this->height,this->width);
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);
    painter->setBrush(Qt::red);
    if(is_appear){
        painter->drawRect(position.x(), position.y(), width, height);
    }
}
