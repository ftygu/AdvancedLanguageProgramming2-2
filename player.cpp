#include "player.h"
#include<QPainter>
#include<QKeyEvent>
Player::Player() :
    width(20),height(20),position(20,20)
{
    is_apperaed = false;
    for(int i = 0; i < 6; i++){
        key_pressed[i] = false;
    }
}

QRectF Player::boundingRect() const
{
    return QRectF(this->position.x(),this->position.y(),this->height,this->width);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);
    painter->setBrush(Qt::red);
    painter->drawRect(position.x(), position.y(), width, height);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    for(int i = 0; i < 6; i++){
        if(keybindings[i] == event->key())
            key_pressed[i] = true;
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    for(int i = 0; i < 6; i++){
        if(keybindings[i] == event->key())
            key_pressed[i] = false;
    }
}

void Player::update_game()
{
    ax = 0;
    ay = 0;

    if(key_pressed[0] == true){
        ay -= 20;
    }
    if(key_pressed[1] == true){
        ay += 20;
    }
    if(key_pressed[2] == true){
        ax -= 5;
    }
    if(key_pressed[3] == true){
        ax += 5;
    }
    if(key_pressed[4] == true){

    }
    if(key_pressed[5] == true){

    }
    vx += ax;
    vy += ay;

    // 限制速度
    vx = std::max(std::min(vx, 10), -10);
    vy = std::max(std::min(vy, 20), -20);

    vx *= 0.9;
    vy *= 0.99;

    position.setX(position.x()+vx);
    position.setY(position.y()+vy);
}
