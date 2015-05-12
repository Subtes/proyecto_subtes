#ifndef SUBTESTATUS_H
#define SUBTESTATUS_H
#include <QObject>
#include <QDebug>

class SubteStatus : public QObject
{
    Q_OBJECT

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
    
    bool tractionable();

signals:
    CSCPChanged(bool cscp);

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
};

#endif // SUBTESTATUS_H
