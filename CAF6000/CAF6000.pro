#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T13:18:10
#
#-------------------------------------------------

QT += core gui quick quickwidgets declarative widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CAF6000

TEMPLATE = app

SOURCES += main.cpp\
    boardcenter.cpp \
    boardright.cpp \
    boardleft.cpp \
    boardhardware.cpp \
    src/models/subtestatus.cpp \
    src/controllers/horn_controller.cpp \
    src/controllers/wiper_controller.cpp \
    src/controllers/tractionlever_controller.cpp \
    src/controllers/hombrevivo_controller.cpp \
    src/controllers/rana_controller.cpp \
    src/controllers/emergencyoverride_controller.cpp \
    src/controllers/tractionbypass_controller.cpp \
    src/controllers/seta_controller.cpp

HEADERS  += boardcenter.h \
    boardright.h \
    boardleft.h \
    boardhardware.h \
    src/models/subtestatus.h \
    src/controllers/horn_controller.h \
    src/controllers/wiper_controller.h \
    src/controllers/tractionlever_controller.h \
    src/controllers/hombrevivo_controller.h \
    src/controllers/rana_controller.h \
    src/controllers/emergencyoverride_controller.h \
    src/controllers/tractionbypass_controller.h \
    src/controllers/seta_controller.h

FORMS    += boardcenter.ui \
    boardright.ui \
    boardleft.ui \
    boardhardware.ui

INCLUDEPATH +=  ../subtewidgets

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc
