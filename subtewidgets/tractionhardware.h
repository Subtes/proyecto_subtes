#ifndef TRACTIONHARDWARE_H
#define TRACTIONHARDWARE_H

#include <QObject>
#include <QTimer>

#include "SDL.h"
#undef main

class TractionHardware : public QObject
{
    Q_OBJECT
public:
     TractionHardware();
    ~TractionHardware();
    void getdata();

signals:
    positionChanged(int);
    manDiedPressed();
    manDiedReleased();

public slots:
    void processValueChanged();

private:
    SDL_Joystick *m_joystick;
    QList<int> axis;
    QList<bool> buttons;
    QString joystickName(int id);

    int m_neutral;
    int m_neutralLower;
    int m_neutralTop;
    int m_breakEmergency;
    int m_maxInterval;
    int m_minInterval;

    int m_traction;
    int m_value;
    int m_rangoT;
    int m_rangoB;

    bool m_diedMan;


};

#endif // TRACTIONHARDWARE_H
