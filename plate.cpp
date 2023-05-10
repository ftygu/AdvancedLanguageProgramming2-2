#include "plate.h"
#include<QPainter>
Plate::Plate()
{

}

QRectF Plate::boundingRect() const
{
    return QRectF(this->position.x(),this->position.y(), this->width, this->height);
}

void Plate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::blue);
    QRectF rect = boundingRect();
    painter->drawRect(rect);
}
