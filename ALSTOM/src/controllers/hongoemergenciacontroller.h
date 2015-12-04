#ifndef HONGOEMERGENCIACONTROLLER_H
#define HONGOEMERGENCIACONTROLLER_H

#include <QObject>
#include "singlebutton.h"
#include "src/models/subtestate.h"
#include "src/controllers/base_controller.h"

class HongoEmergenciaController : public Base_Controller
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
};

#endif // HONGOEMERGENCIACONTROLLER_H
