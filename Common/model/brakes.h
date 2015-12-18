#ifndef BRAKES_H
#define BRAKES_H

#include "traction.h"
#include "controller/base_eventhandler.h"

class Traction;

class Brakes
{
private:
    const std::string NOMBRE_FRENO = "c_freno";
    const std::string NOMBRE_FRENO_EMERGENCIA = "c_freno_emergencia";
    const std::string VALOR_CON_FRENO_EMERGENCIA = "con";
    const std::string VALOR_DES_FRENO_EMERGENCIA = "des";

    bool m_emergencyBrake_tractionLever;
    bool m_emergencyBrake_atp;
    bool m_emergencyBrake_setas;
    bool m_emergencyBrake_HM;
    double m_brake;
    double m_lastBrake;
    bool m_bypass;
    bool m_retentioBrake;
    bool m_anulacionFrenoRetencion;
    bool m_averia;

    Traction *m_traction;
    Base_EventHandler * m_eventHandler;

public:
    Brakes();
    ~Brakes();

    void linkTraction(Traction *traction);
    void setHandler(Base_EventHandler * eventHandler);
    bool braking();
    void reset();

    void notifyEmergencyBrake();
    void notifyBrake();

    //GETTERS & SETTERS
    bool getEmergencyBrake() const;
    bool getHiloLazo();
    void setEmergencyBrake_atp(bool value);
    void setEmergencyBrake_seta(bool value);
    void setEmergencyBrake_HM(bool value);
    double getBrake() const;
    void setBrake(double value);
    bool bypass() const;
    void setBypass(bool status);
    bool retentioBrake() const;
    void setRetentioBrake(bool retentioBrake);
    bool averia() const;
    void setAveria(bool averia);
    bool anulacionFrenoRetencion() const;
    void setAnulacionFrenoRetencion(bool anulacionFrenoRetencion);
};

#endif // BRAKES_H
