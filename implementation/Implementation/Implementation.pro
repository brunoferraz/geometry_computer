#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T12:42:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Implementation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    grahamlist.cpp \
    util.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    grahamlist.h \
    util.h

FORMS    += mainwindow.ui
