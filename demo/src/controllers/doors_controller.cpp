#include "doors_controller.h"

Doors_Controller::Doors_Controller(Panel_Buttons3 * leftPanel,Panel_Buttons3 * rightPanel,QDial * dial)
{
    m_dial = dial;

    inicPanels(leftPanel,rightPanel);
    inicMachines();

    connect(dial,SIGNAL(valueChanged(int)),this,SLOT(updatePanels(int)));

    connect(m_leftPanel,SIGNAL(secondClicked()),this,SLOT(openLeftDoors()));
    connect(m_leftPanel,SIGNAL(thirdClicked()),this,SLOT(closeLeftDoors()));
    connect(m_rightPanel,SIGNAL(secondClicked()),this,SLOT(openRightDoors()));
    connect(m_rightPanel,SIGNAL(thirdClicked()),this,SLOT(closeRightDoors()));

}

Doors_Controller::~Doors_Controller()
{

}

void Doors_Controller::inicPanels(Panel_Buttons3 * leftPanel, Panel_Buttons3 * rightPanel){
    stateLeftDoors = false;
    m_leftPanel = leftPanel;
    m_leftPanel->setFirstClickeable(false);
    m_leftPanel->firstOff();
    m_leftPanel->secondOff();
    m_leftPanel->thirdOff();

    stateRightDoors = false;
    m_rightPanel = rightPanel;
    m_rightPanel->setFirstClickeable(false);
    m_rightPanel->firstOff();
    m_rightPanel->secondOff();
    m_rightPanel->thirdOff();
}

void Doors_Controller::inicMachines(){

//    QState * standby = new QState();
//    QState * opened = new QState();
//    QState * closed = new QState();

//    leftDoorsMachine->addState(standby);
//    leftDoorsMachine->addState(opened);
//    leftDoorsMachine->addState(closed);

//    leftDoorsMachine->addTransition(leftPanel,SIGNAL(secondClicked()),opened);
//    leftDoorsMachine->addTransition(leftPanel,SIGNAL(thirdClicked()),closed);
//    leftDoorsMachine->addTransition(this,SIGNAL(leftStandby()),closed);

//    rightDoorsMachine->addState(standby);
//    rightDoorsMachine->addState(opened);
//    rightDoorsMachine->addState(closed);

//    rightDoorsMachine->addTransition(rightPanel,SIGNAL(secondClicked()),opened);
//    rightDoorsMachine->addTransition(rightPanel,SIGNAL(thirdClicked()),closed);
//    rightDoorsMachine->addTransition(this,SIGNAL(rightStandby()),standby);

}

void Doors_Controller::updatePanels(int value){
    switch (value) {
        case 0:
            disableLeftPanel();
            disableRightPanel();
            break;
        case 1:
            reactiveRightPanel();
            disableLeftPanel();
            break;
        case 2:
            reactiveLeftPanel();
            disableRightPanel();
            break;
    }
}

void Doors_Controller::reactiveLeftPanel(){

    m_leftPanel->setSecondClickeable(false);
    m_leftPanel->setThirdClickeable(false);

    m_leftPanel->firstOn();

    if(stateRightDoors){
        m_leftPanel->secondOn();
        m_leftPanel->thirdOff();
    }else{
        m_leftPanel->secondOff();
        m_leftPanel->thirdOff();
    }
}

void Doors_Controller::reactiveRightPanel(){

    m_rightPanel->setSecondClickeable(false);
    m_rightPanel->setThirdClickeable(false);

    m_rightPanel->firstOn();

    if(stateRightDoors){
        m_rightPanel->secondOn();
        m_rightPanel->thirdOff();
    }else{
        m_rightPanel->secondOff();
        m_rightPanel->thirdOff();
    }
}

void Doors_Controller::disableRightPanel(){
    m_rightPanel->setSecondClickeable(false);
    m_rightPanel->setThirdClickeable(false);
    m_rightPanel->firstOff();
    m_rightPanel->secondOff();
    m_rightPanel->thirdOff();
}

void Doors_Controller::disableLeftPanel(){
    m_leftPanel->setSecondClickeable(false);
    m_leftPanel->setThirdClickeable(false);
    m_leftPanel->firstOff();
    m_leftPanel->secondOff();
    m_leftPanel->thirdOff();
}

void Doors_Controller::openLeftDoors(){
    stateLeftDoors = true;
    m_leftPanel->secondOn();
    m_leftPanel->thirdOff();
    //emit signal if necessary
}

void Doors_Controller::closeLeftDoors(){
    stateLeftDoors = false;
    m_leftPanel->secondOff();
    m_leftPanel->thirdOn();
    //emit signal if necessary
}

void Doors_Controller::openRightDoors(){
    stateRightDoors = true;
    m_rightPanel->secondOn();
    m_rightPanel->thirdOff();
    //emit signal if necessary
}

void Doors_Controller::closeRightDoors(){
    stateRightDoors = false;
    m_rightPanel->secondOff();
    m_rightPanel->thirdOn();
    //emit signal if necessary
}

