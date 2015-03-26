#include "speedgauge_controller.h"

SpeedGauge_Controller::SpeedGauge_Controller(SubteStatus *subte, SpeedGauge * speedGauge)
{
    m_subte = subte;
    m_speedGauge = speedGauge;

    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateNeedle(double)));
}

SpeedGauge_Controller::~SpeedGauge_Controller()
{

}

void SpeedGauge_Controller::updateNeedle(double speed){
    m_speedGauge->updateNeedle(speed);
}

