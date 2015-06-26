#ifndef BOARDLEFT_H
#define BOARDLEFT_H

#include <QMainWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"
#include "src/controllers/atp_controller.h"
namespace Ui {
class BoardLeft;
}

class BoardLeft : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardLeft(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardLeft();
    void probarATP(double speed);

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();

private:
    Ui::BoardLeft *ui;
    SubteStatus *m_subte;
    EventHandler *m_eventHandler;
    //Es para probarlo Quitar!
    Atp_Controller *m_atp;



};

#endif // BOARDLEFT_H
