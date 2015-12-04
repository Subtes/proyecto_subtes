#-------------------------------------------------
# Project created by QtCreator 2015-10-06T11:04:05
#-------------------------------------------------

QT += core gui quick quickwidgets widgets xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ALSTOM

TEMPLATE = app

CONFIG +=  c++11 release

SOURCES +=  ../ENet/include/ENetClient.cpp \
    ../ENet/include/AdmClaves.cpp \
    ../ENet/include/DicClave.cpp \
    main.cpp \
    boardcenter.cpp \
    boardhardware.cpp \
    boardmac.cpp \
    baseboard.cpp \
    boardatp.cpp \
    boardbottom.cpp \
    src/models/subtestate.cpp \
    src/controllers/eventhandler.cpp \
    src/controllers/enethelper.cpp \
    src/controllers/tractioncontroller.cpp \
    src/controllers/alstomtcms_controller.cpp \
    src/controllers/base_controller.cpp \
    src/controllers/hongoemergenciacontroller.cpp \
    src/controllers/llavaseguridadcontroller.cpp

HEADERS  += ../ENet/include/ENetClient.h \
    ../ENet/include/AdmClaves.h \
    ../ENet/include/DicClave.h \
    boardcenter.h \
    boardhardware.h \
    boardmac.h \
    baseboard.h \
    boardatp.h \
    boardbottom.h \
    src/models/subtestate.h \
    src/controllers/eventhandler.h \
    src/controllers/enethelper.h \
    src/controllers/tractioncontroller.h \
    src/controllers/alstomtcms_controller.h \
    src/controllers/base_controller.h \
    src/controllers/hongoemergenciacontroller.h \
    src/controllers/llavaseguridadcontroller.h

FORMS    += \
    boardcenter.ui \
    boardhardware.ui \
    boardmac.ui \
    boardatp.ui \
    boardbottom.ui

INCLUDEPATH +=  ../subtewidgets \
                ../Common \
                $$PWD/../ENet/include \
                $$PWD/../Source/include

DEPENDPATH += $$PWD/../ENet \
              $$PWD/../Source

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \
        -L../Common/debug -lCommon \
        -L../Common/release -lCommon \
        -L$$PWD/../ENet/lib/ -lenet \
        -L$$PWD/../ENet/lib/ -lWS2_32 \
        -L$$PWD/../ENet/lib/ -lBufferOverflowU \
        -L$$PWD/../ENet/lib/ -lWinMM \
        -L$$PWD/../ENet/lib/ -lENetClient-Cpp \
        -L$$PWD/../Source/lib/ -lSDL \
        -L$$PWD/../Source/lib/ -lSDL_mixer

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc \
            boardrsc.qrc

DESTDIR = $$PWD

OTHER_FILES += etc/control.ini
