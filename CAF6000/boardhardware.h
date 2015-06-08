#ifndef BOARDHARDWARE_H
#define BOARDHARDWARE_H

#include <QWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/horn_controller.h"
#include "src/controllers/tractionlever_controller.h"
#include "src/controllers/rana_controller.h"
#include "src/controllers/hombrevivo_controller.h"
#include "src/controllers/seta_controller.h"
#include "src/controllers/speedgaugeleds_controller.h"

namespace Ui {
class BoardHardware;
}

class BoardHardware : public QWidget
{
    Q_OBJECT

public:
    explicit BoardHardware(QWidget *parent = 0, SubteStatus *subte = 0);
    ~BoardHardware();

private:
    Ui::BoardHardware *ui;
    SubteStatus *m_subte;
};

#endif // BOARDHARDWARE_H
