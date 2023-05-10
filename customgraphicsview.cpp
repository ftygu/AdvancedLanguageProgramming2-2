#include "customgraphicsview.h"
#include <QKeyEvent>

CustomGraphicsView::CustomGraphicsView(QWidget* parent) : QGraphicsView(parent)
{
}

void CustomGraphicsView::keyPressEvent(QKeyEvent* event)
{
    emit keyPressed(event);
}

void CustomGraphicsView::keyReleaseEvent(QKeyEvent* event)
{
    emit keyReleased(event);
}
