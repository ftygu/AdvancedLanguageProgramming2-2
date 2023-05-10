#ifndef GAME_H
#define GAME_H
#include<QObject>
#include<QGraphicsScene>
#include"customgraphicsview.h"
#include<QTimer>
#include"player.h"
#include"plate.h"
#include"dialog1.h"
class StackedWidgets;
class GameSetting;
class Game : public QObject
{
    Q_OBJECT
public:
    Game(GameSetting *game_setting,StackedWidgets *stackedwidgets);
    GameSetting *game_setting;
    StackedWidgets *stackedwidgets;
    QGraphicsScene scene;
    CustomGraphicsView view;
    Dialog1 dialog;
    int plates_num,players_num;
    Player *players;
    Plate *plates;
    QTimer timer;
    Player *last_live_player;
    int living_players_num;
public slots:
    void update_game();
    void start();
    void stop();
    void pause_game();
    void continue_game();
    void handleKeyPressEvent(QKeyEvent* event);
    void handleKeyReleaseEvent(QKeyEvent* event);
};
#endif // GAME_H
