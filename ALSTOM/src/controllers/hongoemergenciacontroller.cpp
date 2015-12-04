#include "hongoemergenciacontroller.h"

HongoEmergenciaController::HongoEmergenciaController(SubteState *subte, SingleButton *hongo):
    Base_Controller(subte){

    m_hongo = hongo;

    QSize size;
    size.setWidth(140);
    size.setHeight(140);
    m_hongo->setSize(size);

    m_hongo->setButtonImage(QUrl("qrc:/resources/alstom_emergenciaon.png"),
                            QUrl("qrc:/resources/alstom_emergenciaoff.png"),
                            QUrl("qrc:/resources/alstom_emergenciaon.png"),
                            true,true);

    connect(m_hongo,SIGNAL(buttonClicked()),this,SLOT(hongoChange()));
}

HongoEmergenciaController::~HongoEmergenciaController(){
}

void HongoEmergenciaController::pushHongo(){
    m_hongo->turnOn();
}

void HongoEmergenciaController::releaseHongo(){
    m_hongo->turnOff();
}

void HongoEmergenciaController::hongoChange(){
    if(m_hongo->buttonState()) {
        //TODO: checkear! funciona invertido ??
        m_subte->setaDeactivated();
    }else{
        m_subte->setaActivated();
    }
}
