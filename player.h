#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QPoint>
class Plate;
class Player : public QGraphicsItem
{
public:
    Player();
    QColor color;
    int *keybindings;
    Plate *plates;
    int plates_num;
    QPoint position;
    int width,height;
    bool have_jumped;
    float x, y, vx, vy, ax, ay;
    bool key_pressed[6];
    int on_ground;/* 0为在地面上 1为在空中 2为卡在地面中 */
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
};

#endif // PLAYER_H
