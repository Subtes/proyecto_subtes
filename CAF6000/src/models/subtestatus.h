#ifndef SUBTESTATUS_H
#define SUBTESTATUS_H
#include <QObject>
#include <QDebug>
#include <ENetClient.h>

class SubteStatus : public QObject
{
    Q_OBJECT

    static const string serverIp = "127.0.0.1";
    static const int serverPort = 5000;

    static const string controlsHostName = "P1_control";
    static const string visualHostName = "P1_visualizador";
    static const string instructionsHostName = "P1_instruccion";

public:
    SubteStatus();
    ~SubteStatus();

    bool CSCPStatus();

private:
    static const bool OPEN = true;
    static const bool CLOSE = false;

    bool horn;
    bool emergencyOverride;
    bool leftDoors;
    bool rightDoors;
    bool CSCP;
    bool m_seta;  
    double speed;

    void processValueChanged(std::string unHost, std::string unaClave, std::string unValor);

signals:
    CSCPChanged(bool cscp);
    speedChanged(double speed);

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
