# -------------------------------------------------
# Project created by QtCreator 2011-01-30T10:26:20
# -------------------------------------------------
QT += network core gui widgets

TARGET = Joypick

TEMPLATE = app

CONFIG +=  c++11

SOURCES +=  main.cpp \
            joypick.cpp \
            qjoystick.cpp

HEADERS +=  joypick.h \
            qjoystick.h

LIBS += -L$$PWD/./lib/x86/ -lSDL2

#win32 {
#DEFINES += SDL_WIN
#}

DESTDIR = $$PWD
