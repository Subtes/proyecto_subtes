#include "brake.h"
#include <QDebug>

Brake::Brake()
{
    m_emergencyBrake = false;
    m_parkingBrake = false;
    m_brake = 0;
    m_lastBrake = 0;
    m_bypass = false;
    m_retentioBrake = false;
    m_anulacionFrenoRetencion = false;
    m_averia = false;
}

Brake::~Brake()
{
}

void Brake::linkTraction(Traction *traction)
{
    m_traction = traction;
}

bool Brake::braking()
{
    if (m_brake>0){
        qDebug() << "frenos > 0";
    }

    if (m_emergencyBrake){
        qDebug() << "freno de emergencia activado";
    }

    if (m_bypass) return false;
    if(m_averia) { qDebug() << "averia en frenos! frena el coche"; return true; }
    return m_brake>0 || m_emergencyBrake;
}

void Brake::reset()
{
    m_emergencyBrake = true;
    m_parkingBrake = false;
    m_brake = 0;
    m_lastBrake = 0;
    m_bypass = false;
    m_averia = false;
    m_retentioBrake = false;
    m_anulacionFrenoRetencion = false;
}

bool Brake::getEmergencyBrake() const
{
    if (!m_traction->hombreMuerto())
        return true;

    if (m_averia)
        return true;

    return m_emergencyBrake;
}

void Brake::setEmergencyBrake(bool value)
{
    m_emergencyBrake = value;
}

double Brake::getBrake() const
{
    return m_brake;
}

void Brake::setBrake(double value)
{
    m_brake = value;
}

bool Brake::parkingBrake() const
{
    return m_parkingBrake;
}

void Brake::setParkingBrake(bool parkingBrake)
{
    m_parkingBrake = parkingBrake;
}

double Brake::lastBrake() const
{
    return m_lastBrake;
}

void Brake::setLastBrake(double lastBrake)
{
    m_lastBrake = lastBrake;
}

bool Brake::bypass() const
{
    return m_bypass;
}

void Brake::setBypass(bool status)
{
    m_bypass = status;
}

bool Brake::retentioBrake() const
{
    if(m_anulacionFrenoRetencion)
        return false;

    return m_retentioBrake;
}

void Brake::setRetentioBrake(bool retentioBrake)
{
    m_retentioBrake = retentioBrake;
}

bool Brake::averia() const
{
    return m_averia;
}

void Brake::setAveria(bool averia)
{
    m_averia = averia;
}

bool Brake::anulacionFrenoRetencion() const
{
    return m_anulacionFrenoRetencion;
}

void Brake::setAnulacionFrenoRetencion(bool anulacionFrenoRetencion)
{
    m_anulacionFrenoRetencion = anulacionFrenoRetencion;
}
