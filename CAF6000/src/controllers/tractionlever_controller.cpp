#include "tractionlever_controller.h"

TractionLever_Controller::TractionLever_Controller(SubteStatus * subte, TractionLever * tractionLever)
{
    m_subte = subte;
    m_tractionLever = tractionLever;

    connect(m_tractionLever,SIGNAL(traction(int)),m_subte,SLOT(tractionReceived(int)));
    connect(m_tractionLever,SIGNAL(zero()),m_subte,SLOT(tractionLeverInZero()));
    connect(m_tractionLever,SIGNAL(brake(int)),m_subte,SLOT(brakeReceived(int)));
    connect(m_tractionLever,SIGNAL(emergencyBrake()),m_subte,SLOT(emergencyBrakeActived()));
}

TractionLever_Controller::~TractionLever_Controller()
{

}
