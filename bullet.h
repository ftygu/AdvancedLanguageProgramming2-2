#ifndef BULLET_H
#define BULLET_H
#include<QGraphicsItem>

class Bullet : public  QGraphicsItem
{
public:
    Bullet();
    QColor color;
    double x,y,vx;
    int height,width;
    int bullet_impact_force;
    QPoint position;
    bool is_appear;
    void update();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
};

#endif // BULLET_H
