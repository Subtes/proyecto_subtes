#ifndef BOARDHARDWARE_H
#define BOARDHARDWARE_H
#include "baseboard.h"
#include "src/controllers/tractioncontroller.h"
#include "src/controllers/hongoemergenciacontroller.h"
#include "src/controllers/llavaseguridadcontroller.h"

namespace Ui {
class BoardHardware;
}

class BoardHardware : public BaseBoard
{
    Q_OBJECT

public:
    explicit BoardHardware(QWidget *parent = 0, SubteState *subte = 0, EventHandler *eventHandler = 0);
    ~BoardHardware();

private:
    Ui::BoardHardware *ui;

    TractionController * m_traction;
    HongoEmergenciaController * m_hongo;
    LlavaSeguridadController * m_llaveSeguridad;

};

#endif // BOARDHARDWARE_H
