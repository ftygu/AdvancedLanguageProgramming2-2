#include "game.h"
#include"gamesetting.h"
#include <QKeyEvent>
#include<qshortcut.h>
Game::Game(GameSetting *game_setting,StackedWidgets *stackedwidgets) :
    game_setting(game_setting),stackedwidgets(stackedwidgets),dialog(this)
{
    view.shortcut = new QShortcut(QKeySequence(Qt::Key_Escape), &view);
    QObject::connect(view.shortcut, &QShortcut::activated, this, &Game::pause_game);
    QObject::connect(view.shortcut, &QShortcut::activated, &this->dialog, &Dialog1::exec);
    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(update_game()));
    QObject::connect(&view, &CustomGraphicsView::keyPressed, this, &Game::handleKeyPressEvent);
    QObject::connect(&view, &CustomGraphicsView::keyReleased, this, &Game::handleKeyReleaseEvent);
    players = game_setting->players;
    plates = game_setting->plates;
    timer.setInterval(16);
    scene.setSceneRect(-960,-540,1920,1080);
    view.setScene(&scene);
}

void Game::update_game()
{
    living_players_num = 0;
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true){
            if(players[i].remaining_lives > 0){
                living_players_num++;
                last_live_player = &players[i];
            }
            players[i].update_game();
            for (int j = 0; j < 100; j++) {
                players[i].bullets[j].update();
            }
            for(int j = 0; j < 4; j++){
                if(j != i){
                for(int k = 0; k < 100; k++){
                    if(players[j].bullets[k].is_existing == true){
                        if(players[i].collidesWithItem(&players[j].bullets[k])){
                             players[j].bullets[k].action(&players[i]);
                        }
                    }
                }
                }
            }
        }
     }
    if(living_players_num == 1){
        last_live_player->is_winner = true;
    }
    scene.update();
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
            players[i].initialization(game_setting->lives_num);
            this->scene.addItem(&players[i]);
            for(int j = 0; j < 100; j++){
                this->scene.addItem(&players[i].bullets[j]);
            }
            scene.setBackgroundBrush(QBrush(game_setting->background_color));
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
    for(int i = 0; i < 4; i++){
        if(players[i].is_apperaed == true){
            this->scene.removeItem(&players[i]);
            for(int j = 0; j < 100; j++){
                this->scene.removeItem(&players[i].bullets[j]);
            }
        }
    }
    for(int i = 0; i < plates_num; i++){
        this->scene.removeItem(&plates[i]);
    }
}

void Game::pause_game()
{
    timer.stop();
}

void Game::continue_game()
{
    timer.start();
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
