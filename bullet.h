#ifndef BULLET_H
#define BULLET_H
#include<QGraphicsItem>

class Bullet : public  QGraphicsItem
{
public:
    Bullet();
    QColor color;
    double x,y,vx,vy;
    int height,width;
    int impact_force;
    int existing_time;
    QPoint position;
    bool is_appear;
    void update();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
};

#endif // BULLET_H
