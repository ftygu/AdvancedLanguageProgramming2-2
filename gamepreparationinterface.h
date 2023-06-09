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
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_10_clicked();
    void on_pushButton_11_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_12_clicked();
    void on_pushButton_13_clicked();
    void on_pushButton_14_clicked();
    void on_pushButton_15_clicked();
    void on_pushButton_16_clicked();
    void on_pushButton_17_clicked();
    void on_pushButton_18_clicked();
    void on_pushButton_19_clicked();
private:
    Ui::GamePreparationInterface *ui;
    GameSetting *game_setting;
    StackedWidgets *stacked_widgets;
};

#endif // GAMEPREPARATIONINTERFACE_H
