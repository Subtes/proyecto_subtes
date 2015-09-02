#include "brakebypass_controller.h"

BrakeBypass_Controller::BrakeBypass_Controller(SubteStatus *subte, SingleButton *button)
    : Base_Controller(subte)
{
    m_subte = subte;
    m_button = button;

    m_button->setNestled(false);
    m_button->setLighted(true);
    m_button->setOnPressAsDriver();
    m_button->setLightManagement(false);

    m_button->setButtonImage(QUrl("qrc:/resources/redON.png"),QUrl("qrc:/resources/red.png"));

    updateHiloLazoStatus(m_subte->getHiloLazo());

    connect(m_button,SIGNAL(buttonPressed()),this,SLOT(bypassBrakePressed()));
    connect(m_button,SIGNAL(buttonReleased()),this,SLOT(bypassBrakeReleased()));
    connect(m_subte,SIGNAL(hiloLazoChanged(bool)),this,SLOT(updateHiloLazoStatus(bool)));
}

BrakeBypass_Controller::~BrakeBypass_Controller()
{
}

void BrakeBypass_Controller::bypassBrakePressed()
{
    m_subte->bypassBrake(true);
    m_button->turnOn();
}

void BrakeBypass_Controller::bypassBrakeReleased()
{
    m_subte->bypassBrake(false);
    this->updateHiloLazoStatus(m_subte->getHiloLazo());
}

void BrakeBypass_Controller::updateHiloLazoStatus(bool status)
{
    if(status)
        m_button->turnOn();
    else
        m_button->turnOff();
}
