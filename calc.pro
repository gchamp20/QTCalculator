#-------------------------------------------------
#
# Project created by QtCreator 2016-01-29T00:00:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = calc2
TEMPLATE = app


SOURCES += \
    Core/src/Expression.cpp \
    Core/src/Parser.cpp \
    GUI/src/characterButton.cpp \
    GUI/src/digitbutton.cpp \
    GUI/src/lcdscreen.cpp \
    GUI/src/mainwindow.cpp \
    GUI/src/numpad.cpp \
    main.cpp

HEADERS  += \
    Core/include/Expression.h \
    Core/include/Parser.h \
    GUI/include/characterButton.h \
    GUI/include/digitbutton.h \
    GUI/include/lcdscreen.h \
    GUI/include/mainwindow.h \
    GUI/include/numpad.h
