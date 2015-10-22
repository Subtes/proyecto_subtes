#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include "src/controllers/enethelper.h"
#include "src/models/subtestate.h"
#include <QObject>
#include <ENetClient.h>

class SubteState;
class ENetHelper;

class EventHandler : public QObject
{
    Q_OBJECT

public:
    EventHandler();
    ~EventHandler();

    void processValueChanged(std::string host, std::string key, std::string value);
    void notifyValueChanged(std::string key, std::string value);
    void initConnection();
    void setModel(SubteState *subte);

private:
    ENetClient * m_eNetClient;
    ENetHelper * m_eNetHelper;
    SubteState * m_subte;

signals:
    controlReady();
    controlDisable();
    controlEnable();
    controlReset();
    closeApp();
};

#endif // EVENTHANDLER_H
