#include "player.h"
#include<QPainter>
#include<QKeyEvent>
#include<plate.h>
#include<algorithm>
#include<QDebug>
Player::Player() :
    width(20),height(20),position(0,0)
{
    is_apperaed = false;
    for(int i = 0; i < 6; i++){
        key_pressed[i] = false;
    }
    max_junp_time = 2;
    have_jumped = false;
    want_down = false;
    want_down_counter = 0;
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
    //沿x轴移动的计算
    if (key_pressed[2] == true) {
        ax -= 0.5f;
    }
    if (key_pressed[3] == true) {
        ax += 0.5f;
    }
    if (key_pressed[3] == false && key_pressed[2] == false) {
        if (vx > 0.0f) {
            ax -= 0.3f;
        }
        if (vx < 0.0f) {
            ax += 0.3f;
        }
    }
    vx += ax;

    if (vx > -0.2f && vx < 0.2f) {
        vx = 0;
    }
    vx = std::min(std::max(vx, -8.0f), 8.0f);
    x += vx;
    position.setX(x);
    ax = 0.0f;

    //沿y轴移动的计算
    //判断是否在地面上
    if(want_down_counter >= 15){
        want_down = false;
        want_down_counter = 0;
    }
    else{
        if(want_down == true){
            want_down_counter++;
        }
    }
    if(key_pressed[1] == true){
        want_down = true;
    }
    on_ground = 0;
    for (int i = 0; i < plates_num; i++) {
        qDebug() << i;
        if (x + width >= plates[i].position.x() && x <= plates[i].position.x() + plates[i].width) {
            qDebug() << "x";
            if (y + height >= plates[i].position.y() && y <= plates[i].position.y()) {
                if(vy >= 0 && want_down == false){
                    y = plates[i].position.y() - height;
                    vy = 0.0f;
                    jump_time = 0;
                    on_ground = 1;
                    break;
                }
            }
        }
    }
    if(on_ground == 0){
        ay += 0.3f;
    }
    if(jump_time < max_junp_time){
        if(key_pressed[0] == true){
            if(have_jumped == false){
                ay -= 8.0f;
                jump_time++;
                have_jumped = true;
            }
        }
        if(key_pressed[0] == false){
            have_jumped = false;
        }
    }
    vy += ay;
    if (vy > -0.1f && vy < 0.1f) {
        vy = 0.0f;
    }
    vy = std::min(std::max(vy, -10.0f), 10.0f);
    y += vy;
    position.setY(y);
    ay = 0.0f;
}


