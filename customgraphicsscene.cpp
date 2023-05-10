#include "customgraphicsscene.h"

CustomGraphicsScene::CustomGraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
{
}

void CustomGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    emit keyPressed(event);
    QGraphicsScene::keyPressEvent(event);
}

void CustomGraphicsScene::keyReleaseEvent(QKeyEvent *event)
{
    emit keyReleased(event);
    QGraphicsScene::keyReleaseEvent(event);
}
