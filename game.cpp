#include "game.h"
#include"gamesetting.h"
#include <QKeyEvent>
Game::Game(GameSetting *game_setting) :
    game_setting(game_setting)
{
    this->view.setScene(&this->scene);
    scene.setSceneRect(0, 0, 2000, 2000);
    timer.setInterval(16);
    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(update_game()));
    QObject::connect(&view, &CustomGraphicsView::keyPressed, this, &Game::handleKeyPressEvent);
    QObject::connect(&view, &CustomGraphicsView::keyReleased, this, &Game::handleKeyReleaseEvent);
    players = game_setting->players;
    scene.setSceneRect(-960,-540,1920,1080);
}

void Game::update_game()
{
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true)
            players[i].update_game();
        }
    scene.update();
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true){
            x += players[i].position.x();
            y += players[i].position.y();
        }
    }
    average_point.setX(x / players_num);
    average_point.setY(y / players_num);
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true){
            x += players[i].position.x();
            y += players[i].position.y();
        }
    }
    view.centerOn(average_point);
    x = 0;
    y = 0;
}

void Game::start()
{
    players_num = game_setting->Players_num;
    plates_num = game_setting->plates_num;
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true){
            players[i].keybindings = game_setting->players_keybindings[i];
            this->scene.addItem(&players[i]);
        }
    }
    for(int i = 0; i < plates_num; i++){
        this->scene.addItem(&plates[i]);
    }
    timer.start();
}

void Game::stop()
{
    timer.stop();
}

void Game::handleKeyPressEvent(QKeyEvent* event)
{
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true)
            players[i].keyPressEvent(event);
        }
        // 如果有其他对象需要处理键盘事件，也在这里调用它们的 keyPressEvent 方法。
}

void Game::handleKeyReleaseEvent(QKeyEvent* event)
{
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true)
            players[i].keyReleaseEvent(event);
        }
    // 如果有其他对象需要处理键盘事件，也在这里调用它们的 keyReleaseEvent 方法。
}
