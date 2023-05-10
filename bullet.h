#ifndef BULLET_H
#define BULLET_H
#include<QGraphicsItem>
class Player;
class Bullet : public  QGraphicsItem
{
public:
    Bullet();
    QColor color;
    QPixmap hit;
    double x,y,vx,vy;
    int height,width;
    int impact_force;
    int damage;
    int existing_time;
    QPoint position;
    bool is_appear;
    bool is_existing;
    bool is_hitting;
    int hitting_counter;
    bool is_gravity;
    void update();
    virtual void action(Player *player);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
};

#endif // BULLET_H
