#include "seta_controller.h"

Seta_Controller::Seta_Controller(SubteStatus * modelo, Seta_Button * view)
{
    this->m_setaButton = view;
    //this->m_activated = QVariant(false);

    connect(this->m_setaButton,SIGNAL(m_pressed()),this, SLOT(pushSeta()));
    connect(this->m_setaButton, SIGNAL(m_released()),this, SLOT(pullSeta()));


}

void Seta_Controller::pushSeta(){
    //this->m_activated = true;
    qDebug() << "Entro en pushSeta";
    emit this->setaActivate();

}

void Seta_Controller::pullSeta(){
    //this->m_activated = false;
    emit this->setaDeactivated();

}

QVariant Seta_Controller::isPressed(){
    return(this->isPressed().toBool());

}

Seta_Controller::~Seta_Controller()
{

}

