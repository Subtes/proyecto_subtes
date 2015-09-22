#include "hombremuerto_controller.h"

HombreMuerto_Controller::HombreMuerto_Controller(SubteStatus *subte, TractionLever *slider)
{
    m_subte = subte;
    m_slider = slider;

    connect(m_slider,SIGNAL(hvPressed()),m_subte,SLOT(hombreMuertoPressed()));
    connect(m_slider,SIGNAL(hvReleased()),m_subte,SLOT(hombreMuertoReleased()));
}

HombreMuerto_Controller::~HombreMuerto_Controller()
{

}

