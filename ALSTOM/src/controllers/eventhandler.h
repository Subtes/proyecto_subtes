#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <QString>
#include "src/models/subtestate.h"
#include "controller/base_eventhandler.h"

class SubteState;

class EventHandler : public Base_EventHandler
{
    Q_OBJECT

public:
    EventHandler();
    ~EventHandler();

    void processDifussionChanged(std::string host, bool difusion);
    void processValueChanged(std::string host, std::string key, std::string value);
    void setModel(SubteState *subte);

private:
    SubteState * m_subte;
};

#endif // EVENTHANDLER_H
