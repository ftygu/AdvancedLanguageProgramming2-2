#ifndef PLATE_H
#define PLATE_H
#include<QGraphicsItem>
#include<QPoint>
class Plate : public QGraphicsItem
{
public:
    Plate();
    QColor color;
    QPixmap pixture;
    QPoint position;
    QRectF boundingRect() const override;
    int pix_height,pix_width;
    int width,height;
    bool test_mode;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget*widget) override;
};
#endif // PLATE_H
