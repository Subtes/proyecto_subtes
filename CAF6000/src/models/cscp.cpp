#include "cscp.h"

CSCP::CSCP()
{
    m_leftDoors = CLOSE;
    m_rightDoors = CLOSE;
    m_bypass = false;
    m_averia = false;
}

CSCP::~CSCP()
{

}

void CSCP::reset()
{
    m_leftDoors = CLOSE;
    m_rightDoors = CLOSE;
    m_bypass = false;
    m_averia = false;
}

bool CSCP::evalCircuit()
{
    if (m_bypass) return true;
    if(m_averia) return false;
    return !m_leftDoors && !m_rightDoors;
}

bool CSCP::getBypass() const
{
    return m_bypass;
}

void CSCP::setBypass(bool value)
{
    m_bypass = value;
}

bool CSCP::averia() const
{
    return m_averia;
}

void CSCP::setAveria(bool averia)
{
    m_averia = averia;
}

bool CSCP::leftDoors() const
{
    return m_leftDoors;
}

bool CSCP::rightDoors() const
{
    return m_rightDoors;
}

void CSCP::openLeftDoors()
{
    m_leftDoors = OPEN;
}

void CSCP::openRightDoors()
{
    m_rightDoors = OPEN;
}

void CSCP::closeLeftDoors()
{
    m_leftDoors = CLOSE;
}

void CSCP::closeRightDoors()
{
    m_rightDoors = CLOSE;
}
