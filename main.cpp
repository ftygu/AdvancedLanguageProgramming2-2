#include "mainwindow.h"
#include"stackedwidgets.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StackedWidgets w;
    w.show();
    return a.exec();
}
