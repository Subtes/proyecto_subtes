#ifndef DOORS_CONTROLLER_H
#define DOORS_CONTROLLER_H

#include "base_controller.h"
#include "singlebutton.h"

class Doors_Controller : public Base_Controller
{
    Q_OBJECT
public:
    Doors_Controller(SubteStatus *subte, SingleButton *openLeftDoors, SingleButton *closeLeftDoors, SingleButton *selectLeftDoors, SingleButton *openRightDoors, SingleButton *closeRightDoors, SingleButton *selectRightDoors, SingleButton *silbato);
    ~Doors_Controller();

public slots:
    void enableLeftPanel();
    void enableRightPanel();
    void openLeft();
    void closeLeft();
    void openRight();
    void closeRight();

private:
    SingleButton *m_selectLeftDoors;
    SingleButton *m_openLeftDoors;
    SingleButton *m_closeLeftDoors;
    SingleButton *m_selectRightDoors;
    SingleButton *m_openRightDoors;
    SingleButton *m_closeRightDoors;
    SingleButton *m_silbato;

    void updateLeft();
    void updateRight();
};

#endif // DOORS_CONTROLLER_H
