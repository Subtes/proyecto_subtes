#ifndef BASE_ENETHELPER_H
#define BASE_ENETHELPER_H

#include <QtXml>
#include <QFile>
#include "ENetClient.h"

#include "base_eventhandler.h"

class ENetClient;
class Base_EventHandler;

class Base_ENetHelper
{
    const std::string ini = "etc/control.ini";

public:
    Base_ENetHelper();
    ~Base_ENetHelper();
    void initENet(Base_EventHandler *eventHandler, QString dirPath);
    ENetClient *client();
    std::string serverIp() const;
    int serverPort() const;
    std::string controlsHostName() const;
    std::string visualHostName() const;
    std::string instructionsHostName() const;

protected:
    void readIni(QString dirPath);
    ENetClient *m_eNetClient;
    std::string m_serverIp;
    int m_serverPort;
    std::string m_controlsHostName;
    std::string m_visualHostName;
    std::string m_instructionsHostName;
};

#endif // BASE_ENETHELPER_H
