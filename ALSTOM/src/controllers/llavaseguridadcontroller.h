#ifndef LLAVASEGURIDADCONTROLLER_H
#define LLAVASEGURIDADCONTROLLER_H

#include <QObject>
#include "singlebutton.h"
#include "src/models/subtestate.h"

class LlavaSeguridadController : public QObject
{
    Q_OBJECT
public:
    LlavaSeguridadController(SubteState *subte, SingleButton *llave);
    ~LlavaSeguridadController();
    void turnOnLlave();
    void turnOffLlave();

private slots:
    void turnedOn();
    void turnedOff();

private:
    SingleButton *m_llave;
    SubteState *m_subte;
};

#endif // LLAVASEGURIDADCONTROLLER_H
