#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QPoint>
#include<QSound>
#include"weapon.h"
#include"bullet.h"
class Plate;
class Player : public QGraphicsItem
{
public:
    Player();
    QSound sound1,sound2,sound3;
    QPoint position;
    QColor head_color;
    QColor body_color;
    int *keybindings;
    int width,height;
    int timer;
    int abs_time;
    int face;
    int adjusted_y;
    int health;
    int remaining_lives;
    int plates_num;
    int jump_time,max_junp_time;
    int want_down_counter;
    float x, y, vx, vy, ax, ay;
    Bullet *bullets;
    Weapon *weapen;
    Plate *plates;
    bool key_pressed[6];
    bool have_jumped;
    bool on_ground;
    bool want_down;
    bool is_apperaed;
    bool is_living;
    bool is_winner;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void update_game();
    void print_position();
    void initialization(int lives_num);
};

#endif // PLAYER_H
