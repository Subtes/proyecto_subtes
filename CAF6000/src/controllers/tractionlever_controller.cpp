#include "tractionlever_controller.h"

TractionLever_Controller::TractionLever_Controller(SubteStatus * subte, TractionLever * tractionLever)
{
    m_subte = subte;
    m_tractionLever = tractionLever;

    connect(m_tractionLever,SIGNAL(traction(int)),m_subte,SLOT(tractionReceived(int)));
    connect(m_tractionLever,SIGNAL(brake(int)),m_subte,SLOT(brakeReceived(int)));
    connect(m_tractionLever,SIGNAL(emergencyBrake()),m_subte,SLOT(emergencyBrakeActived()));
    connect(m_tractionLever,SIGNAL(positionChanged(int)),m_subte,SLOT(tractionLeverChanged(int)));
}

TractionLever_Controller::~TractionLever_Controller()
{

}

void TractionLever_Controller::setValue(int v)
{
    m_tractionLever->setValue(v);
}
