//该界面用于修改游戏键位设置
#ifndef SETTINGINTERFACE_H
#define SETTINGINTERFACE_H
#include<QPushButton>
#include <QWidget>
class GameSetting;
class StackedWidgets;
namespace Ui {
class SettingInterface;
}

class SettingInterface : public QWidget
{
    Q_OBJECT

public:
    explicit SettingInterface(QWidget *parent = nullptr, GameSetting *game_setting = nullptr);
    ~SettingInterface();

private slots:
    void on_pushButton_clicked();
    void changeKeyBinding();
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::SettingInterface *ui;
    //指向游戏设置的指针，用于修改键位设置
    GameSetting *game_setting;
    //指向父对象的指针
    StackedWidgets* stacked_widgets;
    //被按下的按钮
    QPushButton *currentButton;
    //提示窗口
    QDialog *keyCaptureDialog;
    //哪个玩家的按键要被修改
    int currentPlayer;
    //哪个按键要被修改
    int currentKeyIndex;
};

#endif // SETTINGINTERFACE_H
