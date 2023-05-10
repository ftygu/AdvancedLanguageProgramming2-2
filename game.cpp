#include "game.h"
#include"player.h"
#include"gamesetting.h"
#include<QTimer>
Game::Game(GameSetting *game_setting) :
    game_setting(game_setting)
{
    this->view.setScene(&this->scene);
    scene.setSceneRect(0, 0, 2000, 2000);
    timer.setInterval(16);
    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(update_game()));
    QObject::connect(&scene, &CustomGraphicsScene::keyPressed, this, &Game::handleKeyPressEvent);
    QObject::connect(&scene, &CustomGraphicsScene::keyReleased, this, &Game::handleKeyReleaseEvent);
    players_num = 2;
    plates_num = 1;
    players = new Player[4]; // 为玩家数组分配内存
    plates = new Plate[plates_num]; // 为 Plate 数组分配内存
    for(int i = 0; i < players_num; i++){
            players[i].keybindings = game_setting->players_keybindings[i];
            this->scene.addItem(&players[i]);
        }

        for(int i = 0; i < plates_num; i++){
            this->scene.addItem(&plates[i]);
        }
}

void Game::update_game()
{
    for(int i = 0; i < players_num; i++){
            players[i].update_game();
        }
        scene.update();
}

void Game::start()
{
    timer.start();
}

void Game::stop()
{
    timer.stop();
}

void Game::handleKeyPressEvent(QKeyEvent* event)
{
    for(int i = 0; i < players_num; i++){
            players[i].keyPressEvent(event);
        }
        // 如果有其他对象需要处理键盘事件，也在这里调用它们的 keyPressEvent 方法。
}

void Game::handleKeyReleaseEvent(QKeyEvent* event)
{
    for(int i = 0; i < players_num; i++){
            players[i].keyReleaseEvent(event);
        }
    // 如果有其他对象需要处理键盘事件，也在这里调用它们的 keyReleaseEvent 方法。
}
