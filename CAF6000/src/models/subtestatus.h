#ifndef SUBTESTATUS_H
#define SUBTESTATUS_H

#include <QObject>
#include <QDebug>
#include <QtXml>
#include <QFile>
#include <QSplashScreen>
#include <QPixmap>
#include <QString>

#include "src/controllers/eventhandler.h"
#include "model/subtestatebase.h"

class EventHandler;

class SubteStatus : public SubteStateBase
{
    Q_OBJECT

private:
    double m_effort;

    // CONTROL STATUS
    bool m_horn;
    bool m_emergencyOverride;
    bool m_keyATP;
    std::string m_rana;

    // CMC:0 CL:1
    //TODO mover esto al ATP model
    int m_drivingMode;
    //m_sourceModoOFF:0 -- m_sourceModo:1 -- m_sourceModo20:2 -- m_sourceModoAs:3 -- m_sourceModoATO:4 -- m_sourceModoATP:5 -- m_sourceModoEEE

    int m_modeOperation;
    int m_estado_coche;

    //CONTROL AUXILIARY PANEL
    QString m_switch;

signals:
    // STATE CHANGE NOTIFICATION
    allowedSpeedChanged(double speed);
    targetSpeedChanged(double speed);
    effortChanged(double s_effort);

    estadoNormal();
    estadoManioAcople();

    senalDisyuntorDes();
    senalDisyuntorCon();
    conmutadorServicioAutomatic();
    conmutadorServicioManual();
    bateriaCon();
    bateriaDes();
    pantografoCon();
    pantografoDes();
    compresorAuxCon();
    compresorAuxDes();
    convertidorCon();
    convertidorDes();
    compresorPpalCon();
    compresorPpalDes();
    alumbradoCon();
    alumbradoDes();
    aireAcondicionadoCon();
    aireAcondicionadoDes();
    megafoniaCon();
    megafoniaDes();
    frenoEstacionamientoCon();
    frenoEstacionamientoDes();
    cabinChanged(int statecabin);
    modeDrivingChanged(int op);

    //AUXILIARY PANEL
    changeSwitch(QString t);

public:
    SubteStatus();
    ~SubteStatus();

    void reset();

    //STATUS GETTERS
    double targetSpeed() const;
    double allowedSpeed() const;

    //CONTROL GETTERS
    bool horn() const;
    bool emergencyOverride() const;
    bool seta() const;
    bool keyTopBoard() const;
    std::string rana() const;
    int getDrivingModeATP();

public slots:
    //STATE CHANGE INVOCATIONS - SETTERS
    bool updateSpeed(double value);
    void updateTargetSpeed(double value);
    void updateAllowedSpeed(double value);
    void wiperOn();
    void wiperOff();
    void washer();
    void disyuntoresCon();
    void disyuntoresDes();
    void hornOn();
    void hornOff();
    void emergencyOverridePressed();
    void keyActivated();
    void keyDeactivated();
    void ranaAD();
    void ranaCERO();
    void ranaAT();
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
    void setParkingBrakeConnector(bool status);
    void updateEffort(double value);
    void bypassBrake(bool status);
    void bypassCSCP(bool status);
    void updateLeftDoorsButtons(bool state);
    void updateRightDoorsButtons(bool state);
    void setTractionFailure();
    void setBrakeFailure();
    void setCSCPFailure();
    void resolveTractionFailure();
    void resolveBrakeFailure();
    void resolveCSCPFailure();
    void setManiobraMode();
    void setAtpMode();
    void setAcopleMode();
    void setSicasOk();
    // CMC, CL
    void setDrivingModeATP(int status);
    void setModeOperation(int m);
    void updatestatecabine(int state_cabine);
    //AUXILIARY PANELS
    void setSwitch(QString s);
};

#endif // SUBTESTATUS_H
