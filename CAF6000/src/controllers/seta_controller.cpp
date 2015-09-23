#include "seta_controller.h"

Seta_Controller::Seta_Controller(SubteStatus * modelo, Seta_Button * view)
{
    m_setaButton = view;
    m_modelo = modelo;

    connect(m_setaButton,SIGNAL(m_pressed()),this, SLOT(pushSeta()));
    connect(m_setaButton, SIGNAL(m_released()),this, SLOT(pullSeta()));

}

void Seta_Controller::pushSeta(){
    //qDebug() << "Entro en controller.pushSeta";
    m_modelo->setaActivated();
    //emit this->setaActivate();
}

void Seta_Controller::pullSeta(){
    //qDebug() << "Entro en controller.pullSeta";
    m_modelo->setaDeactivated();
    //emit this->setaDeactivated(); OJOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
}

QVariant Seta_Controller::isPressed(){
    // return seta's state from the model
    return(this->m_modelo->seta());
}

void Seta_Controller::setaPressed()
{
    m_setaButton->setOn();
}

void Seta_Controller::setaReleased()
{
    m_setaButton->setOff();
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

