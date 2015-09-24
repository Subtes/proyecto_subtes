#include "tractionhardware.h"

TractionHardware::TractionHardware(QObject *parent/*, HardwareEvent *hw */) : QObject(parent)
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);

    m_minInterval = -20000;
    m_speedMax = 104;
    m_neutral = 2642; //m_neutral = 522;
    m_neutralLower = 5000;
    m_neutralTop = -1000;
    m_break = 909;
    m_breakEmergency = 15000; //m_breakEmergency = 973;
    m_maxInterval = 23000; //m_maxInterval = 1023;

//    connect (he,SIGNAL(updateJoyAxis(int wich, int axis, int value)),this,SLOT(processValueChanged(int wich, int axis, int value)));
//    connect (,SIGNAL(valueChanged(int)),this,SIGNAL(positionChanged(int)));
//    connect (he,SIGNAL(updateJoyButton()),this,SIGNAL(hvPressed()));
//    connect (he,SIGNAL(updateJoyButton()),this,SIGNAL(hvReleased()));
}
void TractionHardware::processValueChanged(int wich, int axis, int value){

    if (axis == 1){
        if(value < m_neutralTop){
            int tr = static_cast<int>((value*85)/-20000);
            emit traction(tr);
        }else if((value <= m_neutralLower)&&(value >= m_neutralTop)){
            emit traction(0);
            emit brake(0);
        }else if ((value < m_breakEmergency) && (value >= m_neutralLower)){
            int br = static_cast<int>((value*80)/15000);
            emit brake(br);
        }else if (value >= m_breakEmergency){
            emit emergencyBrake();
        }
    }
}
