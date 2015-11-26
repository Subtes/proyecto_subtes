#include "alstomtcms_controller.h"

AlstomTcms_Controller::AlstomTcms_Controller(SubteState * subte, AlstomTcms * tcms)
    : Base_Controller(subte)
{
    qDebug()<<"3";
    m_subte = subte;
    qDebug()<<"4";

    m_alstomtcms = tcms;
    qDebug()<<"5";

    m_alstomtcms->setMinMaxValue(0,120);
    qDebug()<<"6";

    m_alstomtcms->setMaxAngle(259);
    qDebug()<<"7";

    m_alstomtcms->setOffsetAngle(-40);
    qDebug()<<"8";

    m_alstomtcms->updateNeedle(0);

    connect(m_subte,SIGNAL(velocityChangeTcms(double)),this,SLOT(updateNeedle(double)));
    connect(m_subte,SIGNAL(velocityChangeTcms(double)),this,SLOT(updateDigitalVelocity(double)));

    connect(m_subte,SIGNAL(voltimetroChangeLeft(double)),this,SLOT(updateDigitalVoltimetroLeft(double)));
    connect(m_subte,SIGNAL(voltimetroChangeRight(double)),this,SLOT(updateDigitalVoltimetroRight(double)));
    connect(m_subte,SIGNAL(amperimetroChange(double)),this,SLOT(updateDigitalAmperimetro(double)));


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


