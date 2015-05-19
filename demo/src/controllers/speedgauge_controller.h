#ifndef SPEEDGAUGE_CONTROLLER_H
#define SPEEDGAUGE_CONTROLLER_H
#include "speedgauge.h"
#include "src/models/subtestatus.h"

class SpeedGauge_Controller : public QObject
{
    Q_OBJECT

private:
    SubteStatus *m_subte;
    SpeedGauge * m_speedGauge;


public:
    SpeedGauge_Controller(SubteStatus *subte, SpeedGauge * speedGauge);
    ~SpeedGauge_Controller();

public slots:
    void updateNeedle(double speed);
};

#endif // SPEEDGAUGE_CONTROLLER_H
