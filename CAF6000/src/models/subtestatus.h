#ifndef SUBTESTATUS_H
#define SUBTESTATUS_H
#include <QObject>
#include <QDebug>
#include <ENetClient.h>

#include <QtXml>
#include <QFile>

class SubteStatus : public QObject
{
    Q_OBJECT

public:
    SubteStatus();
    ~SubteStatus();
    void initENet();
    bool CSCPStatus();

private:
    static const bool OPEN = true;
    static const bool CLOSE = false;

    bool splashPassed;

    bool m_horn;
    bool m_emergencyOverride;
    bool m_leftDoors;
    bool m_rightDoors;
    bool m_CSCP;
    bool m_seta;  
    double m_speed;
    std::string m_rana;
    int m_traction;
    int m_lastTraction;
    int m_tractionLeverPosition;
    int m_lastPosition;

    //=== eNet setup ===
    ENetClient *m_eNetClient;
    std::string m_serverIp;
    int m_serverPort;
    std::string m_controlsHostName;
    std::string m_visualHostName;
    std::string m_instructionsHostName;

    void processValueChanged(std::string host, std::string key, std::string value);
    void updateSpeed(double value);
    void recalcularTraccion();
    void readIni();
    void conectarCliente(std::string ip, int puerto, std::string host);

signals:
    CSCPChanged(bool cscp);
    speedChanged(double speed);

    controlReady();
    controlEnable();
    controlDisable();
    controlReset();

public slots:
    void hornOn();
    void hornOff();
    void wiperOn();
    void wiperOff();
    void washer();
    void tractionLeverInZero();
    void tractionReceived(int value);
    void brakeReceived(int value);
    void emergencyBrakeActived();
    void hombreVivoPressed();
    void hombreVivoReleased();
    void tractionLeverChanged(int value);
    void ranaAD();
    void ranaCERO();
    void ranaAT();
    void emergencyOverrideClicked();
    void CSCPBypassed();
    void CSCPActivated();
    void openRightDoors();
    void openLeftDoors();
    void closeLeftDoors();
    void closeRightDoors();
    void setaActivated();
    void setaDeactivated();
    bool isSetaActivated();
    void pressedCON();
    void pressedDES();
};

#endif // SUBTESTATUS_H
