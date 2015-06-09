#include "atp_controller.h"

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp * view)
{
    this->m_subte = subte;
    this->m_view = view;

}

Atp_Controller::~Atp_Controller(){

}

