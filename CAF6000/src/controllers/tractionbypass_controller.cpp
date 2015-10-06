#include "tractionbypass_controller.h"

TractionBypass_Controller::TractionBypass_Controller(SubteStatus *subte, SingleButton *button, TractionHardware *th)
{
    m_subte = subte;
    m_button = button;
    m_tractionHardware = th;

    m_button->setNestled(false);
    m_button->setLighted(true);
    m_button->setOnPressAsDriver();
    m_button->setLightManagement(false);

    m_button->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));

    m_checkTB = new QTimer();
    m_checkTB->setInterval(750);

    connect(m_tractionHardware,SIGNAL(tractionBypassPressed()),this,SLOT(pressBypass()));
    connect(m_tractionHardware,SIGNAL(tractionBypassReleased()),this,SLOT(releaseBypass()));
    connect(m_button,SIGNAL(buttonPressed()),this,SLOT(pressBypass()));
    connect(m_button,SIGNAL(buttonReleased()),this,SLOT(releaseBypass()));
    connect(m_subte,SIGNAL(CSCPChanged(bool)),this,SLOT(updateStatus(bool)));

    updateStatus(m_subte->cscp());

    connect(m_checkTB,SIGNAL(timeout()),m_tractionHardware,SLOT(processBottonChanged()));
}

TractionBypass_Controller::~TractionBypass_Controller()
{

}

void TractionBypass_Controller::updateStatus(bool status)
{
    if(m_button->isLighted()){
        if(status){
            m_button->turnOn();
        }else{
            m_button->turnOff();
        }
    }
}

void TractionBypass_Controller::releaseBypass()
{
    m_subte->bypassCSCP(false);
    updateStatus(m_subte->cscp());
}

void TractionBypass_Controller::pressBypass()
{
    m_subte->bypassCSCP(true);
    updateStatus(m_subte->cscp());
}

void TractionBypass_Controller::onBypassHD(){
    if (m_tractionHardware->isHardwareEnable()){
        m_checkTB->start();
        qDebug()<<"Hardware ON: Bypass Traction";
    }else{
        qDebug()<<"No Hardware Baypass Traction";
    }
}

void TractionBypass_Controller::offBypassHD(){
    if (m_tractionHardware->isHardwareEnable()){
        m_checkTB->stop();
        qDebug()<<"Hardware OFF: Bypass Traction";
    }else{
        qDebug()<<"No Hardware Baypass Traction";
    }
}
