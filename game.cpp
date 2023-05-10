#include "game.h"
#include"gamesetting.h"
#include <QKeyEvent>
Game::Game(GameSetting *game_setting) :
    game_setting(game_setting)
{
    this->view.setScene(&this->scene);
    timer.setInterval(16);
    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(update_game()));
    QObject::connect(&view, &CustomGraphicsView::keyPressed, this, &Game::handleKeyPressEvent);
    QObject::connect(&view, &CustomGraphicsView::keyReleased, this, &Game::handleKeyReleaseEvent);
    players = game_setting->players;
    plates = game_setting->plates;
    scene.setSceneRect(-960,-540,1920,1080);
}

void Game::update_game()
{
    //更新玩家
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true)
            players[i].update_game();
            for (int j = 0; j < 100; j++) {
                players[i].bullets[j].update();
            }
            for(int j = 0; j < 4; j++){
                if(j != i){
                for(int k = 0; k < 100; k++){
                    if(players[j].is_apperaed == true && players[j].bullets[k].is_appear == true){
                        if(players[i].collidesWithItem(&players[j].bullets[k])){
                            if(players[j].bullets[k].vx > 0)
                            players[i].ax += players[j].bullets[k].impact_force;
                            else{
                            players[i].ax -= players[j].bullets[k].impact_force;
                            }
                             players[j].bullets[k].is_appear = false;
                        }
                    }
                }
                }
            }

        }
    scene.update();
    /*
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true){
            x += players[i].position.x();
            y += players[i].position.y();
        }
    }
    //更新视野中心
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
    */
    //更新缩放倍率
}

void Game::start()
{
    players_num = game_setting->players_num;
    plates_num = game_setting->plates_num;
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true){
            players[i].keybindings = game_setting->players_keybindings[i];
            players[i].plates = game_setting->plates;
            players[i].plates_num = game_setting->plates_num;
            this->scene.addItem(&players[i]);
            for(int j = 0; j < 100; j++){
                this->scene.addItem(&players[i].bullets[j]);
            }
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
}

void Game::handleKeyReleaseEvent(QKeyEvent* event)
{
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true)
            players[i].keyReleaseEvent(event);
        }
}
