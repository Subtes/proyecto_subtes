#ifndef SPEEDGAUGE_CONTROLLER_H
#define SPEEDGAUGE_CONTROLLER_H
#include "speedgauge.h"

class SpeedGauge_Controller : public QObject
{
    Q_OBJECT
private:
    SpeedGauge * m_speedGauge;


public:
    SpeedGauge_Controller(SpeedGauge * speedGauge);
    ~SpeedGauge_Controller();

public slots:
    void updateNeedle(float speed);
};

#endif // SPEEDGAUGE_CONTROLLER_H
