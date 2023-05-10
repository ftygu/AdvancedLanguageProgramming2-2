#include "settinginterface.h"
#include "ui_settinginterface.h"
#include"stackedwidgets.h"
#include"gamesetting.h"
#include<Qt>
#include <QPushButton>
#include <QString>
#include <QMetaEnum>
#include<QMessageBox>
#include<QTimer>
#include<QKeyEvent>
#include<QLabel>
#include<QLayout>
SettingInterface::SettingInterface(QWidget *parent, GameSetting *game_setting) :
    QWidget(parent),
    ui(new Ui::SettingInterface)
{
    ui->setupUi(this);
    //使指针指向正确的对象
    stacked_widgets = static_cast<StackedWidgets*>(parent);
    this->game_setting = game_setting;
    //为每个按键按照setting中的键位设置初始化文本
    // Player 1
    ui->first_up->setText(QString(QKeySequence(game_setting->players_keybindings[0][0]).toString()));
    ui->first_down->setText(QString(QKeySequence(game_setting->players_keybindings[0][1]).toString()));
    ui->first_left->setText(QString(QKeySequence(game_setting->players_keybindings[0][2]).toString()));
    ui->first_right->setText(QString(QKeySequence(game_setting->players_keybindings[0][3]).toString()));
    ui->first_attack->setText(QString(QKeySequence(game_setting->players_keybindings[0][4]).toString()));
    ui->first_special->setText(QString(QKeySequence(game_setting->players_keybindings[0][5]).toString()));
    // Player 2
    ui->second_up->setText(QString(QKeySequence(game_setting->players_keybindings[1][0]).toString()));
    ui->second_down->setText(QString(QKeySequence(game_setting->players_keybindings[1][1]).toString()));
    ui->second_left->setText(QString(QKeySequence(game_setting->players_keybindings[1][2]).toString()));
    ui->second_right->setText(QString(QKeySequence(game_setting->players_keybindings[1][3]).toString()));
    ui->second_attack->setText(QString(QKeySequence(game_setting->players_keybindings[1][4]).toString()));
    ui->second_special->setText(QString(QKeySequence(game_setting->players_keybindings[1][5]).toString()));
    // Player 3
    ui->third_up->setText(QString(QKeySequence(game_setting->players_keybindings[2][0]).toString()));
    ui->third_down->setText(QString(QKeySequence(game_setting->players_keybindings[2][1]).toString()));
    ui->third_left->setText(QString(QKeySequence(game_setting->players_keybindings[2][2]).toString()));
    ui->third_right->setText(QString(QKeySequence(game_setting->players_keybindings[2][3]).toString()));
    ui->third_attack->setText(QString(QKeySequence(game_setting->players_keybindings[2][4]).toString()));
    ui->third_special->setText(QString(QKeySequence(game_setting->players_keybindings[2][5]).toString()));
    // Player 4
    ui->forth_up->setText(QString(QKeySequence(game_setting->players_keybindings[3][0]).toString()));
    ui->forth_down->setText(QString(QKeySequence(game_setting->players_keybindings[3][1]).toString()));
    ui->forth_left->setText(QString(QKeySequence(game_setting->players_keybindings[3][2]).toString()));
    ui->forth_right->setText(QString(QKeySequence(game_setting->players_keybindings[3][3]).toString()));
    ui->forth_attack->setText(QString(QKeySequence(game_setting->players_keybindings[3][4]).toString()));
    ui->forth_special->setText(QString(QKeySequence(game_setting->players_keybindings[3][5]).toString()));
    //连接按键与键位改变函数
    // Player 1
    connect(ui->first_up, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->first_down, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->first_left, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->first_right, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->first_attack, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->first_special, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    // Player 2
    connect(ui->second_up, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->second_down, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->second_left, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->second_right, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->second_attack, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->second_special, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    // Player 3
    connect(ui->third_up, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->third_down, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->third_left, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->third_right, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->third_attack, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->third_special, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    // Player 4
    connect(ui->forth_up, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->forth_down, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->forth_left, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->forth_right, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->forth_attack, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    connect(ui->forth_special, &QPushButton::clicked, this, &SettingInterface::changeKeyBinding);
    //为每个按钮设置代表的值
    // Player 1
    ui->first_up->setProperty("player", 0);
    ui->first_up->setProperty("keyIndex", 0);
    ui->first_down->setProperty("player", 0);
    ui->first_down->setProperty("keyIndex", 1);
    ui->first_left->setProperty("player", 0);
    ui->first_left->setProperty("keyIndex", 2);
    ui->first_right->setProperty("player", 0);
    ui->first_right->setProperty("keyIndex", 3);
    ui->first_attack->setProperty("player", 0);
    ui->first_attack->setProperty("keyIndex", 4);
    ui->first_special->setProperty("player", 0);
    ui->first_special->setProperty("keyIndex", 5);
    // Player 2
    ui->second_up->setProperty("player", 1);
    ui->second_up->setProperty("keyIndex", 0);
    ui->second_down->setProperty("player", 1);
    ui->second_down->setProperty("keyIndex", 1);
    ui->second_left->setProperty("player", 1);
    ui->second_left->setProperty("keyIndex", 2);
    ui->second_right->setProperty("player", 1);
    ui->second_right->setProperty("keyIndex", 3);
    ui->second_attack->setProperty("player", 1);
    ui->second_attack->setProperty("keyIndex", 4);
    ui->second_special->setProperty("player", 1);
    ui->second_special->setProperty("keyIndex", 5);
    // Player 3
    ui->third_up->setProperty("player", 2);
    ui->third_up->setProperty("keyIndex", 0);
    ui->third_down->setProperty("player", 2);
    ui->third_down->setProperty("keyIndex", 1);
    ui->third_left->setProperty("player", 2);
    ui->third_left->setProperty("keyIndex", 2);
    ui->third_right->setProperty("player", 2);
    ui->third_right->setProperty("keyIndex", 3);
    ui->third_attack->setProperty("player", 2);
    ui->third_attack->setProperty("keyIndex", 4);
    ui->third_special->setProperty("player", 2);
    ui->third_special->setProperty("keyIndex", 5);
    // Player 4
    ui->forth_up->setProperty("player", 3);
    ui->forth_up->setProperty("keyIndex", 0);
    ui->forth_down->setProperty("player", 3);
    ui->forth_down->setProperty("keyIndex", 1);
    ui->forth_left->setProperty("player", 3);
    ui->forth_left->setProperty("keyIndex", 2);
    ui->forth_right->setProperty("player", 3);
    ui->forth_right->setProperty("keyIndex", 3);
    ui->forth_attack->setProperty("player", 3);
    ui->forth_attack->setProperty("keyIndex", 4);
    ui->forth_special->setProperty("player", 3);
    ui->forth_special->setProperty("keyIndex", 5);

}

SettingInterface::~SettingInterface()
{
    delete ui;
}
//返回按钮被按下返回菜单界面
void SettingInterface::on_pushButton_clicked()
{
    stacked_widgets->setCurrentIndex(0);
}
//按下按钮时调用，确定玩家想要修改哪个键位并提示
void SettingInterface::changeKeyBinding() {
    currentButton = qobject_cast<QPushButton *>(sender());
    currentPlayer = currentButton->property("player").toInt();
    currentKeyIndex = currentButton->property("keyIndex").toInt();

    QMessageBox msgBox;
    msgBox.setWindowTitle("更改按键");
    msgBox.setText("请按下新的按键");
    msgBox.setStandardButtons(QMessageBox::NoButton);
    msgBox.setModal(true);
    QTimer::singleShot(400, &msgBox, &QMessageBox::reject); // 设置对话框自动关闭时间
    msgBox.exec();

    setFocus(); // 确保窗口获得焦点以便捕获按键事件
}
//按下按键时修改setting中的对应键位并更改按钮上显示的值
void SettingInterface::keyPressEvent(QKeyEvent *event)
{
    if (!currentButton)
    {
        return;
    }

    int newKey = event->key();
    game_setting->players_keybindings[currentPlayer][currentKeyIndex] = newKey;
    currentButton->setText(QKeySequence(newKey).toString());

    currentButton = nullptr;
}

