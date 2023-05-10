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
    GameSetting *game_setting;
    StackedWidgets* stacked_widgets;
    QPushButton *currentButton;
    QDialog *keyCaptureDialog;
    int currentPlayer;
    int currentKeyIndex;
};

#endif // SETTINGINTERFACE_H
