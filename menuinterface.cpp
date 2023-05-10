#include "menuinterface.h"
#include "ui_menuinterface.h"
#include"stackedwidgets.h"
MenuInterface::MenuInterface(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuInterface)
{
    ui->setupUi(this);
    stacked_widgets = static_cast<StackedWidgets*>(parent);
}

MenuInterface::~MenuInterface()
{
    delete ui;
}

void MenuInterface::on_option_button_clicked()
{
    stacked_widgets->setCurrentIndex(1);
}

void MenuInterface::on_quit_button_clicked()
{
    stacked_widgets->close();
}

void MenuInterface::on_start_botton_clicked()
{
    stacked_widgets->setCurrentIndex(2);
}
