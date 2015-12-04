#include "doors.h"

Doors::Doors()
{
    reset();
}

Doors::~Doors()
{

}

void Doors::setHandler(Base_EventHandler * eventHandler)
{
    m_eventHandler = eventHandler;
}

void Doors::reset()
{
    m_leftDoors = CLOSE;
    m_rightDoors = CLOSE;
    m_bypass = false;
    m_averia = false;
    m_parkingBrake = false;
}

bool Doors::evalCircuit()
{
    if (m_bypass) return true;
    if(m_averia) return false;
    if(m_parkingBrake) return false;
    return !m_leftDoors && !m_rightDoors;
}

bool Doors::getBypass() const
{
    return m_bypass;
}

void Doors::setBypass(bool value)
{
    m_bypass = value;
}

bool Doors::averia() const
{
    return m_averia;
}

void Doors::setAveria(bool averia)
{
    m_averia = averia;
}

bool Doors::leftDoors() const
{
    return m_leftDoors;
}

bool Doors::rightDoors() const
{
    return m_rightDoors;
}

void Doors::openLeftDoors()
{
    m_leftDoors = OPEN;
}

void Doors::openRightDoors()
{
    m_rightDoors = OPEN;
}

void Doors::closeLeftDoors()
{
    m_leftDoors = CLOSE;
}

void Doors::closeRightDoors()
{
    m_rightDoors = CLOSE;
}

bool Doors::parkingBrake() const
{
    return m_parkingBrake;
}

void Doors::setParkingBrake(bool parkingBrake)
{
    m_parkingBrake = parkingBrake;
}

void Doors::notifyActionLeftDoors(bool state)
{
    if (state)
        m_eventHandler->notifyValueChanged(NOMBRE_PUERTAS, LADO_IZ + ';' + ACCION_ABR);
    else
        m_eventHandler->notifyValueChanged(NOMBRE_PUERTAS, LADO_IZ + ';' + ACCION_CRR);
}

void Doors::notifyActionRightDoors(bool state)
{
    if (state)
        m_eventHandler->notifyValueChanged(NOMBRE_PUERTAS, LADO_DE + ';' + ACCION_ABR);
    else
        m_eventHandler->notifyValueChanged(NOMBRE_PUERTAS, LADO_DE + ';' + ACCION_CRR );
}
