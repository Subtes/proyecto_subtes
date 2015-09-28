#ifndef TRACTIONHARDWARE_H
#define TRACTIONHARDWARE_H

#include <QObject>
#include <QTimer>

#include "../SDL/include/SDL.h"
#undef main

class TractionHardware : public QObject
{
    Q_OBJECT
public:
     TractionHardware();
    ~TractionHardware();
    void getdata();

signals:
    traction(int);
    brake(int);
    emergencyBrake();
    manDiedPressed();
    manDiedReleased();

public slots:
    void processValueChanged(/*int wich, int axis, int value*/);
    void onJoystick();

private:
    SDL_Joystick *m_joystick;
    QTimer *m_tDataReciver;
    QList<int> axis;
    QList<bool> buttons;
    QString joystickName(int id);

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
