#ifndef BASEBOARD_H
#define BASEBOARD_H

#include <QMainWindow>
#include "src/models/subtestate.h"
#include "src/controllers/eventhandler.h"

class BaseBoard : public QMainWindow
{
    Q_OBJECT
public:
    BaseBoard(QWidget *parent, SubteState *subte, EventHandler *eventHandler);
    ~BaseBoard();

protected:
    SubteState     *m_subte;
    EventHandler   *m_eventHandler;
};

#endif // BASEBOARD_H
