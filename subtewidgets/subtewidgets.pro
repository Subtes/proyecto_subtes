QT += core gui quick quickwidgets declarative widgets

TEMPLATE = lib

CONFIG+= staticlib

HEADERS += \
    panel_buttons2.h \
    panel_buttons3.h \
    tractionlever.h \
    speedgauge.h \
    foothorn.h \
    wiper.h

SOURCES += \
    panel_buttons2.cpp \
    panel_buttons3.cpp \
    tractionlever.cpp \
    speedgauge.cpp \
    foothorn.cpp \
    wiper.cpp

FORMS += \
    panel_buttons2.ui \
    panel_buttons3.ui \
    tractionlever.ui \
    speedgauge.ui \
    foothorn.ui \
    wiper.ui

RESOURCES += widgetsrsc.qrc \
            qmlrsc.qrc

DISTFILES +=
