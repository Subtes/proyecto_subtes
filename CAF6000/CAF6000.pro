#-------------------------------------------------
# Project created by QtCreator 2015-04-16T13:18:10
#-------------------------------------------------
#declarative
QT += core gui quick quickwidgets widgets xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CAF6000

TEMPLATE = app

#release
CONFIG +=  c++11 release

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
    src/controllers/atp_controller.cpp \
    src/controllers/enethelper.cpp \
    src/controllers/eventhandler.cpp \
    ../ENet/ENetClient.cpp \
    src/models/traction.cpp \
    src/models/brake.cpp \
    src/models/cscp.cpp \
    src/controllers/keypresseater.cpp \
    src/models/atp_model.cpp \
    src/controllers/topboardconnectors_controller.cpp \
    src/models/connectors.cpp \
    src/controllers/topgauges_controller.cpp \
    src/controllers/brakebypass_controller.cpp \
    src/controllers/base_controller.cpp \
    src/controllers/doors_controller.cpp \
    src/controllers/manometer_controller.cpp


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
    src/controllers/atp_controller.h \
    src/controllers/enethelper.h \
    src/controllers/eventhandler.h \
    ../ENet/ENetClient.h \
    src/models/traction.h \
    src/models/brake.h \
    src/models/cscp.h \
    src/controllers/keypresseater.h \
    src/models/atp_model.h \
    src/controllers/topboardconnectors_controller.h \
    src/models/connectors.h \
    src/controllers/topgauges_controller.h \
    src/controllers/brakebypass_controller.h \
    src/controllers/base_controller.h \
    src/controllers/doors_controller.h \
    src/controllers/manometer_controller.h

FORMS    += boardcenter.ui \
    boardright.ui \
    boardleft.ui \
    boardtop.ui \
    boardhardware.ui

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
