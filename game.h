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
    //游戏场景
    QGraphicsScene scene;
    //游戏视角
    CustomGraphicsView view;
    Dialog1 dialog;
    //玩家指针
    Player *players;
    Player *last_live_player;
    //地形指针
    Plate *plates;
    //玩家和地形的数量
    int plates_num,players_num;
    //刷新
    QTimer timer;
    //所有玩家的平均坐标
    double x,y;
    QPoint average_point;
    //视野放缩大小
    double magnification_ratio;
    int living_players_num;
public slots:
    //更新下一帧
    void update_game();
    //游戏开始
    void start();
    //游戏停止
    void stop();
    void pause_game();
    void continue_game();
    //分发键盘事件
    void handleKeyPressEvent(QKeyEvent* event);
    void handleKeyReleaseEvent(QKeyEvent* event);
};

#endif // GAME_H
