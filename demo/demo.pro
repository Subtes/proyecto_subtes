QT += core gui quick quickwidgets declarative widgets

TEMPLATE = app

TARGET = demo

SOURCES += main.cpp \
            tablero.cpp \
            src/models/mytest.cpp

HEADERS += tablero.h \
            src/models/mytest.h

FORMS += tablero.ui

INCLUDEPATH +=  ../subtewidgets

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc
