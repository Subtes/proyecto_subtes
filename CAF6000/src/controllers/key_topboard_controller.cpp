#include "key_topboard_controller.h"

Key_TopBoard_Controller::Key_TopBoard_Controller(SubteStatus *modelo, LlaveTecho *view, TractionHardware * th)
{
    m_keyButton = view;
    m_modelo = modelo;
    m_tractionHardware = th;

    m_checkJ = new QTimer();
    m_checkJ->setInterval(50);

    connect(m_keyButton,SIGNAL(kHardPressed()),this, SLOT(keyON()));
    connect(m_keyButton, SIGNAL(lHardPressed()),this, SLOT(keyOFF()));
    connect(m_tractionHardware,SIGNAL(processKeyTop(int)),this,SLOT(processKeyTop(int)));
    connect(m_checkJ,SIGNAL(timeout()),m_tractionHardware,SLOT(processKeyTop()));
}

void Key_TopBoard_Controller::keyON(){
    qDebug() << "Entro en controller.keyON";
    m_modelo->keyActivated();
}

void Key_TopBoard_Controller::keyOFF(){
    qDebug() << "Entro en controller.keyOFF";
    m_modelo->keyDeactivated();
}

void Key_TopBoard_Controller::keyTurnON()
{
    m_keyButton->setOn();
}

void Key_TopBoard_Controller::keyTurnOFF()
{
    m_keyButton->setOff();
}

Key_TopBoard_Controller::~Key_TopBoard_Controller()
{
    delete m_modelo;
    delete m_keyButton;
}

void Key_TopBoard_Controller::resetToOff()
{
    m_keyButton->setOff();
}

QVariant Key_TopBoard_Controller::isON(){
    // return keyATP's state from the model
    return(m_modelo->keyTopBoard());
}

void Key_TopBoard_Controller::processKeyTop(int k){
    if (k==1){
        m_keyButton->setOn();
        qDebug()<< "LLave (Joystick) Techo: ON";
    }else{
        m_keyButton->setOff();
    }
}

void Key_TopBoard_Controller::onKeyHD(){
    m_checkJ->start();
}

void Key_TopBoard_Controller::offKeyHD(){
    m_checkJ->stop();
}

