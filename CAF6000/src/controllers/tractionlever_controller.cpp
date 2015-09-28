#include "tractionlever_controller.h"

TractionLever_Controller::TractionLever_Controller(SubteStatus * subte, TractionLever * tractionLever, TractionHardware *th)
{
    m_subte = subte;
    m_tractionLever = tractionLever;

    m_tractionHardware = th;

    m_checkJ = new QTimer();
    m_checkJ->setInterval(50);

    connect(m_tractionHardware,SIGNAL(traction(int)),this,SLOT(processTraction(int)));
    connect(m_tractionHardware,SIGNAL(emergencyBrake()),this,SLOT(processEmergencyBrake()));
    connect(m_tractionHardware,SIGNAL(brake(int)),this,SLOT(processBrake(int)));
    connect(m_checkJ,SIGNAL(timeout()),m_tractionHardware,SLOT(processValueChanged()));

    connect(m_tractionLever,SIGNAL(traction(int)),m_subte,SLOT(tractionReceived(int)));
    connect(m_tractionLever,SIGNAL(brake(int)),m_subte,SLOT(brakeReceived(int)));
    connect(m_tractionLever,SIGNAL(emergencyBrake()),m_subte,SLOT(emergencyBrakeActived()));
    connect(m_tractionLever,SIGNAL(positionChanged(int)),m_subte,SLOT(tractionLeverChanged(int)));

    m_checkJ->start();
    //th->onJoystick();
}

TractionLever_Controller::~TractionLever_Controller()
{

}

void TractionLever_Controller::setValue(int v)
{
    m_tractionLever->setValue(v);
}

void TractionLever_Controller::processTraction(int v)
{
    m_tractionLever->setValue(v);
    qDebug()<<"Valor de Joystick:  ---TRACTION------>"<< v;
}

void TractionLever_Controller::processBrake(int v)
{
    m_tractionLever->setValue(-v);
    qDebug()<<"Valor de Joystick:  ---BRAKE------>"<< v;
}

void TractionLever_Controller::processEmergencyBrake()
{
    m_tractionLever->setValue(-100);
    qDebug()<<"Valor de Joystick:  ---BRAKE EMERGENCY------>";
}
