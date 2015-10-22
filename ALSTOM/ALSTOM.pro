#-------------------------------------------------
#
# Project created by QtCreator 2015-10-06T11:04:05
#
#-------------------------------------------------

QT       += core gui quick quickwidgets widgets xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ALSTOM

TEMPLATE = app

CONFIG +=  c++11 release

SOURCES +=  ../ENet/ENetClient.cpp \
    ../ENet/AdmClaves.cpp \
    main.cpp \
    boardcenter.cpp \
    boardhardware.cpp \
    boardmac.cpp \
    baseboard.cpp \
    src/controllers/eventhandler.cpp \
    src/models/subtestate.cpp \
    boardatp.cpp \
    boardbottom.cpp \
    src/controllers/enethelper.cpp \
    src/controllers/tractioncontroller.cpp

HEADERS  += \
    boardcenter.h \
    boardhardware.h \
    boardmac.h \
    baseboard.h \
    src/controllers/eventhandler.h \
    src/models/subtestate.h \
    boardatp.h \
    boardbottom.h \
    src/controllers/enethelper.h \
    src/controllers/tractioncontroller.h

FORMS    += \
    boardcenter.ui \
    boardhardware.ui \
    boardmac.ui \
    boardatp.ui \
    boardbottom.ui

INCLUDEPATH +=  ../subtewidgets \
                $$PWD/../ENet \
                $$PWD/../Source/include

DEPENDPATH += $$PWD/../ENet \
              $$PWD/../Source

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \
        -L$$PWD/../ENet/ -lenet \
        -L$$PWD/../ENet/ -lWS2_32 \
        -L$$PWD/../ENet/ -lBufferOverflowU \
        -L$$PWD/../ENet/ -lWinMM \
        -L$$PWD/../ENet/ -lENetClient-Cpp \
        -L$$PWD/../Source/lib/ -lSDL

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc \
            boardrsc.qrc

DESTDIR = $$PWD

OTHER_FILES += etc/control.ini
