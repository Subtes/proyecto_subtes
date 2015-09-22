
#ifndef TRACTION_H
#define TRACTION_H

#include "src/models/brake.h"
#include "src/models/cscp.h"
#include "src/models/atp_model.h"

class Brake;

class Traction
{

public:
    enum class RANA { AD=1, CERO=0, AT=-1 };

private:
    RANA m_rana;
    Brake *m_brake;
    CSCP *m_cscp;
    ATP_model *m_atp;

    bool m_hombreMuerto;

    int m_traction;
    int m_position;

    int m_lastTraction;
    int m_lastPosition;

    bool m_averia;
    bool debuguear = true;


public:
    Traction();
    ~Traction();

    void linkBrake(Brake *b);
    void linkCSCP(CSCP *c);
    void linkATP(ATP_model *a);

    void reset();
    void setDirection(RANA r);

    int getTraction();
    double updateTraction(int traction);
    double updateTraction();
    void setLastTraction(int lastTraction);
    int lastTraction() const;

    void setPosition(int tractionLeverPosition);
    int position() const;
    void setLastPosition(int lastPosition);
    int lastPosition() const;

    bool hombreMuerto() const;
    void setHombreMuerto(bool hombreMuerto);

    bool averia() const;
    void setAveria(bool averia);
};

#endif // TRACTION_H
