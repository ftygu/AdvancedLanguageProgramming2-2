#ifndef PLAYER_H
#define PLAYER_H
#include<QGraphicsItem>
#include<QPoint>
class Player : public QGraphicsItem
{
public:
    Player();
    QColor color;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
    int *keybindings;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    QPoint position;
    int width,height;
    int vx,vy;
    int ax,ay;
    void update_game();
    bool key_pressed[6];
    bool on_ground;
    int ground_height;
    void print_position();
};

#endif // PLAYER_H
