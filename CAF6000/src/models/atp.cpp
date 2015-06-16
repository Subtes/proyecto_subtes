#include "atp.h"

ATP::ATP()
{
    m_allowedSpeed = 0;
    m_targetSpeed = 0;
    m_code = "";
}

ATP::~ATP()
{

}

bool ATP::tractionReady()
{
    return true;
}

void ATP::reset()
{
    m_allowedSpeed = 0;
    m_targetSpeed = 0;
    m_code = "";
}

double ATP::allowedSpeed() const
{
    return m_allowedSpeed;
}

void ATP::setAllowedSpeed(double allowedSpeed)
{
    m_allowedSpeed = allowedSpeed;
}

double ATP::targetSpeed() const
{
    return m_targetSpeed;
}

void ATP::setTargetSpeed(double targetSpeed)
{
    m_targetSpeed = targetSpeed;
}

std::string ATP::code() const
{
    return m_code;
}

void ATP::setCode(const std::string &code)
{
    m_code = code;
}
