#ifndef GAME_H
#define GAME_H
#include<QObject>
#include<QGraphicsScene>
#include"customgraphicsview.h"
#include<QTimer>
#include"player.h"
#include"plate.h"
class GameSetting;
class Game : public QObject
{
    Q_OBJECT
public:
    Game(GameSetting *game_setting);
    GameSetting *game_setting;
    //游戏场景
    QGraphicsScene scene;
    //游戏视角
    CustomGraphicsView view;
    //玩家指针
    Player *players;
    //地形指针
    Plate *plates;
    //玩家和地形的数量
    int plates_num,players_num;
    //刷新器
    QTimer timer;
public slots:
    //更新下一帧
    void update_game();
    //游戏开始
    void start();
    //游戏停止
    void stop();
    //分发键盘事件
    void handleKeyPressEvent(QKeyEvent* event);
    void handleKeyReleaseEvent(QKeyEvent* event);
};

#endif // GAME_H
