#ifndef TRACTION_H
#define TRACTION_H

#include "src/models/brake.h"
#include "src/models/cscp.h"
#include "src/models/atp_model.h"

class Traction
{

public:
    enum class RANA { AD=1, CERO=0, AT=-1 };

private:
    RANA m_rana;
    Brake *m_brake;
    CSCP *m_cscp;
    ATP_model *m_atp;

    bool m_hombreVivo;

    int m_traction;
    int m_position;

    int m_lastTraction;
    int m_lastPosition;


public:
    Traction(Brake *b, CSCP *c, ATP_model *a);
    ~Traction();

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

    bool hombreVivo() const;
    void setHombreVivo(bool hombreVivo);
};

#endif // TRACTION_H
