#include "plate.h"
#include<QPainter>
Plate::Plate()
{
    setZValue(0);
}

QRectF Plate::boundingRect() const
{
    return QRectF(this->position.x(),this->position.y(), this->width, this->height);
}

void Plate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
        Q_UNUSED(widget);
        if(test_mode == true){
            painter->setBrush(color);
            QRectF rect = boundingRect();
            painter->drawRect(rect);
        }
        if(pixture.isNull()==false){
        painter->drawPixmap(position.x() - pix_width, position.y() - pix_height, pixture);
        }
}
