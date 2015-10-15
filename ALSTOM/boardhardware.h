#ifndef BOARDHARDWARE_H
#define BOARDHARDWARE_H
#include "baseboard.h"
#include "src/controllers/tractioncontroller.h"

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
};

#endif // BOARDHARDWARE_H
