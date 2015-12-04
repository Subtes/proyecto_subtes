#include "manometer_controller.h"

Manometer_Controller::Manometer_Controller(SubteStatus * subte, Manometer * manometer)
 : Base_Controller(subte)
{
    m_subte = subte;
    m_manometer = manometer;
    m_manometer->setBackgroudImage(QUrl("qrc:/resources/manometro_bkg.png"));
    m_manometer->setNeedleRedImage(QUrl("qrc:/resources/manometro_aguja_roja.png"),94,90);
    m_manometer->setNeedleWhiteImage(QUrl("qrc:/resources/manometro_aguja_blanca.png"),94,90);
    m_manometer->setGlassImage(QUrl("qrc:/resources/manometro_glass.png"));
    m_manometer->setMinMaxValue(0,12);
    m_manometer->setMaxAngle(259);
    m_manometer->setOffsetAngle(-40);
    m_manometer->updateNeedleRed(0);
    m_manometer->updateNeedleWhite(0);

    connect(m_subte,SIGNAL(cylinderPressureChange(double)),this,SLOT(updateCylinderPressure(double)));
    connect(m_subte,SIGNAL(mainPressureChange(double)),this,SLOT(updateMainPressure(double)));
}

Manometer_Controller::~Manometer_Controller()
{

}

void Manometer_Controller::updateMainPressure(double press){
    m_manometer->updateNeedleWhite(press);
}

void Manometer_Controller::updateCylinderPressure(double presscil){
    m_manometer->updateNeedleRed(presscil);
}
