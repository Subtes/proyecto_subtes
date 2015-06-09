#include "atp.h"
#include "ui_atp.h"

Atp::Atp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Atp)
{
    ui->setupUi(this);

    ui->atp_quickWidget->setClearColor(Qt::transparent);
    ui->atp_quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);

    this->m_qmlView = ui->atp_quickWidget->rootObject();
}

void Atp::updateSpeed(double speed){

    QVariant returnedValue1;
    QVariant returnedValue2;
    int v = ((int)speed/2);
    QMetaObject::invokeMethod(m_qmlView, "posLed",
                              Q_RETURN_ARG(QVariant,returnedValue1),
                              Q_ARG(QVariant, v));
    QMetaObject::invokeMethod(m_qmlView, "targetSpeedLCD",
                              Q_RETURN_ARG(QVariant,returnedValue2),
                              Q_ARG(QVariant, speed));
    qDebug() << "¡¡¡Atp::updateSpeed: posLed" << v;
}

void Atp::updateTargetSpeed(double speed){

    QVariant returnedValue;
    int v = (int)speed;
    QMetaObject::invokeMethod(m_qmlView, "targetSpeed",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::updateTargetSpeed: " << v;
}

void Atp::updateAllowedSpeed(double speed){

    QVariant returnedValue;
    int v = (int)speed/2;
    QMetaObject::invokeMethod(m_qmlView, "allowedSpeed",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::updateAllowedSpeed: " << v;
}

Atp::~Atp()
{
    delete ui;
}
