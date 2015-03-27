#ifndef DOORS_CONTROLLER_H
#define DOORS_CONTROLLER_H

#include "panel_buttons3.h"
#include "QDial"
#include <QStateMachine>
#include <QState>

/**
 * El controlador maneja las botoneras de 3 botones (widget) para simular el comportamiento
 * de los comandos de apertura y cerrado de puertas. Coordina ademas, segun la posicion
 * del selector (widget dial), que botonera de puertas se activa. Mantiene el estado de las
 * puertas (inicialmente "cerradas").
 */

class Doors_Controller : public QObject
{
    Q_OBJECT

    /**
    * @STANDBY, @LEFT y @RIGHT:
    *   son los valores que retorna el dial, que indicarian que sistema de puertas esta activo.
    */
    static const int STANDBY = 0;
    static const int LEFT = 1;
    static const int RIGHT = 2;


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
    void turnOnPanel(Panel_Buttons3 * panel);
    void turnOffPanel(Panel_Buttons3 * panel);
    void updatePanel(bool currentState,Panel_Buttons3 * panel);

private slots:
    void switchPanels(int value);

public slots:
    void openLeftDoors();
    void closeLeftDoors();
    void openRightDoors();
    void closeRightDoors();
};

#endif // DOORS_CONTROLLER_H
