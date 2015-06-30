#define _F1 0x70
#define _F2 0x71
#define _F3 0x72
#define _F4 0x73
#define _K 0x4B
#define _L 0x4C
#define _A 0x41
#define _R 0x52
//#define _F 0x46
#define _T 0x54
#define _B 0x42

#define _CERO 0x30
#define _UNO 0x31
#define _DOS 0x32
#define _TRES 0x33
#define _CUATRO 0x34
#define _CINCO 0x35
#define _SEIS 0x36
#define _SIETE 0x37
#define _OCHO 0x38
#define _NUEVE 0x39

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

    bool F1_down;
    bool F2_down;
    bool F3_down;
    bool F4_down;
    bool K_down;
    bool L_down;
    bool A_down;
    bool R_down;
    bool F_down;
    bool T_down;
    bool B_down;
    bool C_down;
    bool CERO_down;
    bool UNO_down;
    bool DOS_down;
    bool TRES_down;
    bool CUATRO_down;
    bool CINCO_down;
    bool SEIS_down;
    bool SIETE_down;
    bool OCHO_down;
    bool NUEVE_down;

    //TODO:: SACAR ESTOOOOOOOO
    bool splashPassed;

signals:
    controlReady();
    controlDisable();
    controlEnable();
    controlReset();
    iCambioSenial1();

    bPressed();
    bReleased();

    aPressed();
    ceroPressed();
    rPressed();

    fPressed();
    tPressed();

    kPressed();
    lPressed();

    f3Pressed();
    f4Pressed();

    cPressed();

public slots:
    void processKeyPressed(DWORD k);
    void processKeyReleased(DWORD k);

};

#endif // EVENTHANDLER_H
