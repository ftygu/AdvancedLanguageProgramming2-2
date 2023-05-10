#ifndef GAMEPREPARATIONINTERFACE_H
#define GAMEPREPARATIONINTERFACE_H

#include <QWidget>

class StackedWidgets;
class GameSetting;
namespace Ui {
class GamePreparationInterface;
}

class GamePreparationInterface : public QWidget
{
    Q_OBJECT

public:
    explicit GamePreparationInterface(QWidget *parent = nullptr);
    ~GamePreparationInterface();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_player1_appear_stateChanged(int arg1);

private:
    Ui::GamePreparationInterface *ui;
    GameSetting *game_setting;
    StackedWidgets *stacked_widgets;
};

#endif // GAMEPREPARATIONINTERFACE_H
