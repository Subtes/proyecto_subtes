#ifndef BOARDMAC_H
#define BOARDMAC_H

#include <QMainWindow>
#include "baseboard.h"
#include "src/controllers/alstomtcms_controller.h"

namespace Ui {
class BoardMac;
}

class BoardMac : public BaseBoard
{
    Q_OBJECT

public:
    explicit BoardMac(QWidget *parent = 0, SubteState *subte = 0, EventHandler *eventHandler = 0);
    ~BoardMac();

private:
    Ui::BoardMac *ui;
    AlstomTcms_Controller * m_alstomtcms;
};

#endif // BOARDMAC_H
