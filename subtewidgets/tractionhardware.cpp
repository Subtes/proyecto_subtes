#include <QDebug>
#include "tractionhardware.h"
#define POLL_INTERVAL 40

TractionHardware::TractionHardware()
{
    qDebug()<<"Entro en TractionHardware:   --->";
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    SDL_JoystickClose(0);
    m_joystick = SDL_JoystickOpen(0);
    if (m_joystick) {
        qDebug("Opened Joystick 0\n");
        qDebug("Name: %s\n", SDL_JoystickNameForIndex(0));
        qDebug("Number of Axes: %d\n", SDL_JoystickNumAxes(m_joystick));
        qDebug("Number of Buttons: %d\n", SDL_JoystickNumButtons(m_joystick));
        qDebug("Number of Balls: %d\n", SDL_JoystickNumBalls(m_joystick));
    } else {
        qDebug("Couldn't open Joystick 0\n");
    }

    m_minInterval = -20000;
    //m_speedMax = 104;
    m_neutral = 2642; //m_neutral = 522;
    m_neutralLower = 5000;
    m_neutralTop = -1000;
    //m_break = 909;
    m_breakEmergency = 15000; //m_breakEmergency = 973;
    m_maxInterval = 23000; //m_maxInterval = 1023;

    m_tDataReciver = new QTimer(this);
//    connect(m_tDataReciver,SIGNAL(timeout()),this,SLOT(processValueChanged(int,int,int)));

}
void TractionHardware::processValueChanged(/*int wich, int axis, int value*/){

    getdata();
    qDebug()<<"Valor: --->  "<< (this->axis.at(1));
    //emit traction(this->axis.at(1));
    int value = this->axis.at(1);

    //if (axis == 1){
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
    //}

}

void TractionHardware::getdata(){

    axis.clear();
    buttons.clear();

    SDL_Event event;
    SDL_PollEvent(&event);

    for(int i=0;i<SDL_JoystickNumAxes(m_joystick);i++)
    {
        axis.append(SDL_JoystickGetAxis(m_joystick,i));
    }

    for(int i=0;i<SDL_JoystickNumButtons(m_joystick);i++)
    {
        buttons.append(SDL_JoystickGetButton(m_joystick,i));
    }

}
TractionHardware::~TractionHardware(){
    axis.clear();
    buttons.clear();
    SDL_JoystickClose(m_joystick);
    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    this->deleteLater();
}

void TractionHardware::onJoystick(){
    m_tDataReciver->start(500);
}
