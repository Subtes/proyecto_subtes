#include "subtestate.h"

SubteState::SubteState()
{

}

SubteState::~SubteState()
{

}

void SubteState::setHandler(EventHandler *eventHandler)
{
    m_eventHandler = eventHandler;
}

void SubteState::hmPressed()
{
    hombreMuerto = true;
    m_eventHandler->notifyValueChanged("c_dispositivo_hombre_muerto","con");
    qDebug() << "c_dispositivo_hombre_muerto - con";
}

void SubteState::hmReleased()
{
    hombreMuerto = false;
    m_eventHandler->notifyValueChanged("c_dispositivo_hombre_muerto","des");
    qDebug() << "c_dispositivo_hombre_muerto - des";
}

void SubteState::setTraction(int value)
{
    if(hombreMuerto){
        m_eventHandler->notifyValueChanged("c_traccion",std::to_string(value));
        qDebug() << "c_traccion - " << value;
    }else{
        m_eventHandler->notifyValueChanged("c_traccion","0");
        qDebug() << "c_traccion - 0";
    }
}

void SubteState::setBrake(int value)
{
    m_eventHandler->notifyValueChanged("c_freno",std::to_string(value));
    qDebug() << "c_freno - " << value;
}

void SubteState::setEmergencyBeake(bool brake)
{
    if(brake){
        m_eventHandler->notifyValueChanged("c_freno_emergencia","con");
        qDebug() << "c_freno_emergencia - con";
    } else {
        m_eventHandler->notifyValueChanged("c_freno_emergencia","des");
        qDebug() << "c_freno_emergencia - des";
    }
}

void SubteState::setMode(int value)
{
    // 0:CLR 1:NEUTRO 2:COCHERA 3:ADELANTE

    if(value==0){
        m_eventHandler->notifyValueChanged("c_rana","at");
        qDebug() << "c_rana - at";
    }
    else if(value==1){
        m_eventHandler->notifyValueChanged("c_rana","0");
        qDebug() << "c_rana - 0";
    }
    else if(value>=2){
        m_eventHandler->notifyValueChanged("c_rana","ad");
        qDebug() << "c_rana - ad";
    }
}

void SubteState::updateneedleVelocityTcms(double value){
    m_needleVelocityTcms = value;
    qDebug()<<"subte velocidad"<<value;
    emit velocityChangeTcms(m_needleVelocityTcms);
}

void SubteState::updateVoltimetroLeftTCMS(double value){
    m_voltimetroLeft = value;
    qDebug()<<"subte voltL"<<value;
    emit voltimetroChangeLeft(m_voltimetroLeft);
}

void SubteState::updateVoltimetroRightTCMS(double value){
    m_voltimetroRight = value;
    qDebug()<<"subte voltRight"<<value;
    emit voltimetroChangeRight(m_voltimetroRight);
}

void SubteState::updateneedleamperimetro(double value){
    m_amperimetro = value;
    qDebug()<<"subte amper"<<value;
    emit amperimetroChange(m_amperimetro);
}

//SACAR ES SOLO PARA PROBAR


void SubteState::updatevaluedoors(double value){
    m_valuedoors = value;
    qDebug()<<"subte puertas"<<value;
    emit doorsChange(m_valuedoors);
}
