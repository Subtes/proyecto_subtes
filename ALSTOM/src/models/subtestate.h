#ifndef SUBTESTATE_H
#define SUBTESTATE_H

#include <QObject>
#include "src/controllers/eventhandler.h"
//#include "model/traction.h"
//#include "model/brakes.h"

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
    void setHongoEmergencia(bool state); //true=PRESSED
};

#endif // SUBTESTATE_H
