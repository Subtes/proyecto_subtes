#ifndef HONGOEMERGENCIACONTROLLER_H
#define HONGOEMERGENCIACONTROLLER_H

#include <QObject>
#include "singlebutton.h"
#include "src/models/subtestate.h"

class HongoEmergenciaController : public QObject
{
    Q_OBJECT

public:
    HongoEmergenciaController(SubteState *subte, SingleButton *hongo);
    ~HongoEmergenciaController();
    void pushHongo();
    void releaseHongo();

private slots:
    void hongoPressed();
    void hongoReleased();

private:
    SingleButton *m_hongo;
    SubteState *m_subte;
};

#endif // HONGOEMERGENCIACONTROLLER_H
