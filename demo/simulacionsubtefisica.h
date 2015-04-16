#ifndef SIMULACIONSUBTEFISICA_H
#define SIMULACIONSUBTEFISICA_H
#include <QObject>
#include <QTimer>
#include "src/models/subtestatus.h"

class SimulacionSubteFisica : public QObject
{
    Q_OBJECT

private:
    QTimer * m_timer;
    SubteStatus *m_subte;

    double m_speed;
    double m_initialSpeed;
    double m_currentTraction;
    double m_time;

    double acceleration(int traction);

public:
    SimulacionSubteFisica(SubteStatus *subte);
    ~SimulacionSubteFisica();

public slots:
    void updateTraction(int);
    void updateStatus();
    void updateTime();

signals:
    void speedChanged(double);
};

#endif // SIMULACIONSUBTEFISICA_H
