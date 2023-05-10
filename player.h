#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QPoint>
#include<weapon.h>
#include<bullet.h>
class Plate;
class Player : public QGraphicsItem
{
public:
    Player();
    int *keybindings;
    Plate *plates;
    int plates_num;
    QPoint position;
    int width,height;
    bool have_jumped;
    float x, y, vx, vy, ax, ay;
    bool key_pressed[6];
    int on_ground;
    bool is_apperaed;
    int ground_height;
    int jump_time,max_junp_time;
    bool want_down;
    int want_down_counter;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void update_game();
    void print_position();
    //射击
    Bullet *bullets;
    int direction;
    int shooting_interval;
    int reload_time;
    int now_time;
    //人物外观
    QColor head_color;
    QColor body_color;
    int timer;
    int abs_time;
    int face;
};

#endif // PLAYER_H
