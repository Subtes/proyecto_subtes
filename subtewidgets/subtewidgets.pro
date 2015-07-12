QT += core gui quick quickwidgets multimedia widgets
#declarative
TEMPLATE = lib

CONFIG += debug staticlib order

HEADERS += \
    panel_buttons2.h \
    panel_buttons3.h \
    tractionlever.h \
    speedgauge.h \
    foothorn.h \
    wiper.h \
    rana.h \
    seta_button.h \
    singlebutton.h \
    speedgaugeleds.h \
    splash.h \
    atp.h

SOURCES += \
    panel_buttons2.cpp \
    panel_buttons3.cpp \
    tractionlever.cpp \
    speedgauge.cpp \
    foothorn.cpp \
    wiper.cpp \
    rana.cpp \
    seta_button.cpp \
    singlebutton.cpp \
    speedgaugeleds.cpp \
    splash.cpp \
    atp.cpp

FORMS += \
    panel_buttons2.ui \
    panel_buttons3.ui \
    tractionlever.ui \
    speedgauge.ui \
    foothorn.ui \
    wiper.ui \
    rana.ui \
    seta_button.ui \
    singlebutton.ui \
    speedgaugeleds.ui \
    splash.ui \
    atp.ui

RESOURCES += \
            qmlrsc.qrc \
            widgetsrsc.qrc


DISTFILES +=
