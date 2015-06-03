#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <QObject>
#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"
#include "boardtop.h"
#include "splashtest.h"

#include "src/models/subtestatus.h"

#include <ENetClient.h>
#include <QDebug>

class Dispatcher : public QObject
{
    Q_OBJECT

private:
    SubteStatus * m_subte;
    ENetClient *m_eNetClient;
    std::string m_serverIp;
    int m_serverPort;
    std::string m_controlsHostName;
    std::string m_instructionsHostName;
    BoardHardware *m_h;
    BoardCenter * m_c;
    BoardLeft *m_l;
    BoardRight *m_r;
    BoardTop *m_t;
    splashTest *m_s1;
    splashTest *m_s2;
    splashTest *m_s3;

public:
    Dispatcher();
    ~Dispatcher();
    void initApp();
    void startApp();
    void listener(std::string host, std::string clave, std::string valor);

signals:
    closeSplash();
    showScreens();

};

#endif // DISPATCHER_H
