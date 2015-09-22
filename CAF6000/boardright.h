#ifndef BOARDRIGHT_H
#define BOARDRIGHT_H

#include "baseboard.h"
#include "src/controllers/circuitbreakercon_controller.h"
#include "src/controllers/circuitbreakerdes_controller.h"
#include "src/controllers/manometer_controller.h"
#include "src/controllers/sicasmac_controller.h"

namespace Ui {
class BoardRight;
}

class BoardRight : public BaseBoard
{
    Q_OBJECT

public:
    explicit BoardRight(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardRight();

private:
    Ui::BoardRight *ui;
    SubteStatus *m_subte;
    EventHandler *m_eventHandler;
    Manometer_Controller * m_manometer;
    SicasMac_Controller * m_sicasmac;

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();
    void loadState(int state);

private:

    CircuitBreakerCON_Controller * m_CON_Disyuntor;
    CircuitBreakerDES_Controller * m_DES_Disyuntor;

    int lastState=0;
};

#endif // BOARDRIGHT_H
