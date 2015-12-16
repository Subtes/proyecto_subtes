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

    connect(m_subte,SIGNAL(velocityChangeTcms(double)),this,SLOT(updateNeedle(double)));
    connect(m_subte,SIGNAL(velocityChangeTcms(double)),this,SLOT(updateDigitalVelocity(double)));

    connect(m_subte,SIGNAL(voltimetroChangeLeft(double)),this,SLOT(updateDigitalVoltimetroLeft(double)));
    connect(m_subte,SIGNAL(voltimetroChangeRight(double)),this,SLOT(updateDigitalVoltimetroRight(double)));
    connect(m_subte,SIGNAL(amperimetroChange(double)),this,SLOT(updateDigitalAmperimetro(double)));
    connect(m_subte,SIGNAL(doorsChange(double)),this,SLOT(logicaPuertasSicas(double)));


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

void AlstomTcms_Controller::logicaPuertasSicas(double state){

    if (state == 0){
        recorridoPuertasVagon("closedoors");
        Sleep(1000);
        recorridoPuertasVagon("doornotclosedandnotopened");
        Sleep(1000);
        recorridoPuertasVagon("opendoors");
    }
    else if (state == 1){
        recorridoPuertasVagon("doornotclosedandnotopened");
        Sleep(1000);
        recorridoPuertasVagon("closedoors");
        Sleep(1000);
        recorridoPuertasVagon("doorclosedandlocked");
    }
    else if (state == 2){
        recorridoPuertasVagon("doorisolated");

    }
    else if (state == 3){
       recorridoPuertasVagon("obstacledetected");

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
