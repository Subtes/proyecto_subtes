#ifndef BOARDLEFT_H
#define BOARDLEFT_H

#include <QMainWindow>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"

namespace Ui {
class BoardLeft;
}

class BoardLeft : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardLeft(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~BoardLeft();

private:
    Ui::BoardLeft *ui;
    SubteStatus *m_subte;
    EventHandler *m_eventHandler;

};

#endif // BOARDLEFT_H
