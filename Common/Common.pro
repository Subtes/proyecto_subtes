QT += core xml

TEMPLATE = lib

CONFIG +=  c++11 release

HEADERS += model/brakes.h \
    model/traction.h \
    controller/eventhandler.h \
    controller/enethelper.h
    #../ENet/ENetClient.h \
    #../ENet/AdmClaves.h \

SOURCES += model/brakes.cpp \
    model/traction.cpp \
    controller/eventhandler.cpp \
    controller/enethelper.cpp
    #../ENet/ENetClient.cpp \
    #../ENet/AdmClaves.cpp \

INCLUDEPATH += #$$PWD/../ENet


DEPENDPATH += #$$PWD/../ENet

LIBS += #-L$$PWD/../ENet/ -lenet \
    #-L$$PWD/../ENet/ -lWS2_32 \
    #-L$$PWD/../ENet/ -lBufferOverflowU \
    #-L$$PWD/../ENet/ -lWinMM \
    #-L$$PWD/../ENet/ -lENetClient-Cpp

DESTDIR = $$PWD

#DISTFILES +=


