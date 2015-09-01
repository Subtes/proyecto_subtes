#ifndef BRAKEBYPASS_CONTROLLER_H
#define BRAKEBYPASS_CONTROLLER_H

#include "base_controller.h"
#include "singlebutton.h"

class BrakeBypass_Controller : public Base_Controller
{
    Q_OBJECT

public:
    BrakeBypass_Controller(SubteStatus *subte, SingleButton *button);
    ~BrakeBypass_Controller();

private:
    SingleButton *m_button;

public slots:
    void bypassBrakePressed();
    void bypassBrakeReleased();
    void updateHiloLazoStatus(bool status);
};

#endif // BRAKEBYPASS_CONTROLLER_H
