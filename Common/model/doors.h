#ifndef DOORS_H
#define DOORS_H

#include "controller/base_eventhandler.h"

class Doors
{

private:
    const std::string NOMBRE_PUERTAS = "c_pulsador_puertas";
    const std::string LADO_IZ = "izquierda";
    const std::string LADO_DE = "derecha";
    const std::string ACCION_ABR = "abrir";
    const std::string ACCION_CRR = "cerrar";

    Base_EventHandler * m_eventHandler;

    bool m_bypass;
    bool m_leftDoors;
    bool m_rightDoors;
    bool m_averia;

    bool m_rightDoorsPanel;
    bool m_leftDoorsPanel;

    bool m_parkingBrake;

public:
    static const bool OPEN = true;
    static const bool CLOSE = false;

    Doors();
    ~Doors();

    void setHandler(Base_EventHandler * eventHandler);
    void reset();
    bool evalCircuit();
    bool getBypass() const;
    void setBypass(bool value);
    bool leftDoors() const;
    bool rightDoors() const;
    void openLeftDoors();
    void openRightDoors();
    void closeLeftDoors();
    void closeRightDoors();
    bool averia() const;
    void setAveria(bool averia);
    bool parkingBrake() const;
    void setParkingBrake(bool parkingBrake);

    void notifyActionLeftDoors(bool state);
    void notifyActionRightDoors(bool state);
};

#endif // DOORS_H
