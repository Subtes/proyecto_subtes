#include "atp_controller.h"

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp * view)
{
    this->m_subte = subte;
    this->m_view = view;

    this->m_timer_ATP_Allowed = new QTimer();
    this->m_timer_ATP_Allowed->setInterval(15000);

    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(checkSpeedWayAllowed(double)));
    connect(subte,SIGNAL(targetSpeedChanged(double)),this,SLOT(checkSpeedWayTarget(double)));
    connect(subte,SIGNAL(allowedSpeedChanged(double)),this,SLOT(updateAllowedSpeed(double)));
    connect(subte,SIGNAL(targetSpeedChanged(double)),this,SLOT(updateTargetSpeed(double)));
    connect(this->m_timer_ATP_Allowed,SIGNAL(timeout()),subte,SLOT(emergencyBrakeActived()));
    connect(this,SIGNAL(enableTraction()),subte,SLOT(enableTraction()));
    connect(this,SIGNAL(disableTraction()),subte,SLOT(disableTraction()));

}

void Atp_Controller::setTimerAllowed(int msec){
    this->m_timer_ATP_Allowed->setInterval(msec);
}

void Atp_Controller::updateTargetSpeed(double speed){
    m_view->updateTargetSpeed(speed);
}

void Atp_Controller::updateAllowedSpeed(double speed){
    m_view->updateAllowedSpeed(speed);
    //this->m_speedAllowed = speed;
}

void Atp_Controller::updateSpeed(double speed){
    m_view->updateSpeed(speed);
    //qDebug() << "Velocidad Atp_Controller: " << speed;
}

void Atp_Controller::resetIndicator(){
    m_view->setCL(false);
    m_view->setCMC(false);
    m_view->setFrenoUrg(false);
    m_view->setCorte(false);
    m_view->setFalla(false);
    m_view->setFserv(false);
}

void Atp_Controller::checkSpeedWayAllowed(double speed){
    //Falta ver el arranque en cuanto a velocidad inicial 0 y permitida
    //tambien 0?? Y la conduccion sea CMC u otra.
    if (speed > this->m_subte->getAllowSpeed() && !(this->m_timer_ATP_Allowed->isActive())){
        this->m_timer_ATP_Allowed->start();
        emit disableTraction();
        qDebug() << "Atp_Controller::--> emit disable Traction";
    }else if ((this->m_timer_ATP_Allowed->isActive()) && (speed <= this->m_subte->getAllowSpeed())){
        this->m_timer_ATP_Allowed->stop();
        emit enableTraction();
        qDebug() << "Atp_Controller::--> emit enable Traction";

    }
}

void Atp_Controller::checkSpeedWayTarget(double speedTarget){
    //Seria una caso en el cual vengo al palo y me encuentro con un codigo de via menor,
    //o sea proximidades a fin de recorrido, no se si se puede dar consultar!
    if (speedTarget < this->m_subte->getSpeed() && !(this->m_timer_ATP_Allowed->isActive())){
        this->m_timer_ATP_Allowed->start();
        emit disableTraction();
        qDebug() << "Atp_Controller::--> emit disable Traction, porque flag de via (target speed) supero velocidad traida";
    }else if ((this->m_timer_ATP_Allowed->isActive()) && ((speedTarget*0.9) >= (this->m_subte->getSpeed()))){
        this->m_timer_ATP_Allowed->stop();
        emit enableTraction();
        qDebug() << "Atp_Controller::--> emit enable Traction";

    }
}

Atp_Controller::~Atp_Controller(){

}



