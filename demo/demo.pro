QT += core gui quick quickwidgets declarative widgets

TEMPLATE = app

TARGET = demo

SOURCES += main.cpp \
            tablero.cpp \
            src/models/mytest.cpp \
    src/controllers/hombrevivohombremuerto_controller.cpp \
    src/controllers/doors_controller.cpp

HEADERS += tablero.h \
            src/models/mytest.h \
    src/controllers/hombrevivohombremuerto_controller.h \
    src/controllers/doors_controller.h

FORMS += tablero.ui

INCLUDEPATH +=  ../subtewidgets

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc
