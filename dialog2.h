#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
class Weapon;
class Player;
namespace Ui {
class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(Weapon **weapon, Player *player, QWidget *parent = nullptr);
    ~Dialog2();
    Weapon **weapon;
    Player *player;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
