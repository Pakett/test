#-------------------------------------------------
#
# Project created by QtCreator 2017-12-10T18:46:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QT_GAME
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    scenemanager.cpp \
    player.cpp \
    platform.cpp \
    platofrmspawner.cpp \
    score.cpp \
    enemy.cpp

HEADERS += \
    scenemanager.h \
    player.h \
    platform.h \
    vector2.h \
    platofrmspawner.h \
    score.h \
    enemy.h

FORMS +=

RESOURCES += \
    res.qrc
