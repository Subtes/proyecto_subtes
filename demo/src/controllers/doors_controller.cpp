#include "doors_controller.h"

/**
 * @brief Doors_Controller::Doors_Controller:
 *          inicializa las variables, y paneles, adicionalmente podria recibir el estado actual de
 *          las puertas proveniente del modelo.
 * @param leftPanel:
 *          botonera (widget) que controla las puertas de la inquierda
 * @param rightPanel:
 *          botonera (widget) que controla las puertas de la derecha
 * @param dial
 *          selector de activacion de sistema de puertas
 */
Doors_Controller::Doors_Controller(Panel_Buttons3 * leftPanel,Panel_Buttons3 * rightPanel,QDial * dial)
{
    m_dial = dial;

    inicPanels(leftPanel,rightPanel);
    connect(dial,SIGNAL(valueChanged(int)),this,SLOT(switchPanels(int)));

    connect(m_leftPanel,SIGNAL(secondClicked()),this,SLOT(openLeftDoors()));
    connect(m_leftPanel,SIGNAL(thirdClicked()),this,SLOT(closeLeftDoors()));
    connect(m_rightPanel,SIGNAL(secondClicked()),this,SLOT(openRightDoors()));
    connect(m_rightPanel,SIGNAL(thirdClicked()),this,SLOT(closeRightDoors()));
}

/**
 * @brief Doors_Controller::~Doors_Controller
 */
Doors_Controller::~Doors_Controller()
{

}

/**
 * @brief Doors_Controller::inicPanels:
 *          inicializa los paneles, (por defecto apagados) setea los botones como luces,
 *          adicionalmente podria setear imagenes y demas cuestiones relacionadas
 *          a la vista (widget)
 * @param leftPanel:
 *          panel/botonera (widget) iquierda
 * @param rightPanel
 *          panel/botonera (widget) derecha
 */
void Doors_Controller::inicPanels(Panel_Buttons3 * leftPanel, Panel_Buttons3 * rightPanel){
    stateLeftDoors = false;
    m_leftPanel = leftPanel;
    m_leftPanel->setFirstClickeable(false);
    turnOffPanel(m_leftPanel);

    stateRightDoors = false;
    m_rightPanel = rightPanel;
    m_rightPanel->setFirstClickeable(false);
    turnOffPanel(m_rightPanel);
}

/**
 * @brief Doors_Controller::switchPanels:
 *          Segun la posicion del dial (value), activa o desactiva los paneles de control
 *          de puertas.
 * @param value:
 *          int mapeado a las variables estaticas 0=STANDBY, 1=LEFT y 2=RIGHT.
 */
void Doors_Controller::switchPanels(int value){
    switch (value) {

        case STANDBY:
            turnOffPanel(m_leftPanel);
            turnOffPanel(m_rightPanel);
            break;

        case LEFT:
            turnOnPanel(m_leftPanel);
            updatePanel(stateLeftDoors,m_leftPanel);
            turnOffPanel(m_rightPanel);
            break;

        case RIGHT:
            turnOnPanel(m_rightPanel);
            updatePanel(stateRightDoors,m_rightPanel);
            turnOffPanel(m_leftPanel);
            break;
    }
}

/**
 * @brief Doors_Controller::turnOnPanel
 *          enciende un panel, en este caso solo prende la luz azul.
 * @param panel
 */
void Doors_Controller::turnOnPanel(Panel_Buttons3 * panel){
    panel->firstOn();
}

/**
 * @brief Doors_Controller::turnOffPanel:
 *          apaga el panel, desactiva sus botones y apaga las luces.
 * @param panel
 */
void Doors_Controller::turnOffPanel(Panel_Buttons3 * panel){
    panel->setSecondClickeable(false);
    panel->setThirdClickeable(false);
    panel->firstOff();
    panel->secondOff();
    panel->thirdOff();
}

/**
 * @brief Doors_Controller::updatePanel:
 *          aparte de encender o apagar las luces segun el estado actual de las puertas,
 *          habilita o deshabilita los click en los botones, es decir, si las puertas estan
 *          cerradas, no se puede clickear el boton rojo.
 * @param currentState:
 *          estado actual de las puertas.
 * @param panel:
 */
void Doors_Controller::updatePanel(bool currentState,Panel_Buttons3 * panel){
    if(currentState){
        panel->secondOn();
        panel->setSecondClickeable(false);
        panel->thirdOff();
        panel->setThirdClickeable(true);
    }else{
        panel->secondOff();
        panel->setSecondClickeable(true);
        panel->thirdOn();
        panel->setThirdClickeable(false);
    }
}

/**
 * @brief Doors_Controller::openLeftDoors:
 *          SLOT: actualiza el estado de las puertas y configura la botonera en el
 *          estado puertas abiertas.
 */
void Doors_Controller::openLeftDoors(){
    stateLeftDoors = true;
    updatePanel(stateLeftDoors,m_leftPanel);
    //emit signal if necessary
}

/**
 * @brief Doors_Controller::closeLeftDoors:
 *          SLOT: actualiza el estado de las puertas y configura la botonera en el
 *          estado puertas cerradas.
 */
void Doors_Controller::closeLeftDoors(){
    stateLeftDoors = false;
    updatePanel(stateLeftDoors,m_leftPanel);
    //emit signal if necessary
}

/**
 * @brief Doors_Controller::openRightDoors:
            SLOT: actualiza el estado de las puertas y configura la botonera en el
 *          estado puertas abiertas.
 */
void Doors_Controller::openRightDoors(){
    stateRightDoors = true;
    updatePanel(stateRightDoors,m_rightPanel);
    //emit signal if necessary
}

/**
 * @brief Doors_Controller::closeRightDoors:
 *          SLOT: actualiza el estado de las puertas y configura la botonera en el
 *          estado puertas cerradas.
 */
void Doors_Controller::closeRightDoors(){
    stateRightDoors = false;
    updatePanel(stateRightDoors,m_rightPanel);
    //emit signal if necessary
}
