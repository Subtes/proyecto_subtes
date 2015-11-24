#include "brakes.h"

Brakes::Brakes()
{
    m_emergencyBrake_atp = false;
    m_emergencyBrake_setas = false;
    m_emergencyBrake_tractionLever = false;
    m_emergencyBrake_HM = false;
    m_brake = 0;
    m_lastBrake = 0;
    m_bypass = false;
    m_retentioBrake = false;
    m_anulacionFrenoRetencion = false;
    m_averia = false;
}

Brakes::~Brakes()
{
}

void Brakes::linkTraction(Traction *traction)
{
    m_traction = traction;
}

void Brakes::setHandler(EventHandler * eventHandler)
{
    m_eventHandler = eventHandler;
}

bool Brakes::braking()
{
    if (m_bypass){
        return false;
    }

    if(m_averia){
        return true;
    }

    return m_brake>0 || getEmergencyBrake();
}

void Brakes::reset()
{
    m_emergencyBrake_atp = false;
    m_emergencyBrake_setas = false;
    m_emergencyBrake_tractionLever = false;
    m_emergencyBrake_HM = false;
    m_brake = 0;
    m_lastBrake = 0;
    m_bypass = false;
    m_averia = false;
    m_retentioBrake = false;
    m_anulacionFrenoRetencion = false;
}

bool Brakes::getHiloLazo(){
    if (m_bypass)
        return true;

    return  m_traction->hombreMuerto() &&
            !m_averia &&
            !m_emergencyBrake_atp &&
            !m_emergencyBrake_setas &&
            !m_emergencyBrake_tractionLever;
}

bool Brakes::getEmergencyBrake() const
{
   if (m_bypass)
       return false;

    if (m_averia)
        return true;

    return m_emergencyBrake_atp || m_emergencyBrake_setas || m_emergencyBrake_tractionLever || m_emergencyBrake_HM;
}

void Brakes::setEmergencyBrake_atp(bool value)
{
    m_emergencyBrake_atp = value;
    notifyEmergencyBrake();
}

void Brakes::setEmergencyBrake_seta(bool value)
{
    m_emergencyBrake_setas = value;
    notifyEmergencyBrake();
}


void Brakes::setEmergencyBrake_HM(bool value)
{
    m_emergencyBrake_HM = value;
    notifyEmergencyBrake();
}

double Brakes::getBrake() const
{
    return m_brake;
}

void Brakes::setBrake(double value)
{
    if (value==100){
        m_brake = value;
        m_lastBrake = value;
        m_emergencyBrake_tractionLever = true;
        notifyEmergencyBrake();
    } else if((value<10) || (abs(value - m_lastBrake) >= 3)){
        if (m_emergencyBrake_tractionLever){
            m_emergencyBrake_tractionLever = false;
            notifyEmergencyBrake();
        }
        m_brake = value;
        notifyBrake();
        m_lastBrake = value;
    }
}

bool Brakes::bypass() const
{
    return m_bypass;
}

void Brakes::setBypass(bool status)
{
    m_bypass = status;
}

bool Brakes::retentioBrake() const
{
    if(m_anulacionFrenoRetencion)
        return false;

    return m_retentioBrake;
}

void Brakes::setRetentioBrake(bool retentioBrake)
{
    m_retentioBrake = retentioBrake;
}

bool Brakes::averia() const
{
    return m_averia;
}

void Brakes::setAveria(bool averia)
{
    m_averia = averia;
}

bool Brakes::anulacionFrenoRetencion() const
{
    return m_anulacionFrenoRetencion;
}

void Brakes::setAnulacionFrenoRetencion(bool anulacionFrenoRetencion)
{
    m_anulacionFrenoRetencion = anulacionFrenoRetencion;
}

void Brakes::notifyEmergencyBrake(){
    if (getEmergencyBrake()){
        //m_eventHandler->notifyValueChanged(NOMBRE_FRENO_EMERGENCIA,VALOR_CON_FRENO_EMERGENCIA);
    }else{
        //m_eventHandler->notifyValueChanged(NOMBRE_FRENO_EMERGENCIA,VALOR_DES_FRENO_EMERGENCIA);
    }
}

void Brakes::notifyBrake(){
    //m_eventHandler->notifyValueChanged(NOMBRE_FRENO,std::to_string(getBrake()));
}


