#include "seta_controller.h"

Seta_Controller::Seta_Controller(SubteStatus * modelo, Seta_Button * view)
{
    this->m_setaButton = view;
    this->m_modelo = modelo;

    connect(this->m_setaButton,SIGNAL(m_pressed()),this, SLOT(pushSeta()));
    connect(this->m_setaButton, SIGNAL(m_released()),this, SLOT(pullSeta()));


}

void Seta_Controller::pushSeta(){
    //qDebug() << "Entro en controller.pushSeta";
    m_modelo->setaActivated();
    emit this->setaActivate();

}

void Seta_Controller::pullSeta(){
    //qDebug() << "Entro en controller.pullSeta";
    m_modelo->setaDeactivated();
    emit this->setaDeactivated();
}

QVariant Seta_Controller::isPressed(){
    // return seta's state from the model
    return(this->m_modelo->isSetaActivated());

}

Seta_Controller::~Seta_Controller()
{
    delete m_modelo;
    delete this->m_setaButton;
}

void Seta_Controller::resetToOff()
{
    m_setaButton->setOff();
}

