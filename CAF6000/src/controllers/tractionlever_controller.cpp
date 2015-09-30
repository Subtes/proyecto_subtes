#include "tractionlever_controller.h"

TractionLever_Controller::TractionLever_Controller(SubteStatus * subte, TractionLever * tractionLever, TractionHardware *th)
{
    m_subte = subte;
    m_tractionLever = tractionLever;
    m_tractionHardware = th;

    m_checkJ = new QTimer();
    m_checkJ->setInterval(50);

    connect(m_checkJ,SIGNAL(timeout()),m_tractionHardware,SLOT(processValueChanged()));
    connect(m_tractionHardware,SIGNAL(positionChanged(int)),this,SLOT(processValue(int)));
    connect(m_tractionLever,SIGNAL(positionChanged(int)),this,SLOT(processValue(int)));
    connect(m_tractionLever,SIGNAL(positionChanged(int)),m_subte,SLOT(tractionLeverChanged(int)));

    connect(this,SIGNAL(traction(int)),m_subte,SLOT(tractionReceived(int)));
    connect(this,SIGNAL(brake(int)),m_subte,SLOT(brakeReceived(int)));
    connect(this,SIGNAL(emergencyBrake()),m_subte,SLOT(emergencyBrakeActived()));
}

TractionLever_Controller::~TractionLever_Controller()
{

}

void TractionLever_Controller::setValue(int v)
{
    m_tractionLever->setValue(v);
}

void TractionLever_Controller::onTractionLever(){
    m_checkJ->start();
}

void TractionLever_Controller::offTractionLever(){
    m_checkJ->stop();
}

void TractionLever_Controller::processValue(int value){

    if (value > 100){
        qDebug()<<" Valor de Traction MAYOR a 100, Controlar! "<< value;
        value = 100;
    }else if (value < -100){
        qDebug()<<" Valor de Traction MAYOR a 100, Controlar! "<< value;
        value = -100;
    }

    if(value > 15){
        int tr = static_cast<int>((((double)value-15.0)/85.0)*100.0);
        emit traction(tr);
        m_tractionLever->setValue(value);
        qDebug()<<"Valor de Joystick:  ---TRACTION------>"<< value;
    }else if((value <= 15)&&(value >= -15)){
        emit traction(0);
        emit brake(0);
        qDebug()<<"Valor de Joystick:  ---BRAKE & TRACTION------> 0";
    }else if ((value < -15) && (value >= -95)){
        int br = static_cast<int>((((double)((-1)*value)-15.0)/80.0)*100.0);
        emit brake(br);
        m_tractionLever->setValue(value);
        qDebug()<<"Valor de Joystick:  ---BRAKE------>"<< value;
    }else if (value < -95){
        emit emergencyBrake();
        m_tractionLever->setValue(-100);
        qDebug()<<"Valor de Joystick:  ---BRAKE EMERGENCY!!!!!!------";
    }

}
