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

private:
    bool horn;
    bool emergencyOverride;

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
};

#endif // SUBTESTATUS_H
