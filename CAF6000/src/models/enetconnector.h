#ifndef ENETCONNECTOR_H
#define ENETCONNECTOR_H

#include "string.h"

class ENetConnector
{
    static const string serverIp = "127.0.0.1";
    static const int serverPort = 5000;

    static const string controlsHostName = "P1_control";
    static const string visualHostName = "P1_visualizador";
    static const string instructionsHostName = "P1_instruccion";


public:
    ENetConnector();
    ~ENetConnector();

    void init();
    void suscribe();
    void
};

#endif // ENETCONNECTOR_H
