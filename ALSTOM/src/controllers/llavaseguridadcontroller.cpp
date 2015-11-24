#include "llavaseguridadcontroller.h"

LlavaSeguridadController::LlavaSeguridadController(SubteState *subte, SingleButton *llave){
    m_llave = llave;
    m_subte = subte;

    QSize size;
    size.setWidth(72);
    size.setHeight(72);
    m_llave->setSize(size);

    m_llave->setButtonImage(QUrl("qrc:/resources/alstom_greenkey_on.png"),
                        QUrl("qrc:/resources/alstom_greenkey_off.png"),
                        QUrl("qrc:/resources/alstom_greenkey_off.png"),
                        true,true);

    connect(m_llave,SIGNAL(buttonPressed),this,SLOT(turnedOn()));
    connect(m_llave,SIGNAL(buttonPressed),this,SLOT(turnedOff()));
}

LlavaSeguridadController::~LlavaSeguridadController(){
}

void LlavaSeguridadController::turnOnLlave(){
    m_llave->turnOn();
}

void LlavaSeguridadController::turnOffLlave(){
    m_llave->turnOff();
}

void LlavaSeguridadController::turnedOn(){

}

void LlavaSeguridadController::turnedOff(){

}
