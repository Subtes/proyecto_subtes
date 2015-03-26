#include "subtestatus.h"

SubteStatus::SubteStatus(double speed=0,bool right=false,bool left=false)
{
    m_speed = speed;
    m_leftDoor = left;
    m_rightDoor = right;
    m_traction = 0;
}

SubteStatus::~SubteStatus()
{
}

double SubteStatus::getSpeed(){
    return m_speed;
}

double SubteStatus::getTraction(){
    return m_traction;
}

bool SubteStatus::getLeftDoor(){
    return m_leftDoor;
}

bool SubteStatus::getRightDoor(){
    return m_rightDoor;
}

void SubteStatus::changeSpeed(double speed){
    m_speed=speed;
    qDebug() << "(subteStatus) SLOT CHANGE SPEED: (m_speed)"<< m_speed;
    emit speedChanged(m_speed);
}

void SubteStatus::changeLeftDoor(bool status){
    m_leftDoor=status;
}

void SubteStatus::changeRightDoor(bool status){
    m_rightDoor=status;
}

void SubteStatus::updateTraction(int traction){
    m_traction = traction;
    emit tractionChanged(m_traction);
    qDebug() << "(subteStatus) EMIT TRACTION CHANGED = " << m_traction;
}
