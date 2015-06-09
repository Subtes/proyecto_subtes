#include "atp_controller.h"

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp * view)
{
    this->m_subte = subte;
    this->m_view = view;

    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    //connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateAllowSpeed(double)));

}

void Atp_Controller::updateTargetSpeed(double speed){
    m_view->updateTargetSpeed(speed);
}

void Atp_Controller::updateAllowedSpeed(double speed){
    m_view->updateAllowedSpeed(speed);
}

void Atp_Controller::updateSpeed(double speed){
    m_view->updateSpeed(speed);
    qDebug() << "Velocidad Atp_Controller: " << speed;
}

Atp_Controller::~Atp_Controller(){

}

