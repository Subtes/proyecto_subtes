#ifndef BOARDTOP_H
#define BOARDTOP_H

#include <QMainWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"
#include "src/controllers/topboardconnectors_controller.h"

namespace Ui {
class BoardTop;
}

class BoardTop : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardTop(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardTop();

private:
    Ui::BoardTop *ui;
    SubteStatus *m_subte;
    EventHandler *m_eventHandler;

    TopBoardConnectors_Controller *m_connectors;

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();
    void cargarEstado(int);
};

#endif // BOARDTOP_H
