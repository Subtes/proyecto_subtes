#ifndef SUBTESTATE_H
#define SUBTESTATE_H

#include <QObject>
#include "src/controllers/eventhandler.h"
#include "model/subtestatebase.h"

class EventHandler;

class SubteState : public SubteStateBase
{
    Q_OBJECT

public:
    SubteState();
    ~SubteState();
    void reset();

public slots:
    void setMode(int value);

};

#endif // SUBTESTATE_H
