#include "traction.h"
#include <QDebug>

Traction::Traction(Brake *b, CSCP* c, ATP_model *a)
{
    m_brake = b;
    m_cscp = c;
    m_atp = a;

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

void Traction::reset()
{
    m_traction = 0;
    m_rana = RANA::CERO;
    m_hombreVivo = false;

    m_lastTraction = 0;
    m_position = 0;
    m_lastPosition = 0;
}

void Traction::setDirection(RANA r){
    m_rana = r;
}

int Traction::getTraction()
{
    if(!m_brake->braking()){
        if (m_cscp->evalCircuit()){
            if(m_atp->tractionReady()){
                if(m_rana != RANA::CERO){
                    if(m_hombreVivo){
                        return m_traction;
                    }else{
                        qDebug() << "==== m_hombreVivo released ==> traction blocked";
                    }
                }else{
                    qDebug() << "==== m_rana = CERO ==> traction blocked";
                }
            }else{
                qDebug() << "==== atp:  ==> traction blocked";
            }
        }else{
            qDebug() << "==== cscp no cerrado ==> traction blocked";
        }
    }else{
        qDebug() << "==== braking!  ==> traction blocked";
    }
    return 0;
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
