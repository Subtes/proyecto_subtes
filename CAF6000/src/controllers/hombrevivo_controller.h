#ifndef HOMBREVIVO_CONTROLLER_H
#define HOMBREVIVO_CONTROLLER_H

#include <QObject>
#include <tractionlever.h>
#include "src/models/subtestatus.h"

class HombreVivo_Controller : public QObject
{
    Q_OBJECT

public:
    HombreVivo_Controller(SubteStatus *subte,TractionLever *slider=0);
    ~HombreVivo_Controller();

private:
    SubteStatus *m_subte;
    TractionLever *m_slider;
};

#endif // HOMBREVIVO_CONTROLLER_H
