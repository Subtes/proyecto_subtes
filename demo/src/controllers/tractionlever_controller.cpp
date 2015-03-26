#include "tractionlever_controller.h"

TractionLever_Controller::TractionLever_Controller(SubteStatus * subte, TractionLever * tractionLever)
{
    m_subte = subte;
    m_tractionLever = tractionLever;
    connect(m_tractionLever,SIGNAL(valueChanged(int)),m_subte,SLOT(updateTraction(int)));
}

TractionLever_Controller::~TractionLever_Controller()
{

}

