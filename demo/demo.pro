QT += core gui quick quickwidgets declarative widgets

TEMPLATE = app

TARGET = demo

SOURCES += main.cpp \
            tablero.cpp \
            src/models/mytest.cpp \
            src/models/subtestatus.cpp \
            src/controllers/hombrevivohombremuerto_controller.cpp \
            src/controllers/doors_controller.cpp \
            src/controllers/speedgauge_controller.cpp \
            src/controllers/tractionlever_controller.cpp \
    simulacionsubtefisica.cpp \
    dispatcher.cpp

HEADERS += tablero.h \
            src/models/mytest.h \
            src/models/subtestatus.h \
            src/controllers/hombrevivohombremuerto_controller.h \
            src/controllers/doors_controller.h \
            src/controllers/speedgauge_controller.h \
            src/controllers/tractionlever_controller.h \
    simulacionsubtefisica.h \
    dispatcher.h

FORMS += tablero.ui

INCLUDEPATH +=  ../subtewidgets

LIBS+=  -L../subtewidgets/debug -lsubtewidgets \
        -L../subtewidgets/release -lsubtewidgets \

RESOURCES += ../subtewidgets/widgetsrsc.qrc \
            ../subtewidgets/qmlrsc.qrc
