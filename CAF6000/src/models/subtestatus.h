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
    EventHandler *m_eventHandler;

    // SUBTE STATUS
    CSCP *m_cscp;
    Brake *m_brake;
    ATP_model *m_ATP_model;
    Traction *m_traction;
    double m_speed;
    double m_effort;
    double  m_volts;
    double m_amps;

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
    effortChanged(double s_effort);
    voltChanged(double s_effort);
    ampsChanged(double s_effort);

    //Usado por ATP
    setaFired();

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
    void hornOn();
    void hornOff();
    void emergencyOverridePressed();
    void setaActivated();
    void setaDeactivated();
    void ranaAD();
    void ranaCERO();
    void ranaAT();
    void tractionLeverChanged(int value);
    void cutTraction();
    void enableTraction();
    void setBatteryConnector(bool status);
    void setConmutadorPuestaServicio(bool status);
    void setConmutadorPuestaServicioAutomatica(bool status);
    void setPantographConnector(bool status);
    void setCompressorAuxConnector(bool status);
    void setConverterConnector(bool status);
    void setMainCompressorConnector(bool status);
    void setLightingConnector(bool status);
    void setAirConnector(bool status);
    void setMegaphoneConnector(bool status);
    void setRetentionBrakeConnector(bool status);
    void updateEffort(double value);
    void updateVolt(double value);
    void updateAmm(double value);

};

#endif // SUBTESTATUS_H
