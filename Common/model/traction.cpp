#include "traction.h"

Traction::Traction()
{
    reset();
}

Traction::~Traction()
{
}


void Traction::linkBrake(Brakes *b){
    m_brake = b;
}

void Traction::linkCSCP(Doors *c){
    m_doors = c;
}

void Traction::linkATP(AutomaticTrainProtection *a){
    m_atp = a;
}

void Traction::setHandler(Base_EventHandler * eventHandler)
{
    m_eventHandler = eventHandler;
}

void Traction::reset()
{
    m_traction = 0;
    m_rana = TRACTION_MODE::NEUTRO;
    m_hombreMuerto = false;
    m_lastTraction = 0;
    m_averia = false;
}

void Traction::setDirection(TRACTION_MODE r){
    m_rana = r;
}

/**
 * @brief Traction::updateTraction: aca se decide si hay traccion o no.
 */
int Traction::getTraction()
{
    if(debuguear){
        if(m_averia)
            qDebug() << "averia en traccion";
        if(m_brake->braking())
            qDebug() << "coche frenando";
        if (!m_doors->evalCircuit())
            qDebug() << "CSCP abierto";
        if(!m_atp->tractionReady())
            qDebug() <<  "atp bloquea traccion";
        if(m_rana == TRACTION_MODE::NEUTRO)
            qDebug() << "rana en NEUTRO";
        if(!m_hombreMuerto)
            qDebug() << "Hombre Muerto NO cumplido";
    }

    if(!m_averia
       && !m_brake->braking()
       && m_doors->evalCircuit()
       && m_atp->tractionReady()
       && m_rana != TRACTION_MODE::NEUTRO
       && m_hombreMuerto){
        return m_traction;
    }else{
        return 0;
    }
}

/**
 * @brief Traction::updateTraction: se notifica solo si hay un cambio en la traccion
 * respecto a la ultima.
 */
void Traction::updateTraction(int traction)
{
    m_traction = traction;
    if(m_lastTraction != getTraction()){
        notifyTraction();
    }
}

bool Traction::hombreMuerto() const
{
    return m_hombreMuerto;
}

void Traction::setHombreMuerto(bool hombreMuerto)
{
    m_hombreMuerto = hombreMuerto;
    if(hombreMuerto){
        m_brake->setEmergencyBrake_HM(false);
    } else {
        m_brake->setEmergencyBrake_HM(true);
    }
    notifyHM();
}

bool Traction::averia() const
{
    return m_averia;
}

void Traction::setAveria(bool averia)
{
    m_averia = averia;
}

/**
 * @brief Traction::updateTraction: en caso de que la diferencia entre la ultima traccion emitida y
 * la nueva sea mayor a 5, se notifica el cambio en blackboard.
 * y se cierran las puertas
 */
void Traction::notifyTraction()
{
    double tractionToEmit = getTraction();
    if((tractionToEmit<SAFE_NEUTRAL_ZONE) || (abs(tractionToEmit - m_lastTraction) >= INTERVAL_EMISSION)){
        m_lastTraction = tractionToEmit;
        m_eventHandler->notifyValueChanged(NOMBRE_TRACCION,std::to_string(tractionToEmit));
    }
}

void Traction::notifyHM()
{
    if(m_hombreMuerto){
        m_eventHandler->notifyValueChanged(NOMBRE_HOMBRE_MUERTO,VALOR_HOMBRE_MUERTO_CON);
    } else {
        m_eventHandler->notifyValueChanged(NOMBRE_HOMBRE_MUERTO,VALOR_HOMBRE_MUERTO_DES);
    }
}
