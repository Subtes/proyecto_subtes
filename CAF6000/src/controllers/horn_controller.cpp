#include "horn_controller.h"

Horn_Controller::Horn_Controller(SubteStatus *subte,FootHorn *pedal)
{
    m_subte = subte;
    m_pedal = pedal;

    connect(m_pedal,SIGNAL(hornPressed()),m_subte,SLOT(hombreVivoPressed()));
    connect(m_pedal,SIGNAL(hornReleased()),m_subte,SLOT(hombreVivoReleased()));
}

Horn_Controller::~Horn_Controller()
{

}
