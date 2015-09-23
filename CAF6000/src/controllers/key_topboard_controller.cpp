#include "key_topboard_controller.h"

Key_TopBoard_Controller::Key_TopBoard_Controller(SubteStatus *modelo, LlaveTecho *view)
{
    m_keyButton = view;
    m_modelo = modelo;
    connect(m_keyButton,SIGNAL(kHardPressed()),this, SLOT(keyON()));
    connect(m_keyButton, SIGNAL(lHardPressed()),this, SLOT(keyOFF()));
}

void Key_TopBoard_Controller::keyON(){
    qDebug() << "Entro en controller.keyON";
    m_modelo->keyActivated();
    emit keyActivated();
}

void Key_TopBoard_Controller::keyOFF(){
    qDebug() << "Entro en controller.keyOFF";
    m_modelo->keyDeactivated();
    emit keyDeactivated();
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

