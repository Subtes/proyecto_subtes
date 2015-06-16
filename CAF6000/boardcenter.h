#ifndef BOARDCENTER_H
#define BOARDCENTER_H

#include <QMainWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"
#include "src/controllers/wiper_controller.h"
#include "src/controllers/emergencyoverride_controller.h"
#include "src/controllers/tractionbypass_controller.h"
#include "src/controllers/speedgaugeleds_controller.h"

namespace Ui {
class BoardCenter;
}

class BoardCenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardCenter(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardCenter();

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();

private:
    Ui::BoardCenter *ui;
    SubteStatus *m_subte;
    EventHandler *m_eventHandler;

};

#endif // BOARDCENTER_H
