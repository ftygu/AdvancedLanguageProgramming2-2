#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QPoint>
class Player : public QGraphicsItem
{
public:
    Player();
    QColor color;
    int *keybindings;
    QPoint position;
    int width,height;
    int vx,vy,ax,ay;
    bool key_pressed[6];
    bool on_ground;
    bool is_apperaed;
    int ground_height;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void update_game();
    void print_position();
};

#endif // PLAYER_H
