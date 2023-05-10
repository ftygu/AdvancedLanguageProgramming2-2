QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bullet.cpp \
    customgraphicsview.cpp \
    dialog.cpp \
    dialog1.cpp \
    dialog2.cpp \
    game.cpp \
    gamepreparationinterface.cpp \
    gamesetting.cpp \
    main.cpp \
    menuinterface.cpp \
    plate.cpp \
    player.cpp \
    settinginterface.cpp \
    stackedwidgets.cpp \
    weapon.cpp

HEADERS += \
    bullet.h \
    customgraphicsview.h \
    dialog.h \
    dialog1.h \
    dialog2.h \
    game.h \
    gamepreparationinterface.h \
    gamesetting.h \
    menuinterface.h \
    plate.h \
    player.h \
    settinginterface.h \
    stackedwidgets.h \
    weapon.h

FORMS += \
    dialog.ui \
    dialog1.ui \
    dialog2.ui \
    gamepreparationinterface.ui \
    menuinterface.ui \
    settinginterface.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

QT += multimedia
