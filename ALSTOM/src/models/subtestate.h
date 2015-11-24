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
    //Brakes *m_brakes;
    //Traction *m_traction;

    bool hombreMuerto = false;
    void updateTraction(double value);

    //ALSTOMTCMS
        double m_needleVelocityTcms;
        double m_voltimetroLeft;
        double m_voltimetroRight;
        double m_amperimetro;
        double m_valuedoors;

signals:
   velocityChangeTcms(double velocity);
   voltimetroChangeLeft(double voltL);
   voltimetroChangeRight(double voltR);
   amperimetroChange(double amper);
   doorsChange(double statedoors);

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
    void updatevaluedoors(double value);
    void setHongoEmergencia(bool state); //true=PRESSED
};

#endif // SUBTESTATE_H
