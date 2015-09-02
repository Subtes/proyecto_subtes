#ifndef BOARDLEFT_H
#define BOARDLEFT_H

#include "baseboard.h"
#include "src/controllers/atp_controller.h"

namespace Ui {
class BoardLeft;
}

class BoardLeft : public BaseBoard
{
    Q_OBJECT

public:
    explicit BoardLeft(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardLeft();

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();
    void loadState(int state);

private:
    Ui::BoardLeft *ui;

    Atp_Controller *m_atp;
};

#endif // BOARDLEFT_H
