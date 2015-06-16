#define _F1 0x70
#define _F2 0x71

#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>
#include <ENetClient.h>
#include <Windows.h>
#include "src/controllers/enethelper.h"
#include "src/controllers/keypresseater.h"
#include "src/models/subtestatus.h"

class SubteStatus;
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

    void setModel(SubteStatus *subte);

private:
    ENetClient * m_eNetClient;
    ENetHelper * m_eNetHelper;
    SubteStatus * m_subte;

    //TODO:: SACAR ESTOOOOOOOO
    bool splashPassed;

signals:
    controlReady();
    controlDisable();
    controlEnable();
    controlReset();

public slots:
    void processKey(DWORD k);

};

#endif // EVENTHANDLER_H
