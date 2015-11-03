#include "horn_controller.h"

Horn_Controller::Horn_Controller(SubteStatus *subte,FootHorn *pedal)
{
    m_subte = subte;
    m_pedal = pedal;

    connect(m_pedal,SIGNAL(hornPressed(int)),m_subte,SLOT(hornOn(int)));
    connect(m_pedal,SIGNAL(hornReleased(int)),m_subte,SLOT(hornOff(int)));
}

Horn_Controller::~Horn_Controller()
{

}

void Horn_Controller::setBocina(bool v)
{
    m_pedal->setBocina(v);
}
