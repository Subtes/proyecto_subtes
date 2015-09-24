#ifndef TRACTIONHARDWARE_H
#define TRACTIONHARDWARE_H

#include <QObject>
#include <QTimer>
#include "../Source/include/SDL.h"

class TractionHardware : public QObject
{
    Q_OBJECT
public:
    explicit TractionHardware(QObject *parent = 0);

signals:
    traction(int);
    brake(int);
    emergencyBrake();
    manDiedPressed();
    manDiedReleased();

public slots:
    void processValueChanged(int wich, int axis, int value);

private:
    SDL_Joystick *m_joy;
    QTimer *m_tDataReciver;
    int m_speedMax;
    int m_neutral;
    int m_neutralLower;
    int m_neutralTop;
    int m_break;
    int m_breakEmergency;
    int m_maxInterval;
    int m_minInterval;

};

#endif // TRACTIONHARDWARE_H
