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

    m_minInterval = 25635; //m_minInterval = 973;
    m_neutral = 642; //m_neutral = 522;
    m_neutralLower = 4500;
    m_neutralTop = -1000;
    m_breakEmergency = 20500;
    m_maxInterval = -26049; //m_maxInterval = 104;

    m_traction = 0;
    m_value = 0;
    m_diedMan = false;
    m_bypassBrake = false;
    m_bypassTraction = false;
    m_ranaAD = false;
    m_ranaAT = false;
    //m_ranaC = false;
    m_seta = false;
    m_keyTop = false;

    m_rangoT = m_maxInterval - m_neutral;
    m_rangoB = m_minInterval - m_neutral;

}

void TractionHardware::processValueChanged(){

    getdata();
    //qDebug()<<"Valor: --->  "<< (this->axis.at(0));
    m_value = this->axis.at(0);
    bool m_auXdiedMan = this->buttons.at(0);

    if (m_value < m_neutral){
        m_traction = static_cast<int>(((m_value-m_neutral)*100)/m_rangoT);
        //qDebug()<<"Valor TRACCION Emitido TH: --->  "<< m_traction;
    }else{
        m_traction = -(static_cast<int>(((m_value-m_neutral)*100)/m_rangoB));
        //qDebug()<<"Valor BRAKE Emitido TH: --->  "<< m_traction;
    }

    emit positionChanged(m_traction);

    if (m_diedMan != m_auXdiedMan){

        m_diedMan = m_auXdiedMan;
        if (m_diedMan){
            emit manDiedPressed();
        }else{
            emit manDiedReleased();
        }
    }
}

void TractionHardware::processBottonChanged(){

    getdata();

    bool m_auxBT = this->buttons.at(4);
    bool m_auxBB = this->buttons.at(5);

    if (m_bypassBrake != m_auxBB){

        m_bypassBrake = m_auxBB;

        if (m_bypassBrake){
            emit brakeBypassPressed();
            qDebug()<< "BOTON Bypass Freno presionado";
        }else{
            emit brakeBypassReleased();
            qDebug()<< "BOTON Bypass Freno soltado";
        }

    }

    if (m_bypassTraction != m_auxBT){

        m_bypassTraction = m_auxBT;

        if (m_bypassTraction){
            emit tractionBypassPressed();
            qDebug()<< "BOTON Bypass Traccion presionado";
        }else{
            emit tractionBypassReleased();
            qDebug()<< "BOTON Bypass Traccion soltado";
        }
    }

}

void TractionHardware::processRanaChanged(){

    getdata();
    bool m_auXranaAD = buttons.at(1);// && !buttons.at(2);
    bool m_auXranaAT = buttons.at(2);// && !buttons.at(1);
    //bool m_auXranaC = !buttons.at(1) && !buttons.at(2);

    if ((m_ranaAD != m_auXranaAD) || (m_ranaAT != m_auXranaAT)){
        int toEmit =0;

        m_ranaAD = m_auXranaAD;
        m_ranaAT = m_auXranaAT;

        if (m_ranaAT) toEmit = -1;
        if (m_ranaAD) toEmit = 1;

        emit ranaY(toEmit);
    }
}

void TractionHardware::processSetaChanged(){

    getdata();
    bool m_auXseta = buttons.at(3);

    if (m_seta != m_auXseta){

        m_seta = m_auXseta;
        if (m_seta){
            m_seta = m_auXseta;
            emit seta(1);
            qDebug()<< "SETA Joystick ON";
        }else{
            emit seta(0);
            qDebug()<< "SETA Joystick OFF";
        }
    }
}

void TractionHardware::processKeyTop(){
    getdata();
    bool m_auXkeyTop = buttons.at(7);

    if (m_keyTop != m_auXkeyTop){

        m_keyTop = m_auXkeyTop;
        if (m_keyTop){
            emit processKeyTop(1);
            qDebug()<< "SETA Joystick ON";
        }else{
            emit processKeyTop(0);
            qDebug()<< "SETA Joystick OFF";
        }
    }

}

void TractionHardware::getdata(){

    axis.clear();
    buttons.clear();

    SDL_Event event;
    SDL_PollEvent(&event);

    axis.append(SDL_JoystickGetAxis(m_joystick,1));

    for(int i=0;i<SDL_JoystickNumButtons(m_joystick);i++){
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
