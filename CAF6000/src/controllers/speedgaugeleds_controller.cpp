#include "speedgaugeleds_controller.h"

SpeedGaugeLeds_Controller::SpeedGaugeLeds_Controller(SubteStatus *subte, SpeedGaugeLeds * speedGauge)
{
    m_subte = subte;
    m_gauge = speedGauge;

    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateMaxSpeed(double)));
}

SpeedGaugeLeds_Controller::~SpeedGaugeLeds_Controller()
{

}

void SpeedGaugeLeds_Controller::updateSpeed(double speed){
    m_gauge->updateSpeed(speed);
}

void SpeedGaugeLeds_Controller::updateMaxSpeed(double speed){
    m_gauge->updateMaxSpeed(speed);
}
