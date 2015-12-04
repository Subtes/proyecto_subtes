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

    connect(m_hongo,SIGNAL(buttonPressed()),this,SLOT(hongoPressed()));
    connect(m_hongo,SIGNAL(buttonPressed()),this,SLOT(hongoPressed()));
}

HongoEmergenciaController::~HongoEmergenciaController(){
}

void HongoEmergenciaController::pushHongo(){
    m_hongo->turnOn();
}

void HongoEmergenciaController::releaseHongo(){
    m_hongo->turnOff();
}

void HongoEmergenciaController::hongoPressed(){
    m_subte->setaActivated();
}

void HongoEmergenciaController::hongoReleased(){
    m_subte->setaDeactivated();
}
