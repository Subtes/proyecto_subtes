#ifndef SUBTESTATEBASE_H
#define SUBTESTATEBASE_H

#include <QObject>
#include "doors.h"
#include "traction.h"
#include "automatictrainprotection.h"
#include "brakes.h"

class SubteStateBase : public QObject
{
        Q_OBJECT
public:
    static const bool PUERTAS_CERRADAS = false;
    static const bool PUERTAS_ABIERTAS = true;

    SubteStateBase();
    ~SubteStateBase();
    void reset();

    //Public setters
    void setHandler(Base_EventHandler *eventHandler);

    //Public getters
    double speed() const;
    double getCylinderPressure() const;
    double getMainPressure() const;
    bool getHiloLazo();
    int traction() const;
    int brake() const;
    bool emergencyBrake() const;
    bool doorsCircuit() const;
    bool leftDoors() const;
    bool rightDoors() const;

public slots:
    //Slot setters
    bool updateSpeed(double value);
    void updateCylinderPreassure(double value);
    void updateMainPreassure(double value);
    void tractionReceived(int value);
    void brakeReceived(int value);
    void ATP_emergencyBrakeActivated();
    void ATP_emergencyBrakeReleased();
    void hombreMuertoPressed();
    void hombreMuertoReleased();
    void openRightDoors();
    void openLeftDoors();
    void closeLeftDoors();
    void closeRightDoors();
    void setaActivated();
    void setaDeactivated();
    void cutTraction();
    void enableTraction();
    void updateVolt(double value);
    void updateAmm(double value);
    void setRetentionBrakeBypass(bool state);
    void setRetentionBrake(bool state);

protected:
    //State vars
    double m_speed;
    double m_cylinder_pressure;
    double m_main_pressure;
    double  m_volts;
    double m_amps;
    bool m_seta;

    //Subsystems
    Base_EventHandler *m_eventHandler;
    Doors *m_cscp;
    Brakes *m_brake;
    AutomaticTrainProtection *m_atp;
    Traction *m_traction;

signals:
    //Gauges & States
    speedChanged(double speed);
    mainPressureChange(double s_effort);
    cylinderPressureChange(double s_effort);
    voltChanged(double s_effort);
    ampsChanged(double s_effort);
    retentionBrakeChanged(bool status);
    hiloLazoChanged(bool status);

    //Doors
    DoorsChanged(bool status);
    rightDoorsOpened();
    rightDoorsClosed();
    leftDoorsOpened();
    leftDoorsClosed();

    //Atp
    atpOn();
    atpOff();
    modeOperation(int m);
};

#endif // SUBTESTATEBASE_H
