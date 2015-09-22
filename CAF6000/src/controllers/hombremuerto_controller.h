#ifndef HOMBREMUERTO_CONTROLLER_H
#define HOMBREMUERTO_CONTROLLER_H

#include <QObject>
#include <tractionlever.h>
#include "src/models/subtestatus.h"

class HombreMuerto_Controller : public QObject
{
    Q_OBJECT

public:
    HombreMuerto_Controller(SubteStatus *subte,TractionLever *slider=0);
    ~HombreMuerto_Controller();

private:
    SubteStatus *m_subte;
    TractionLever *m_slider;
};

#endif // HOMBREMUERTO_CONTROLLER_H
