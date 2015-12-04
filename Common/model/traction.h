#ifndef TRACTION_H
#define TRACTION_H

#include "brakes.h"
#include "automatictrainprotection.h"
#include "doors.h"
#include "controller/base_eventhandler.h"

class Brakes;

class Traction
{

public:

    enum TRACTION_MODE { ADELANTE=1, NEUTRO=0, REVERSA=-1, LIMITADO=2 };

    Traction();
    ~Traction();
    void linkBrake(Brakes *b);
    void linkCSCP(Doors *c);
    void linkATP(AutomaticTrainProtection *a);
    void setHandler(Base_EventHandler * eventHandler);

    void reset();
    void setDirection(TRACTION_MODE tm);

    int getTraction();
    void updateTraction(int traction);

    bool hombreMuerto() const;
    void setHombreMuerto(bool hombreMuerto);

    bool averia() const;
    void setAveria(bool averia);

    void notifyTraction();
    void notifyHM();

private:
    const std::string NOMBRE_TRACCION = "c_traccion";
    const std::string NOMBRE_FRENO_HOMBRE_MUERTO = "c_freno";
    const std::string VALOR_FRENO_HOMBRE_MUERTO = "50";
    const std::string NOMBRE_HOMBRE_MUERTO = "c_dispositivo_hombre_muerto";
    const std::string VALOR_HOMBRE_MUERTO_CON = "con";
    const std::string VALOR_HOMBRE_MUERTO_DES = "des";
    const int SAFE_NEUTRAL_ZONE = 15;
    const int INTERVAL_EMISSION = 5;

    int m_traction;
    int m_lastTraction;
    bool m_hombreMuerto;
    bool m_averia;
    bool debuguear = true;

    TRACTION_MODE m_rana;
    Brakes *m_brake;
    Doors *m_doors;
    AutomaticTrainProtection *m_atp;
    Base_EventHandler * m_eventHandler;
};

#endif // TRACTION_H
