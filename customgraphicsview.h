#ifndef CUSTOMGRAPHICSVIEW_H
#define CUSTOMGRAPHICSVIEW_H
#include<QShortcut>
#include <QGraphicsView>
//view将不在相应键盘事件，转而将事件发送给game中的函数，再由game将事件分发给每一个item
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
