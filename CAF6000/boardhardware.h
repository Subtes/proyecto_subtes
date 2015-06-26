#ifndef BOARDHARDWARE_H
#define BOARDHARDWARE_H

#include <QMainWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"
#include "src/controllers/horn_controller.h"
#include "src/controllers/tractionlever_controller.h"
#include "src/controllers/rana_controller.h"
#include "src/controllers/hombrevivo_controller.h"
#include "src/controllers/seta_controller.h"
#include "src/controllers/speedgaugeleds_controller.h"

namespace Ui {
class BoardHardware;
}

class BoardHardware : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardHardware(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardHardware();

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();

private:
    Ui::BoardHardware *ui;
    SubteStatus *m_subte;
    EventHandler *m_eventHandler;

    Horn_Controller *m_horn;
    TractionLever_Controller *m_tractionLever;
    Rana_Controller *m_rana;
    HombreVivo_Controller *m_hombreVivo;
    Seta_Controller *m_setaButton;
    SpeedGaugeLeds_Controller *m_speedGauge;
};

#endif // BOARDHARDWARE_H
