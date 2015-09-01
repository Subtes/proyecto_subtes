#include "doors_controller.h"

Doors_Controller::Doors_Controller(SubteStatus *subte, SingleButton *openLeftDoors, SingleButton *closeLeftDoors, SingleButton *selectLeftDoors, SingleButton *openRightDoors, SingleButton *closeRightDoors, SingleButton *selectRightDoors, SingleButton *silbato)
    : Base_Controller(subte)
{
    m_selectLeftDoors = selectLeftDoors;
    m_openLeftDoors = openLeftDoors;
    m_closeLeftDoors = closeLeftDoors;
    m_selectRightDoors = selectRightDoors;
    m_openRightDoors = openRightDoors;
    m_closeRightDoors = closeRightDoors;
    m_silbato = silbato;

    m_closeLeftDoors->setClickeable(false);
    m_closeLeftDoors->setLightManagement(false);
    m_closeRightDoors->setClickeable(false);
    m_closeRightDoors->setLightManagement(false);
    m_openLeftDoors->setClickeable(false);
    m_openLeftDoors->setLightManagement(false);
    m_openRightDoors->setClickeable(false);
    m_openRightDoors->setLightManagement(false);

    connect(m_closeLeftDoors,SIGNAL(buttonClicked()),this,SLOT(closeLeft()));
    connect(m_openLeftDoors,SIGNAL(buttonClicked()),this,SLOT(openLeft()));
    connect(m_closeRightDoors,SIGNAL(buttonClicked()),this,SLOT(closeRight()));
    connect(m_openRightDoors,SIGNAL(buttonClicked()),this,SLOT(openRight()));
    connect(m_selectLeftDoors,SIGNAL(buttonClicked()),this,SLOT(enableLeftPanel()));
    connect(m_selectRightDoors,SIGNAL(buttonClicked()),this,SLOT(enableRightPanel()));
}

Doors_Controller::~Doors_Controller(){}

void Doors_Controller::openLeft(){
    m_subte->openLeftDoors();
    updateLeft();
}

void Doors_Controller::closeLeft(){
    m_subte->closeLeftDoors();
    updateLeft();
}

void Doors_Controller::openRight(){
    m_subte->openRightDoors();
    updateRight();
}

void Doors_Controller::closeRight(){
    m_subte->closeRightDoors();
    updateRight();
}

void Doors_Controller::enableLeftPanel(){
    if(!m_selectLeftDoors->buttonState()){
        updateLeft();
    }else{
        m_closeLeftDoors->setClickeable(false);
        m_openLeftDoors->setClickeable(false);
        m_closeLeftDoors->turnOff();
        m_openLeftDoors->turnOff();
    }
}

void Doors_Controller::enableRightPanel(){
    if(!m_selectRightDoors->buttonState()){
        updateRight();
    }else{
        m_closeRightDoors->setClickeable(false);
        m_openRightDoors->setClickeable(false);
        m_closeRightDoors->turnOff();
        m_openRightDoors->turnOff();
    }
}

void Doors_Controller::updateLeft(){
    if(m_subte->leftDoors()){
        m_closeLeftDoors->turnOff();
        m_openLeftDoors->turnOn();
    }else{
        m_closeLeftDoors->turnOn();
        m_openLeftDoors->turnOff();
    }
    m_closeLeftDoors->setClickeable(m_subte->leftDoors());
    m_openLeftDoors->setClickeable(!m_subte->leftDoors());
}

void Doors_Controller::updateRight(){
    if(m_subte->rightDoors()){
        m_closeRightDoors->turnOff();
        m_openRightDoors->turnOn();
    }else{
        m_closeRightDoors->turnOn();
        m_openRightDoors->turnOff();
    }
    m_closeRightDoors->setClickeable(m_subte->rightDoors());
    m_openRightDoors->setClickeable(!m_subte->rightDoors());
}
