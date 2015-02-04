#-------------------------------------------------
#
# Project created by QtCreator 2015-01-28T14:54:10
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets opengl

TARGET = CGal
TEMPLATE = app

LIBS += -lGLEW -lglut -lGL -lGLU
LIBS += -L/lib64 -lgmp -lCGAL

QMAKE_CXXFLAGS += -frounding-math

SOURCES += main.cpp\
        mainwindow.cpp \
    glcanvas.cpp

HEADERS  += mainwindow.h \
    glcanvas.h

FORMS    += mainwindow.ui
