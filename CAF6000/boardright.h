#ifndef BOARDRIGHT_H
#define BOARDRIGHT_H

#include <QMainWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"
#include "src/controllers/circuitbreakercon_controller.h"
#include "src/controllers/circuitbreakerdes_controller.h"

namespace Ui {
class BoardRight;
}

class BoardRight : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardRight(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardRight();

private:
    Ui::BoardRight *ui;
    SubteStatus *m_subte;
    EventHandler *m_eventHandler;

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();
};

#endif // BOARDRIGHT_H
