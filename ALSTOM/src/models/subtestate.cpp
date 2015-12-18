#include "subtestate.h"

SubteState::SubteState() : SubteStateBase(){
    m_atp->enableTraction();
}

SubteState::~SubteState(){
    delete m_cscp;
    delete m_brake;
    delete m_atp;
    delete m_traction;
}

void SubteState::setMode(int value)
{
    // 0:CLR 1:NEUTRO 2:COCHERA 3:ADELANTE

    if(value==0){
        m_traction->setDirection(Traction::TRACTION_MODE::REVERSA);
        m_eventHandler->notifyValueChanged("c_rana","at");
        qDebug() << "c_rana - at";
    }
    else if(value==1){
        m_traction->setDirection(Traction::TRACTION_MODE::NEUTRO);
        m_eventHandler->notifyValueChanged("c_rana","0");
        qDebug() << "c_rana - 0";
    }
    else if(value>=2){
        m_traction->setDirection(Traction::TRACTION_MODE::ADELANTE);
        m_eventHandler->notifyValueChanged("c_rana","ad");
        qDebug() << "c_rana - ad";
    }
}
