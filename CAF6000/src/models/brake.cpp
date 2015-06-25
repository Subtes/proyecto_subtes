#include "brake.h"
#include <QDebug>

Brake::Brake()
{
    m_emergencyBrake = false;
    m_parkingBrake = false;
    m_brake = 0;
    m_lastBrake = 0;
}

Brake::~Brake()
{
    
}

bool Brake::braking()
{
    if( m_brake>0 ) qDebug() << "m_brake = " << m_brake;
    if( m_emergencyBrake ) qDebug() << "m_emergencyBrake = " << m_emergencyBrake;

    return ( m_brake>0 || m_emergencyBrake );
}

void Brake::reset()
{
    m_emergencyBrake = false;
    m_parkingBrake = false;
    m_brake = 0;
    m_lastBrake = 0;
}

bool Brake::getEmergencyBrake() const
{
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
