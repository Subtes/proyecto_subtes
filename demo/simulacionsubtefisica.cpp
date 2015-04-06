#include "simulacionsubtefisica.h"
#include <math.h>

SimulacionSubteFisica::SimulacionSubteFisica(SubteStatus *subte)
{
    m_speed = 0;
    m_initialSpeed = 0;
    m_currentTraction = 0;
    m_time = 0;

    m_subte = subte;
    m_timer = new QTimer(this);

    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateTime()));

    m_timer->start(50);
}

SimulacionSubteFisica::~SimulacionSubteFisica()
{

}

void SimulacionSubteFisica::updateTraction(int traction)
{
    m_currentTraction = traction;
    qDebug() << "(simulacion_SubteFisica) SLOT UPDATE TRACTION: (m_currentTraction)"<< m_currentTraction;
    m_time = 0;
    updateStatus();
}

void SimulacionSubteFisica::updateTime()
{
    m_time += 0.2;
    qDebug() << "(simulacion_SubteFisica) TIME OUT";
    qDebug() << "(simulacion_SubteFisica) TIME: (current)" << m_time;
    updateStatus();
}

void SimulacionSubteFisica::updateStatus()
{
    m_speed = (double)m_initialSpeed + (m_currentTraction/80)*m_time;

    qDebug() << "m_initialSpeed: "<< m_initialSpeed;
    qDebug() << "m_time: "<< m_time;
    qDebug() << "m_currentTraction: "<< m_currentTraction;
    qDebug() << "m_speed: "<< m_speed;

    if (m_speed != m_initialSpeed)
    {
        emit speedChanged(abs(m_speed));
        m_initialSpeed = m_speed;
        qDebug() << "(simulacion_SubteFisica) EMIT SPEED: "<< m_speed;
    }

}

