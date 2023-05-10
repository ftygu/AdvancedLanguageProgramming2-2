#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H
#include<QShortcut>
#include <QGraphicsView>
class CustomGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    CustomGraphicsView(QWidget* parent = nullptr);
    QShortcut *shortcut;
signals:
    void keyPressed(QKeyEvent* event);
    void keyReleased(QKeyEvent* event);
protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
};

#endif // CUSTOMGRAPHICSVIEW_H
