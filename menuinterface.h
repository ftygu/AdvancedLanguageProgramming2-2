#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <QWidget>

class StackedWidgets;
namespace Ui {
class MenuInterface;
}
class MenuInterface : public QWidget
{
    Q_OBJECT
public:
    explicit MenuInterface(QWidget *parent = nullptr);
    ~MenuInterface();
private slots:
    void on_option_button_clicked();
    void on_quit_button_clicked();
    void on_start_botton_clicked();
private:
    Ui::MenuInterface *ui;
    StackedWidgets *stacked_widgets;
};

#endif // MENUINTERFACE_H
