#ifndef TRACTION_H
#define TRACTION_H

//#include "src/models/cscp.h"
//#include "src/models/atp_model.h"
#include "model/brakes.h"
#include "controller/eventhandler.h"

class Brakes;
class EventHandler;

class Traction
{

public:
    enum class RANA { AD=1, CERO=0, AT=-1 };

private:
    const std::string NOMBRE_TRACCION = "c_traccion";
    const std::string NOMBRE_FRENO_HOMBRE_MUERTO = "c_freno";
    const std::string NOMBRE_HOMBRE_MUERTO = "c_dispositivo_hombre_muerto";
    const std::string VALOR_HOMBRE_MUERTO_CON = "con";
    const std::string VALOR_HOMBRE_MUERTO_DES = "des";

    RANA m_rana;
    Brakes *m_brake;
    EventHandler * m_eventHandler;

    bool m_hombreMuerto;

    int m_traction;
    int m_lastTraction;

    bool m_averia;
    bool debuguear = false;

public:
    Traction();
    ~Traction();

    void linkBrake(Brakes *b);
    void setHandler(EventHandler * eventHandler);

    void reset();
    void setDirection(RANA r);

    int getTraction();
    void updateTraction(int traction);

    bool hombreMuerto() const;
    void setHombreMuerto(bool hombreMuerto);

    bool averia() const;
    void setAveria(bool averia);

    void notifyTraction();
    void notifyHM();
};

#endif // TRACTION_H
