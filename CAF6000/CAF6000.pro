#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T13:18:10
#
#-------------------------------------------------

QT += core gui quick quickwidgets declarative widgets xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CAF6000

TEMPLATE = app

CONFIG     += c++11

SOURCES += main.cpp\
    boardcenter.cpp \
    boardright.cpp \
    boardleft.cpp \
    boardtop.cpp \
    boardhardware.cpp \
    src/models/subtestatus.cpp \
    src/controllers/horn_controller.cpp \
    src/controllers/wiper_controller.cpp \
    src/controllers/tractionlever_controller.cpp \
    src/controllers/hombrevivo_controller.cpp \
    src/controllers/rana_controller.cpp \
    src/controllers/emergencyoverride_controller.cpp \
    src/controllers/tractionbypass_controller.cpp \
    src/controllers/seta_controller.cpp \
    src/controllers/circuitbreakerdes_controller.cpp \
    src/controllers/circuitbreakercon_controller.cpp \
    src/controllers/speedgaugeleds_controller.cpp \
    ../ENet/ENetClient.cpp \
    src/controllers/atp_controller.cpp

HEADERS  += boardcenter.h \
    boardright.h \
    boardleft.h \
    boardhardware.h \
    boardtop.h \
    src/models/subtestatus.h \
    src/controllers/horn_controller.h \
    src/controllers/wiper_controller.h \
    src/controllers/tractionlever_controller.h \
    src/controllers/hombrevivo_controller.h \
    src/controllers/rana_controller.h \
    src/controllers/emergencyoverride_controller.h \
    src/controllers/tractionbypass_controller.h \
    src/controllers/seta_controller.h \
    src/controllers/circuitbreakerdes_controller.h \
    src/controllers/circuitbreakercon_controller.h \
    src/controllers/speedgaugeleds_controller.h \
    ../ENet/ENetClient.h \
    src/controllers/atp_controller.h

FORMS    += boardcenter.ui \
    boardright.ui \
    boardleft.ui \
    boardhardware.ui \
    boardtop.ui

INCLUDEPATH +=  ../subtewidgets \
                $$PWD/../ENet

DEPENDPATH += $$PWD/../ENet

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \
        -L$$PWD/../ENet -lenet \
        -L$$PWD/../ENet/ -lWS2_32 \
        -L$$PWD/../ENet/ -lBufferOverflowU \
        -L$$PWD/../ENet/ -lWinMM \
        -L$$PWD/../ENet/ -lENetClient-Cpp

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc \
            boardrsc.qrc

DESTDIR = $$PWD

OTHER_FILES += \
    control.ini.xml
