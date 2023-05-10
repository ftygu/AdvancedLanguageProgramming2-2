#include "player.h"
#include<QPainter>
#include<QKeyEvent>
#include<plate.h>
#include<algorithm>
#include<QDebug>
Player::Player() :
    width(30),height(54),position(0,0)
{
    is_apperaed = false;
    for(int i = 0; i < 6; i++){
        key_pressed[i] = false;
    }
    max_junp_time = 2;
    have_jumped = false;
    want_down = false;
    want_down_counter = 0;
    setZValue(1);
    //color_test
    head_color = Qt::blue;
    body_color = Qt::green;
    health = 100;
    remaining_lives = 2;
    kill_count = 0;
    timer = 30;
    is_living = true;
    is_winner = false;
}

QRectF Player::boundingRect() const
{
    return QRectF(this->position.x(),this->position.y(),this->height,this->width);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);
    painter->save();
    if(face == 1){
        painter->scale(1, 1);
        /*
        painter->setBrush(Qt::red);
        painter->drawRect(position.x(), position.y(), width, height);
        */
        QColor shadow(150, 150, 150);
        shadow.setAlpha(150);
        painter->setBrush(shadow);
        if(on_ground == true){
            painter->drawEllipse(position.x()-width/5+abs_time/4,position.y()+height*8/9-adjusted_y,width*7/5-abs_time/2,height*2/9+adjusted_y*2);
        }
        QPen pen(Qt::black);
        pen.setWidth(1);
        painter->setPen(pen);
        painter->setBrush(body_color);
        QPolygonF polygon;
        polygon << QPointF(position.x(), position.y()+height/3+adjusted_y)
                << QPointF(position.x()+width/5, position.y()+height+adjusted_y)
                << QPointF(position.x()+width*4/5, position.y()+height+adjusted_y)
                << QPointF(position.x()+width, position.y()+height/3+adjusted_y);
        painter->drawPolygon(polygon);
        painter->setBrush(head_color);
        if(vy >= 0){
            painter->drawEllipse(position.x() + width/5, position.y() - vy+adjusted_y, width*2/3, width*2/3);
            painter->setPen(Qt::NoPen);
            painter->setBrush(Qt::black);
            painter->drawEllipse(position.x() + width*4/10, position.y() - vy + height / 9+adjusted_y, width/5, width/5);
            painter->drawEllipse(position.x() + width*6/10, position.y() - vy + height / 9+adjusted_y, width/5, width/5);
        }
        else{
            painter->drawEllipse(position.x() + width/5, position.y() - vy/2+adjusted_y, width*2/3, width*2/3);
            painter->setPen(Qt::NoPen);
            painter->setBrush(Qt::black);
            painter->drawEllipse(position.x() + width*4/10, position.y() - vy/2 + height / 9+adjusted_y, width/5, width/5);
            painter->drawEllipse(position.x() + width*6/10, position.y() - vy/2 + height / 9+adjusted_y, width/5, width/5);
        }
    }
    else{
        int adjusted_x = -position.x() - width;
        painter->scale(-1, 1);
        /*
        painter->setBrush(Qt::red);
        painter->drawRect(adjusted_x, position.y(), width, height);
        */
        QColor shadow(150, 150, 150);
        shadow.setAlpha(150);
        painter->setBrush(shadow);
        if(on_ground == true){
            painter->drawEllipse(adjusted_x - width / 5+abs_time/4, position.y() + height * 8 / 9-adjusted_y, width * 7 / 5-abs_time/2, height * 2 / 9+adjusted_y*2);
        }
        QPen pen(Qt::black);
        pen.setWidth(1);
        painter->setPen(pen);
        painter->setBrush(body_color);
        QPolygonF polygon;
        polygon << QPointF(adjusted_x, position.y() + height / 3+adjusted_y)
                << QPointF(adjusted_x + width / 5, position.y() + height+adjusted_y)
                << QPointF(adjusted_x + width * 4 / 5, position.y() + height+adjusted_y)
                << QPointF(adjusted_x + width, position.y() + height / 3+adjusted_y);
        painter->drawPolygon(polygon);
        painter->setBrush(head_color);
        if (vy >= 0) {
            painter->drawEllipse(adjusted_x + width / 5, position.y() - vy+adjusted_y, width * 2 / 3, width * 2 / 3);
            painter->setPen(Qt::NoPen);
            painter->setBrush(Qt::black);
            painter->drawEllipse(adjusted_x + width * 4 / 10, position.y() - vy + height / 9+adjusted_y, width / 5, width / 5);
            painter->drawEllipse(adjusted_x + width * 6 / 10, position.y() - vy + height / 9+adjusted_y, width / 5, width / 5);
        } else {
            painter->drawEllipse(adjusted_x + width / 5, position.y() - vy / 2+adjusted_y, width * 2 / 3, width * 2 / 3);
            painter->setPen(Qt::NoPen);
            painter->setBrush(Qt::black);
            painter->drawEllipse(adjusted_x + width * 4 / 10, position.y() - vy / 2 + height / 9+adjusted_y, width / 5, width / 5);
            painter->drawEllipse(adjusted_x + width * 6 / 10, position.y() - vy / 2 + height / 9+adjusted_y, width / 5, width / 5);
        }
    }
    painter->restore();
    weapen->paint(painter);
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
    if(remaining_lives > 0){
        is_living = true;
    }
    else{
        is_living = false;
    }
    if(is_living){
        if(health <= 0){
            remaining_lives--;
            x = 0;
            y = -600;
            health = 100;
        }
        //沿x轴移动的计算
        if (key_pressed[2] == true) {
            ax -= 0.5f;
            face = -1;
        }
        if (key_pressed[3] == true) {
            ax += 0.5f;
            face = 1;
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
        if(want_down_counter >= 20){
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
            if (x + width >= plates[i].position.x() && x <= plates[i].position.x() + plates[i].width) {
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
        if(on_ground == false){
            ay += 0.3f;
        }
        if(jump_time < max_junp_time){
            if(key_pressed[0] == true){
                if(have_jumped == false){
                    vy = -8.0f;
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

        //超出场景的判断
        if(y >=810){
            x = 0;
            y = -600;
            remaining_lives--;
            health = 100;
        }

        //射击的判断
        weapen->update();
        if(key_pressed[4] == true){
            weapen->shoot();
        }
        if(key_pressed[5] == true){
            weapen->special_shoot();
        }
        //外观的渲染
        timer++;
        if(timer > 60){
            timer = 0;
        }
        abs_time = abs(timer - 30);
        adjusted_y = -abs_time / 10;
    }
}

void Player::initialization(int lives_num)
{
    x = 0;
    y = - 600;
    vx = 0;
    vy = 0;
    health = 100;
    remaining_lives = lives_num;
    jump_time = 0;
    max_junp_time = 2;
    is_living = true;
    is_winner = false;
    have_jumped = false;
    want_down = false;
    for(int i = 0; i < 6; i++){
        key_pressed[i] = false;
    }
    face = 1;
}


