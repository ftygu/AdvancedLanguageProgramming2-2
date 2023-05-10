#include "plate.h"
#include<QPainter>
Plate::Plate()
{

}

QRectF Plate::boundingRect() const
{
    return QRectF(this->position.x(),this->position.y(),this->height,this->width);
}

void Plate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);  //标明该参数没有使用
    Q_UNUSED(widget);
    painter->setBrush(Qt::blue);
    painter->drawRect(position.x(), position.y(), width, height);
}
