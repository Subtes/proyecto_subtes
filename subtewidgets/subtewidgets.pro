QT += core gui quick quickwidgets widgets
#declarative

TEMPLATE = lib

#order
CONFIG +=  release

HEADERS += \
    tractionlever.h \
    speedgauge.h \
    foothorn.h \
    wiper.h \
    rana.h \
    seta_button.h \
    singlebutton.h \
    speedgaugeleds.h \
    atp.h \
    analoggauge.h \
    manometer.h

SOURCES += \
    tractionlever.cpp \
    speedgauge.cpp \
    foothorn.cpp \
    wiper.cpp \
    rana.cpp \
    seta_button.cpp \
    singlebutton.cpp \
    speedgaugeleds.cpp \
    atp.cpp \
    analoggauge.cpp \
    manometer.cpp

FORMS += \
    tractionlever.ui \
    speedgauge.ui \
    foothorn.ui \
    wiper.ui \
    rana.ui \
    seta_button.ui \
    singlebutton.ui \
    speedgaugeleds.ui \
    atp.ui \
    analoggauge.ui \
    manometer.ui

RESOURCES += \
            qmlrsc.qrc \
            widgetsrsc.qrc


DISTFILES +=
