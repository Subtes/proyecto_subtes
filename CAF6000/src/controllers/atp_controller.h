#ifndef ATP_CONTROLLER_H
#define ATP_CONTROLLER_H

#include <QObject>

#include <atp.h>
#include "src/models/subtestatus.h"



class Atp_Controller : public QObject
{
    Q_OBJECT

public:
    Atp_Controller(SubteStatus *subte, Atp *view);
    ~Atp_Controller();

public slots:
    void updateTargetSpeed(double speed);
    void updateAllowedSpeed(double speed);
    void updateSpeed(double speed);
    void resetIndicator();
    void checkSpeedWayAllowed(double);
    void checkSpeedWayTarget(double);
    void setTimerAllowed(int);

signals:
    enableTraction();
    disableTraction();

private:
    Atp * m_view;
    SubteStatus *m_subte;
    QTimer *m_timer_ATP_Allowed;
    double m_speedAllowed;
};

#endif // ATP_CONTROLLER_H
