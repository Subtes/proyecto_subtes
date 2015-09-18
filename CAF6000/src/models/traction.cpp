#include "traction.h"
#include <QDebug>

Traction::Traction()
{
    m_traction = 0;
    m_rana = RANA::CERO;
    m_hombreVivo = false;

    m_lastTraction = 0;
    m_position = 0;
    m_lastPosition = 0;
}

Traction::~Traction()
{
}

void Traction::linkBrake(Brake *b){
    m_brake = b;
}

void Traction::linkCSCP(CSCP *c){
    m_cscp = c;
}

void Traction::linkATP(ATP_model *a){
    m_atp = a;
}

void Traction::reset()
{
    m_traction = 0;
    m_rana = RANA::CERO;
    m_hombreVivo = false;

    m_lastTraction = 0;
    m_position = 0;
    m_lastPosition = 0;

    m_averia = false;
}

void Traction::setDirection(RANA r){
    m_rana = r;
}

int Traction::getTraction()
{
    if(debuguear){
        if(m_averia)
            qDebug() << "averia en traccion";
        if(m_brake->braking())
            qDebug() << "coche frenando";
        if (!m_cscp->evalCircuit())
            qDebug() << "CSCP abierto";
        if(!m_atp->tractionReady())
            qDebug() <<  "atp bloquea traccion";
        if(m_rana == RANA::CERO)
            qDebug() << "rana en CERO";
        if(!m_hombreVivo)
            qDebug() << "Hombre Vivo NO cumplido";
    }

    if(!m_averia
       && !m_brake->braking()
       && m_cscp->evalCircuit()
       && m_atp->tractionReady()
       && m_rana != RANA::CERO
       && m_hombreVivo){
        return m_traction;
    }else{
        return 0;
    }
}

double Traction::updateTraction(int traction)
{
    m_traction = traction;
    return this->getTraction();
}

double Traction::updateTraction()
{
    m_traction = m_lastTraction;
    return this->getTraction();
}

void Traction::setLastTraction(int lastTraction)
{
    m_lastTraction = lastTraction;
}

int Traction::lastTraction() const
{
    return m_lastTraction;
}

void Traction::setPosition(int tractionLeverPosition)
{
    m_position = tractionLeverPosition;
}

int Traction::position() const
{
    return m_position;
}

void Traction::setLastPosition(int lastPosition)
{
    m_lastPosition = lastPosition;
}

int Traction::lastPosition() const
{
    return m_lastPosition;
}

bool Traction::hombreVivo() const
{
    return m_hombreVivo;
}

void Traction::setHombreVivo(bool hombreVivo)
{
    m_hombreVivo = hombreVivo;
}

bool Traction::averia() const
{
    return m_averia;
}

void Traction::setAveria(bool averia)
{
    m_averia = averia;
}
