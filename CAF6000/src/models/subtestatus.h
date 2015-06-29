#ifndef SUBTESTATUS_H
#define SUBTESTATUS_H

#include <QObject>
#include <QDebug>
#include <QtXml>
#include <QFile>
#include <QSplashScreen>
#include <QPixmap>

#include "src/controllers/eventhandler.h"
#include "src/models/cscp.h"
#include "src/models/brake.h"
#include "src/models/traction.h"
#include "src/models/atp_model.h"


class EventHandler;

class SubteStatus : public QObject
{
    Q_OBJECT

private:
    bool splashPassed;
    QSplashScreen *m_splash = NULL;
    QPixmap m_pixMapSplash;

    EventHandler *m_eventHandler;

    // SUBTE STATUS
    CSCP *m_cscp;
    Brake *m_brake;
    ATP_model *m_ATP_model;
    Traction *m_traction;
    double m_speed;

    // CONTROL STATUS
    bool m_horn;
    bool m_emergencyOverride;
    bool m_seta;
    std::string m_rana;

signals:
    // STATE CHANGE NOTIFICATION
    speedChanged(double s_speed);
    allowedSpeedChanged(double s_speed);
    targetSpeedChanged(double s_speed);

public:
    SubteStatus();
    ~SubteStatus();

    void setHandler(EventHandler *eventHandler);
    void reset();

    // STATUS GETTERS
    bool cscp() const;
    double speed() const;
    double targetSpeed() const;
    double allowedSpeed() const;
    int traction() const;
    int brake() const;
    bool emergencyBrake() const;

    // CONTROL GETTERS
    bool horn() const;
    bool emergencyOverride() const;
    bool seta() const;
    std::string rana() const;
    int tractionLeverPosition() const;

public slots:
    // STATE CHANGE INVOCATIONS - SETTERS
    void updateSpeed(double value);
    void updateTargetSpeed(double value);
    void updateAllowedSpeed(double value);
    void wiperOn();
    void wiperOff();
    void washer();
    void tractionReceived(int value);
    void brakeReceived(int value);
    void emergencyBrakeActived();
    void emergencyBrakeReleased();
    void hombreVivoPressed();
    void hombreVivoReleased();
    void CSCPBypassed();
    void CSCPActivated();
    void openRightDoors();
    void openLeftDoors();
    void closeLeftDoors();
    void closeRightDoors();
    void pressedCON();
    void pressedDES();
    void loadFinish();
    void hornOn();
    void hornOff();
    void emergencyOverridePressed();
    void setaActivated();
    void setaDeactivated();
    void ranaAD();
    void ranaCERO();
    void ranaAT();
    void tractionLeverChanged(int value);
};

#endif // SUBTESTATUS_H
