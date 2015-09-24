#ifndef BRAKE_H
#define BRAKE_H

#include "traction.h"

class Traction;

class Brake
{

private:
    Traction *m_traction;

    bool m_emergencyBrake;
    bool m_parkingBrake;
    double m_brake;
    double m_lastBrake;
    bool m_bypass;
    bool m_retentioBrake;
    bool m_anulacionFrenoRetencion;
    bool m_averia;

public:
    Brake();
    ~Brake();
    void linkTraction(Traction *traction);
    bool braking();
    void reset();

    //GETTERS & SETTERS
    bool getEmergencyBrake() const;
    void setEmergencyBrake(bool value);
    double getBrake() const;
    void setBrake(double value);
    bool parkingBrake() const;
    void setParkingBrake(bool parkingBrake);
    double lastBrake() const;
    void setLastBrake(double lastBrake);
    bool bypass() const;
    void setBypass(bool status);
    bool retentioBrake() const;
    void setRetentioBrake(bool retentioBrake);
    bool averia() const;
    void setAveria(bool averia);
    bool anulacionFrenoRetencion() const;
    void setAnulacionFrenoRetencion(bool anulacionFrenoRetencion);
};

#endif // BRAKE_H
