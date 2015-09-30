#include <QDebug>
#include "tractionhardware.h"
#define POLL_INTERVAL 40

TractionHardware::TractionHardware()
{
    qDebug()<<"Entro en Seteo TractionHardware:   --->";
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    SDL_JoystickClose(0);
    m_joystick = SDL_JoystickOpen(0);

    if (m_joystick) {
        qDebug("Opened Joystick 0\n");
        //qDebug("Name: %s\n", SDL_JoystickNameForIndex(0));
        qDebug("Number of Axes: %d\n", SDL_JoystickNumAxes(m_joystick));
        qDebug("Number of Buttons: %d\n", SDL_JoystickNumButtons(m_joystick));
        qDebug("Number of Balls: %d\n", SDL_JoystickNumBalls(m_joystick));
    } else {
        qDebug("Couldn't open Joystick 0\n");
    }

    m_minInterval = 23000; //m_minInterval = 973;
    m_neutral = 2642; //m_neutral = 522;
    m_neutralLower = 4500;
    m_neutralTop = -1000;
    m_breakEmergency = 20500;
    m_maxInterval = -23000; //m_maxInterval = 104;

    m_traction = 0;
    m_value = 0;
    m_diedMan = false;

    m_rangoT = m_maxInterval - m_neutral;
    m_rangoB = m_minInterval - m_neutral;

}

void TractionHardware::processValueChanged(){

    getdata();
    qDebug()<<"Valor: --->  "<< (this->axis.at(0));
    m_value = this->axis.at(0);
    m_diedMan = this->buttons.at(0);

    if (m_value < m_neutral){
        m_traction = static_cast<int>(((m_value-m_neutral)*100)/m_rangoT);
        qDebug()<<"Valor TRACCION Emitido TH: --->  "<< m_traction;
    }else{
        m_traction = -(static_cast<int>(((m_value-m_neutral)*100)/m_rangoB));
        qDebug()<<"Valor BRAKE Emitido TH: --->  "<< m_traction;
    }

    emit positionChanged(m_traction);

    if (m_diedMan){
        emit manDiedPressed();
    }else{
        emit manDiedReleased();
    }

}

void TractionHardware::getdata(){

    axis.clear();
    buttons.clear();

    SDL_Event event;
    SDL_PollEvent(&event);

    axis.append(SDL_JoystickGetAxis(m_joystick,1));

    //bool estado = SDL_JoystickGetButton(m_joystick,i);
    buttons.append(SDL_JoystickGetButton(m_joystick,0));
}

TractionHardware::~TractionHardware(){
    axis.clear();
    buttons.clear();
    SDL_JoystickClose(m_joystick);
    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    this->deleteLater();
}

