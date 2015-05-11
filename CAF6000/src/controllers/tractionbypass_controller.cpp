#include "tractionbypass_controller.h"

TractionBypass_Controller::TractionBypass_Controller(SubteStatus *subte, SingleButton *button)
{
    m_subte = subte;
    m_button = button;

    m_button->setNestled(false);
    m_button->setLighted(true);
    m_button->setOnPressAsDriver();

    m_button->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));

    if(m_subte->CSCPStatus())
        m_button->turnOn();

    connect(m_button,SIGNAL(buttonPressed()),m_subte,SLOT(CSCPBypassed()));
    connect(m_button,SIGNAL(buttonReleased()),m_subte,SLOT(CSCPActivated()));

}

TractionBypass_Controller::~TractionBypass_Controller()
{

}

void TractionBypass_Controller::CSCP_checked()
{
    m_button->turnOn();
}

void TractionBypass_Controller::CSCP_unchecked()
{
    m_button->turnOff();
}
