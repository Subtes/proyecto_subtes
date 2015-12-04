QT += core xml widgets gui

TEMPLATE =

CONFIG += c++11 dll release

HEADERS += ../ENet/include/ENetClient.h \
    ../ENet/include/AdmClaves.h \
    ../ENet/include/DicClave.h \
    model/brakes.h \
    model/traction.h \
    model/subtestatebase.h \
    model/doors.h \
    model/automatictrainprotection.h \
    controller/base_eventhandler.h \
    controller/base_enethelper.h \
    notifier.h
    
SOURCES += ../ENet/include/ENetClient.cpp \
    ../ENet/include/AdmClaves.cpp \
    ../ENet/include/DicClave.cpp \
    model/brakes.cpp \
    model/traction.cpp \
    model/subtestatebase.cpp \
    model/doors.cpp \
    model/automatictrainprotection.cpp \
    controller/base_eventhandler.cpp \
    controller/base_enethelper.cpp \
    notifier.cpp
    
INCLUDEPATH += $$PWD/../ENet/include

DEPENDPATH += $$PWD/../ENet

LIBS+=  -L$$PWD/../ENet/lib/ -lenet \
        -L$$PWD/../ENet/lib/ -lWS2_32 \
        -L$$PWD/../ENet/lib/ -lBufferOverflowU \
        -L$$PWD/../ENet/lib/ -lWinMM \
        -L$$PWD/../ENet/lib/ -lENetClient-Cpp

#DESTDIR = $$PWD

EVERYTHING = $$SOURCES $$HEADERS $$LIBS
message("The project contains the following files:")
message($$EVERYTHING)
