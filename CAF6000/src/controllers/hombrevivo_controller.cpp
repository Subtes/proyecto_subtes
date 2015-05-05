#include "hombrevivo_controller.h"

HombreVivo_Controller::HombreVivo_Controller(SubteStatus *subte, TractionLever *slider)
{
    m_subte = subte;
    m_slider = slider;

    connect(m_slider,SIGNAL(hvPressed()),m_subte,SLOT(hombreVivoPressed()));
    connect(m_slider,SIGNAL(hvReleased()),m_subte,SLOT(hombreVivoReleased()));
}

HombreVivo_Controller::~HombreVivo_Controller()
{

}

