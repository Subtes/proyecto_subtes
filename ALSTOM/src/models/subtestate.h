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
};

#endif // SUBTESTATE_H
