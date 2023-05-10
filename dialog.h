#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QColor>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QColor *color,QWidget *parent = nullptr);
    ~Dialog();
    QColor *color;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
