#include "alstomtcms_controller.h"

AlstomTcms_Controller::AlstomTcms_Controller(SubteState * subte, AlstomTcms * tcms)
    : Base_Controller(subte)
{
    m_subte = subte;
    m_alstomtcms = tcms;
    cantwagons=6;
    doorsXwagon=8;
    abrir_puertas=0;
    cerrar_puertas=1;

    m_alstomtcms->setMinMaxValue(0,120);
    m_alstomtcms->setMaxAngle(259);
    m_alstomtcms->setOffsetAngle(-40);
    m_alstomtcms->updateNeedle(0);

    connect(m_subte,SIGNAL(speedChanged(double)),this,SLOT(updateNeedle(double)));
    connect(m_subte,SIGNAL(speedChanged(double)),this,SLOT(updateDigitalVelocity(double)));
    connect(m_subte,SIGNAL(voltChanged(double)),this,SLOT(updateDigitalVoltimetroLeft(double)));
    connect(m_subte,SIGNAL(voltChanged(double)),this,SLOT(updateDigitalVoltimetroRight(double)));
    connect(m_subte,SIGNAL(ampsChanged(double)),this,SLOT(updateDigitalAmperimetro(double)));
    connect(m_subte,SIGNAL(DoorsChanged(bool)),this,SLOT(logicaPuertas(bool)));
}

AlstomTcms_Controller::~AlstomTcms_Controller()
{

}

void AlstomTcms_Controller::updateNeedle(double velocity){
    qDebug()<<"velocidad"<<velocity;
    m_alstomtcms->updateNeedle(velocity);
}

void AlstomTcms_Controller::updateDigitalVelocity(double velocity){
    qDebug()<<"velocidad"<<velocity;
    m_alstomtcms->updateDigitalVelocity(velocity);
}

void AlstomTcms_Controller::updateDigitalVoltimetroLeft(double voltL){
    qDebug()<<"voltL"<<voltL;
    m_alstomtcms->updateDigitalVoltimetroLeft(voltL);
}

void AlstomTcms_Controller::updateDigitalVoltimetroRight(double voltR){
    qDebug()<<"voltR"<<voltR;
    m_alstomtcms->updateDigitalVoltimetroRight(voltR);
}

void AlstomTcms_Controller::updateDigitalAmperimetro(double amper){
    qDebug()<<"amper"<<amper;
    m_alstomtcms->updateDigitalAmperimetro(amper);
}

void AlstomTcms_Controller::recorridoPuertasVagon(QString stateDoors){
    int cantdoors = 0;
    for (int wagon = 0; wagon < cantwagons; wagon++) {
        for (int door = 0; door < doorsXwagon; door++) {
            verificoEstPuertas(stateDoors,cantdoors);
            cantdoors++;
        }
    }
}

void AlstomTcms_Controller::logicaPuertas(bool state){
    if(m_subte->leftDoors()){
        recorridoDePuertas_1Der_2Izq("closedoors");
        Sleep(1000);
        recorridoDePuertas_1Der_2Izq("doornotclosedandnotopened");
        Sleep(1000);
        recorridoDePuertas_1Der_2Izq("opendoors");
    }else{
        recorridoDePuertas_1Der_2Izq("closedoors");
        Sleep(1000);
        recorridoDePuertas_1Der_2Izq("doornotclosedandnotopened");
        Sleep(1000);
        recorridoDePuertas_1Der_2Izq("opendoors");
    }

    if(m_subte->rightDoors()){
        recorridoDePuertas_1Izq_2Der("closedoors");
        Sleep(1000);
        recorridoDePuertas_1Izq_2Der("doornotclosedandnotopened");
        Sleep(1000);
        recorridoDePuertas_1Izq_2Der("opendoors");
    }else{
        recorridoDePuertas_1Izq_2Der("closedoors");
        Sleep(1000);
        recorridoDePuertas_1Izq_2Der("doornotclosedandnotopened");
        Sleep(1000);
        recorridoDePuertas_1Izq_2Der("opendoors");
    }
}

void AlstomTcms_Controller::verificoEstPuertas(QString state, int canrdoors){
    if(state=="closedoors"){
        m_alstomtcms->closedoors(canrdoors);}
    if(state=="doornotclosedandnotopened"){
        m_alstomtcms->doornotclosedandnotopened(canrdoors);}
    if(state=="opendoors"){
        m_alstomtcms->opendoors(canrdoors);}
    if(state=="obstacledetected"){
        m_alstomtcms->obstacledetected(canrdoors);}
    if(state=="doorisolated"){
        m_alstomtcms->doorisolated(canrdoors);}
    if(state=="doorclosedandlocked"){
        m_alstomtcms->doorclosedandlocked(canrdoors);}
}

void AlstomTcms_Controller::recorridoDePuertas_1Der_2Izq(QString state){
 int cantPuertas=0;
    for (int var = 0; var < 6; var++) {
        for (int datos = 0; datos < 4; datos++) {
            verificoEstPuertas(state,cantPuertas); //las puertas
            cantPuertas++;
        }
        cantPuertas = cantPuertas + 4;
    }
}

void AlstomTcms_Controller::recorridoDePuertas_1Izq_2Der(QString state){
 int cantPuertas=0;
    for (int var = 0; var < 6; var++) {
        cantPuertas = cantPuertas + 4;
        for (int datos = 0; datos < 4; datos++) {
            verificoEstPuertas(state,cantPuertas); //las puertas
            cantPuertas++;
        }
    }
}
