QT += core gui quick quickwidgets declarative widgets

TEMPLATE = lib

CONFIG+= staticlib

HEADERS += botonera2.h \
    botonera3.h \
    velocimetro.h \
    palancaslider.h

SOURCES += botonera2.cpp \
    botonera3.cpp \
    velocimetro.cpp \
    palancaslider.cpp

FORMS += botonera2.ui \
    botonera3.ui \
    velocimetro.ui \
    palancaslider.ui

RESOURCES += widgetsrsc.qrc \
            qmlrsc.qrc

DISTFILES +=
