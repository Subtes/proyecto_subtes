#ifndef DOORS_CONTROLLER_H
#define DOORS_CONTROLLER_H

#include "panel_buttons3.h"
#include "QDial"
#include <QStateMachine>
#include <QState>


class Doors_Controller : public QObject
{
     Q_OBJECT

public:
    Doors_Controller(Panel_Buttons3 *leftPanel=0,Panel_Buttons3 *rightPanel=0,QDial * dial=0);
    ~Doors_Controller();

private:
    Panel_Buttons3 *m_leftPanel;
    Panel_Buttons3 *m_rightPanel;
    QDial *m_dial;

    QStateMachine *leftDoorsMachine;
    QStateMachine *rightDoorsMachine;

    bool stateLeftDoors;
    bool stateRightDoors;

    void inicPanels(Panel_Buttons3 * leftPanel, Panel_Buttons3 * rightPanel);
    void inicMachines();

private slots:
    void updatePanels(int value);
    void disableRightPanel();
    void disableLeftPanel();
    void reactiveRightPanel();
    void reactiveLeftPanel();
    void openLeftDoors();
    void closeLeftDoors();
    void openRightDoors();
    void closeRightDoors();

};

#endif // DOORS_CONTROLLER_H
