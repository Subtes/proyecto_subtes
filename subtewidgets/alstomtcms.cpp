#include "alstomtcms.h"
#include "ui_alstomtcms.h"

AlstomTcms::AlstomTcms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlstomTcms)
{
    ui->setupUi(this);
    m_qmlView = ui->qAlstomTcms->rootObject();

}

AlstomTcms::~AlstomTcms()
{
    delete ui;
}
void AlstomTcms::setMaxAngle(int angle)
{
    m_qmlView->setProperty("maxAngle",angle);
}

void AlstomTcms::setOffsetAngle(int angle)
{
    m_qmlView->setProperty("offsetAngle",angle);
}

void AlstomTcms::setMinMaxValue(int minV,int maxV)
{
    m_qmlView->setProperty("maxValue",maxV);
    m_qmlView->setProperty("minValue",minV);

}


void AlstomTcms::updateNeedle(double speed){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "updateNeedle",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, speed));
}

void AlstomTcms::updateDigitalVelocity(double speed){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "updateDigitalVelocity",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, speed));
}

void AlstomTcms::updateDigitalVoltimetroRight(double voltR){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "updateDigitalVoltimetroRight",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, voltR));
}

void AlstomTcms::updateDigitalVoltimetroLeft(double voltL){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "updateDigitalVoltimetroLeft",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, voltL));
}

void AlstomTcms::updateDigitalAmperimetro(double amper){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "updateDigitalAmperimetro",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, amper));
}


void AlstomTcms::closedoors(double doors){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "closedoors",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, doors));
}
void AlstomTcms::doornotclosedandnotopened(double doors){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "doornotclosedandnotopened",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, doors));
}

void AlstomTcms::opendoors(double doors){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "opendoors",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, doors));
}


void AlstomTcms::obstacledetected(double doors){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "obstacledetected",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, doors));
}
void AlstomTcms::doorisolated(double doors){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "doorisolated",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, doors));
}
void AlstomTcms::doorclosedandlocked(double doors){
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "doorclosedandlocked",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, doors));
}



