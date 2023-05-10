#include "customgraphicsview.h"
#include <QKeyEvent>

CustomGraphicsView::CustomGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
}

void CustomGraphicsView::keyPressEvent(QKeyEvent* event)
{
    // 不要调用父类的实现
    emit keyPressed(event);
}

void CustomGraphicsView::keyReleaseEvent(QKeyEvent* event)
{
    // 不要调用父类的实现
    emit keyReleased(event);
}
