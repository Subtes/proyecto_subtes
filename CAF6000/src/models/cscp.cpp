#include "cscp.h"

CSCP::CSCP()
{
    m_leftDoors = CLOSE;
    m_rightDoors = CLOSE;
    bypass = false;
}

CSCP::~CSCP()
{

}

void CSCP::reset()
{
    m_leftDoors = CLOSE;
    m_rightDoors = CLOSE;
    bypass = false;
}

bool CSCP::evalCircuit()
{
    return bypass || (!m_leftDoors && !m_rightDoors);
}

bool CSCP::getBypass() const
{
    return bypass;
}

void CSCP::setBypass(bool value)
{
    bypass = value;
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
