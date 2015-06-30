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

    this->setCMC(true);
}

void Atp::updateSpeed(double speed){

    QVariant returnedValue1;
    QVariant returnedValue2;
    int v = (int)speed;
    QMetaObject::invokeMethod(m_qmlView, "posLed",
                              Q_RETURN_ARG(QVariant,returnedValue1),
                              Q_ARG(QVariant, (v/2)));
    QMetaObject::invokeMethod(m_qmlView, "speedLCD",
                              Q_RETURN_ARG(QVariant,returnedValue2),
                              Q_ARG(QVariant, v));
    //qDebug() << "¡¡¡Atp::updateSpeed: posLed" << v;
}

void Atp::updateTargetSpeed(double speed){

    QVariant returnedValue;
    int v = (int)speed;
    QMetaObject::invokeMethod(m_qmlView, "targetSpeed",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    //qDebug() << "Atp::updateTargetSpeed: " << speed;
}

void Atp::updateAllowedSpeed(double speed){

    QVariant returnedValue;
    int v = ((int)speed/2);
    QMetaObject::invokeMethod(m_qmlView, "allowedSpeed",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    //qDebug() << "Atp::updateAllowedSpeed: " << v;
}

void Atp::setCMC(bool v){

    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "setCMC",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::setCMC: " << v;
}

void Atp::setCL(bool v){

    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "setCL",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::setCL: " << v;
}

void Atp::setFserv(bool v){

    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "setFserv",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::setFserv: " << v;
}

void Atp::setFrenoUrg(bool v){

    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "setFrenoUrg",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::setFrenoUrg: " << v;
}

void Atp::setCorte(bool v){

    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "setCorte",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::setCorte: " << v;
}

void Atp::setFalla(bool v){

    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "setFalla",
                              Q_RETURN_ARG(QVariant,returnedValue),
                              Q_ARG(QVariant, v));
    qDebug() << "Atp::setFalla: " << v;
}

Atp::~Atp()
{
    delete ui;
}
