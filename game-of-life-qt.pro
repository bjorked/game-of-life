#-------------------------------------------------
#
# Project created by QtCreator 2017-10-03T17:12:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game-of-life-qt
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
        src/main.cpp \
        src/ui/sources/mainwindow.cpp \
        src/logic/sources/cell.cpp \
        src/logic/sources/universe.cpp \
    src/ui/sources/gameoflifewidget.cpp

HEADERS += \
        src/ui/headers/mainwindow.h \
        src/logic/headers/cell.h \
        src/logic/headers/universe.h \
    src/ui/headers/gameoflifewidget.h

FORMS += \
        src/ui/forms/mainwindow.ui

DISTFILES += \
    TODO.txt
