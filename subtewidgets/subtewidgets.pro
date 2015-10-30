QT += core gui quick quickwidgets widgets
#declarative

TEMPLATE = lib

CONFIG += release

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
    manometer.h \
    sicasmac.h \
    llavemodoconduccion.h \
    llavetecho.h \
    tractionhardware.h \
    alstomtractionlever.h \
    alstomselectormodoconduccion.h \
    caf6000subwaycarcabina.h \
    caf6000subwaycargrifos.h \
    caf6000subwaycaroption.h \
    caf6000subwaycarselection.h \
    caf6000subwaycartermicas.h \
    caf6000subwaycarsalon.h

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
    manometer.cpp \
    sicasmac.cpp \
    llavemodoconduccion.cpp \
    llavetecho.cpp \
    tractionhardware.cpp \
    alstomtractionlever.cpp \
    alstomselectormodoconduccion.cpp \
    caf6000subwaycarcabina.cpp \
    caf6000subwaycargrifos.cpp \
    caf6000subwaycaroption.cpp \
    caf6000subwaycarselection.cpp \
    caf6000subwaycartermicas.cpp \
    caf6000subwaycarsalon.cpp

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
    manometer.ui \
    sicasmac.ui \
    llavemodoconduccion.ui \
    llavetecho.ui \
    alstomtractionlever.ui \
    alstomselectormodoconduccion.ui \
    caf6000subwaycarcabina.ui \
    caf6000subwaycargrifos.ui \
    caf6000subwaycaroption.ui \
    caf6000subwaycarselection.ui \
    caf6000subwaycartermicas.ui \
    caf6000subwaycarsalon.ui

RESOURCES += \
            qmlrsc.qrc \
            widgetsrsc.qrc

INCLUDEPATH +=  $$PWD/../Source/include

DEPENDPATH += $$PWD/../Source

LIBS += -L$$PWD/../Source/lib/ -lSDL \
        -L$$PWD/../Source/lib/ -lSDL_mixer

DISTFILES +=
