#ifndef BOARDCENTER_H
#define BOARDCENTER_H

#include <QMainWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/wiper_controller.h"
#include "src/controllers/emergencyoverride_controller.h"
#include "src/controllers/tractionbypass_controller.h"

namespace Ui {
class BoardCenter;
}

class BoardCenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardCenter(QWidget *parent = 0, SubteStatus *subte = 0);
    ~BoardCenter();

private:
    Ui::BoardCenter *ui;
    SubteStatus *m_subte;
};

#endif // BOARDCENTER_H
