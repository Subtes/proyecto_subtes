#-------------------------------------------------
# Project created by QtCreator 2015-04-16T13:18:10
#-------------------------------------------------
#declarative
QT += core gui quick quickwidgets widgets xml
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CAF6000

TEMPLATE = app

#release
CONFIG +=  c++11 debug

SOURCES += main.cpp \
    baseboard.cpp \
#    boardcenter.cpp \
#    boardright.cpp \
#    boardleft.cpp \
#    boardtop.cpp \
    boardhardware.cpp \
    src/models/subtestatus.cpp \
    src/controllers/horn_controller.cpp \
#    src/controllers/wiper_controller.cpp \
    src/controllers/tractionlever_controller.cpp \
    src/controllers/rana_controller.cpp \
#    src/controllers/emergencyoverride_controller.cpp \
#    src/controllers/tractionbypass_controller.cpp \
    src/controllers/seta_controller.cpp \
#    src/controllers/circuitbreakerdes_controller.cpp \
#    src/controllers/circuitbreakercon_controller.cpp \
#    src/controllers/speedgaugeleds_controller.cpp \
#    src/controllers/atp_controller.cpp \
    src/controllers/enethelper.cpp \
    src/controllers/eventhandler.cpp \
    ../ENet/ENetClient.cpp \
    src/models/traction.cpp \
    src/models/brake.cpp \
    src/models/cscp.cpp \
    src/controllers/keypresseater.cpp \
    src/models/atp_model.cpp \
#    src/controllers/topboardconnectors_controller.cpp \
    src/models/connectors.cpp \
#    src/controllers/topgauges_controller.cpp \
#    src/controllers/brakebypass_controller.cpp \
#    src/controllers/base_controller.cpp \
#    src/controllers/doors_controller.cpp \
#    src/controllers/manometer_controller.cpp \
#    src/instructionsolutionpanel/treeitem.cpp \
#    src/instructionsolutionpanel/treemodel.cpp \
#    src/instructionsolutionpanel/mainwindow.cpp \
    src/controllers/failures_controller.cpp \
#    src/controllers/sicasmac_controller.cpp \
    src/controllers/hombremuerto_controller.cpp \
#    src/controllers/llavemodoconduccion_controller.cpp
#    ../JoystickB/Joystick_Driver.cpp
    hardwareevent.cpp \
    qjoystick.cpp \
    joypick.cpp

HEADERS  += baseboard.h \
#    boardcenter.h \
#    boardright.h \
#    boardleft.h \
    boardhardware.h \
#    boardtop.h \
    src/models/subtestatus.h \
    src/controllers/horn_controller.h \
#    src/controllers/wiper_controller.h \
    src/controllers/tractionlever_controller.h \
    src/controllers/rana_controller.h \
#    src/controllers/emergencyoverride_controller.h \
#    src/controllers/tractionbypass_controller.h \
    src/controllers/seta_controller.h \
#    src/controllers/circuitbreakerdes_controller.h \
#    src/controllers/circuitbreakercon_controller.h \
#    src/controllers/speedgaugeleds_controller.h \
#    src/controllers/atp_controller.h \
    src/controllers/enethelper.h \
    src/controllers/eventhandler.h \
    ../ENet/ENetClient.h \
    src/models/traction.h \
    src/models/brake.h \
    src/models/cscp.h \
    src/controllers/keypresseater.h \
#    src/models/atp_model.h \
#    src/controllers/topboardconnectors_controller.h \
    src/models/connectors.h \
#    src/controllers/topgauges_controller.h \
#    src/controllers/brakebypass_controller.h \
#    src/controllers/base_controller.h \
#    src/controllers/doors_controller.h \
#    src/controllers/manometer_controller.h \
#    src/instructionsolutionpanel/treeitem.h \
#    src/instructionsolutionpanel/treemodel.h \
#    src/instructionsolutionpanel/mainwindow.h \
    src/controllers/failures_controller.h \
#    src/controllers/sicasmac_controller.h \
    src/controllers/hombremuerto_controller.h \
#    src/controllers/llavemodoconduccion_controller.h
#    ../JoystickB/Joystick_Driver.h \
#    ../JoystickB/dinputd.h \
#    ../JoystickB/resource.h
    hardwareevent.h \
    qjoystick.h \
    joypick.h

FORMS    += boardcenter.ui \
    boardright.ui \
    boardleft.ui \
    boardtop.ui \
    boardhardware.ui \
    src/instructionsolutionpanel/mainwindow.ui

INCLUDEPATH +=  ../subtewidgets \
                $$PWD/../ENet \
                $$PWD/../subtewidgets \
                $$PWD/../SDL

DEPENDPATH += $$PWD/../ENet \
              $$PWD/../SDL

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \
        -L$$PWD/../ENet -lenet \
        -L$$PWD/../ENet/ -lWS2_32 \
        -L$$PWD/../ENet/ -lBufferOverflowU \
        -L$$PWD/../ENet/ -lWinMM \
        -L$$PWD/../ENet/ -lENetClient-Cpp \
        -L$$PWD/../SDL/lib/x86/ -lSDL2

#        -L$$PWD/../JoystickB/Libs/ -lComCtl32 \
#        -L$$PWD/../JoystickB/Libs/ -lOle32 \
#        -L$$PWD/../JoystickB/Libs/ -ldinput8 \
#        -L$$PWD/../JoystickB/Libs/ -ldxguid \
#        -L$$PWD/../JoystickB/Libs/ -lUuid \
#        -L$$PWD/../JoystickB/Libs/ -lwbemuuid \
#        -L$$PWD/../JoystickB/Libs/ -lRpcRT4

#win32:QMAKE_LIBS_QT_ENGTRY -= -lqtmain
#win32-g++:DEFINES -= QT_NEEDS_QMAIN

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc \
            boardrsc.qrc

#win32 {
#DEFINES += SDL_WIN
#}
#CONFIG -= console
#contains(TEMPLATE, ".*app"){
#    QMAKE_LFLAGS += $$QMAKE_LFLAGS_WINDOWS
#    win32-g++:DEFINES += QT_NEEDS_QMAIN
#    win32-borland:DEFINES += QT_NEEDS_QMAIN

#    qt:for(entryLib, $$list($$unique(QMAKE_LIBS_QT_ENTRY))) {
#        isEqual(entryLib, -lqtmain): {
#            CONFIG(debug, debug|release): QMAKE_LIBS += $${entryLib}$${QT_LIBINFIX}d
#            else: QMAKE_LIBS += $${entryLib}$${QT_LIBINFIX}
#        } else {
#            QMAKE_LIBS += $${entryLib}
#        }
#    }
#}

DESTDIR = $$PWD

DISTFILES +=
