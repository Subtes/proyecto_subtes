#include "dispatcher.h"

Dispatcher::Dispatcher()
{
}

Dispatcher::~Dispatcher()
{
}

void Dispatcher::initApp()
{
    // MODEL
    m_subte = new SubteStatus();

    // ENET
    m_serverIp = "127.0.0.1";
    m_serverPort = 5000;
    m_controlsHostName = "P1_control";
    m_instructionsHostName = "P1_instruccion";

    m_eNetClient = new ENetClient();

    using namespace std::placeholders;
    m_eNetClient->OnCambioValClave = std::bind(&Dispatcher::listener, this, _1, _2, _3);

    m_eNetClient->Conectar(m_serverIp, m_serverPort, m_controlsHostName);
    m_eNetClient->Suscribirse(m_instructionsHostName,"i_estado_simulador");

    //VIEWS
    m_h = new BoardHardware(0,m_subte);
    m_c = new BoardCenter(0,m_subte,);
    m_l = new BoardLeft(0,m_subte);
    m_r = new BoardRight(0,m_subte);
    m_t = new BoardTop(0,m_subte);
    m_s1 = new splashTest(this);
    m_s1->show();
}

void Dispatcher::startApp()
{
    m_c->show();
    emit closeSplash(); //m_s1->close();
    emit showScreens(); //m_c->show();
    qDebug() << "chao";
}

void Dispatcher::listener(std::string host, std::string clave, std::string valor){
    if (    (host   .compare(m_instructionsHostName)==0) &&
            (clave  .compare("i_estado_simulador")==0) &&
            (valor  .compare("0")==0))
        startApp();
    qDebug() << "hoa";
}

