#ifndef GAME_H
#define GAME_H
#include<QObject>
#include "customgraphicsscene.h"
#include<QGraphicsItem>
#include<QGraphicsView>
#include"player.h"
#include<QTimer>
#include"plate.h"
class GameSetting;
class Game : public QObject
{
    Q_OBJECT
public:
    Game(GameSetting *game_setting);
    GameSetting *game_setting;
    CustomGraphicsScene scene;
    QGraphicsView view;
    Player *players;
    Plate *plates;
    int plates_num,players_num;
    QTimer timer;
public slots:
    void update_game();
    void start();
    void stop();
    void handleKeyPressEvent(QKeyEvent* event);
    void handleKeyReleaseEvent(QKeyEvent* event);
};

#endif // GAME_H
