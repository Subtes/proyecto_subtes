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
    //MANOMETER NEEDLE
    double m_pressure_red;
    double m_pressure_white;


    // CONTROL STATUS
    bool m_horn;
    bool m_emergencyOverride;
    bool m_seta;
    std::string m_rana;

signals:
    // STATE CHANGE NOTIFICATION
    speedChanged(double speed);
    allowedSpeedChanged(double speed);
    targetSpeedChanged(double speed);
    tractionChanged(double traction);
    hiloLazoChanged(bool status);
    effortChanged(double s_effort);
    voltChanged(double s_effort);
    ampsChanged(double s_effort);
    CSCPChanged(bool status);
    manometerWhiteChange(double s_effort);
    manometerRedChange(double s_effort);

public:
    SubteStatus();
    ~SubteStatus();

    void setHandler(EventHandler *eventHandler);
    void reset();

    // STATUS GETTERS
    bool cscp() const;
    bool leftDoors() const; //true=open
    bool rightDoors() const; //true=open
    double speed() const;
    double targetSpeed() const;
    double allowedSpeed() const;
    int traction() const;
    int brake() const;
    bool emergencyBrake() const;
    bool getHiloLazo();

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
    void bypassBrake(bool status);
    void bypassCSCP(bool status);
    void updatePreassureRed(double value);
    void updatePreassureWhite(double value);
};

#endif // SUBTESTATUS_H
