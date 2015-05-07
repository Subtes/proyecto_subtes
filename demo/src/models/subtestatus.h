#ifndef SUBTESTATUS_H
#define SUBTESTATUS_H
#include <QObject>
#include <QDebug>

class SubteStatus : public QObject
{

    Q_OBJECT

public:
    static const bool DOORS_OPENED = true;
    static const bool DOORS_CLOSED = false;

    SubteStatus(double speed,bool right,bool left);
    ~SubteStatus();

    double getSpeed();
    double getTraction();
    bool getLeftDoor();
    bool getRightDoor();

private:
    double m_speed;
    int m_traction;
    bool m_leftDoor;
    bool m_rightDoor;

signals:
    void speedChanged(double speed);
    void tractionChanged(int traction);

public slots:
    void changeSpeed(double speed);
    void changeLeftDoor(bool status);
    void changeRightDoor(bool status);
    void updateTraction(int traction);
};



#endif // SUBTESTATUS_H
