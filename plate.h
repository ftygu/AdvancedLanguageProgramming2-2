#ifndef PLATE_H
#define PLATE_H
#include<QGraphicsItem>
#include<QPoint>
class Plate : public QGraphicsItem
{
public:
    Plate();
    QColor color;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
    QPoint position;
    QPixmap pixture;
    int pix_height,pix_width;
    bool test_mode;
    int width,height;
};

#endif // PLATE_H
