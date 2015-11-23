#ifndef SUBTESTATE_H
#define SUBTESTATE_H

#include <QObject>
#include "src/controllers/eventhandler.h"

class EventHandler;

class SubteState : public QObject
{
    Q_OBJECT

private:
    EventHandler *m_eventHandler;
    bool hombreMuerto = false;
    void updateTraction(double value);

    //ALSTOMTCMS
        double m_needleVelocityTcms;
        double m_voltimetroLeft;
        double m_voltimetroRight;
        double m_amperimetro;

signals:
   velocityChangeTcms(double velocity);
   voltimetroChangeLeft(double voltL);
   voltimetroChangeRight(double voltR);
   amperimetroChange(double amper);


public:
    SubteState();
    ~SubteState();
    void setHandler(EventHandler *eventHandler);

public slots:
    void hmPressed();
    void hmReleased();
    void setTraction(int);
    void setBrake(int);
    void setEmergencyBeake(bool);
    void setMode(int value);
    void updateneedleVelocityTcms(double value);
    void updateVoltimetroLeftTCMS(double value);
    void updateVoltimetroRightTCMS(double value);
    void updateneedleamperimetro(double value);
};

#endif // SUBTESTATE_H
