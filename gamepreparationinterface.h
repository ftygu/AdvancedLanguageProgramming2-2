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

    void on_checkBox_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

private:
    Ui::GamePreparationInterface *ui;
    //用于修改地图，角色等属性
    GameSetting *game_setting;
    //父对象指针用于修改显示窗口
    StackedWidgets *stacked_widgets;
};

#endif // GAMEPREPARATIONINTERFACE_H
