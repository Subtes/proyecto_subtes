#ifndef BASE_EVENTHANDLER_H
#define BASE_EVENTHANDLER_H

#include <QObject>
#include "ENetClient.h"
#include "base_enethelper.h"

class ENetClient;
class Base_ENetHelper;

/**
 * @brief The EventHandler class
 * Clase comun virtual-abstracta para abstraer el comportamiento
 * comun del manejador de eventos de red, como transmitir un mensaje
 * o mutear la difusion.
 */
class Base_EventHandler : public QObject
{
    Q_OBJECT

protected:
    Base_ENetHelper * m_eNetHelper;
    int m_boardsReady = 0;
    std::string m_cargandoEstado = " ";


public:
    Base_EventHandler();
    ~Base_EventHandler();

    virtual void processValueChanged(std::string host, std::string key, std::string value)=0;
    void notifyValueChanged(std::string key, std::string value);
    void notifyValueChanged(std::string key, std::string subKey, std::string value);
    void enableDiffusion();
    void initConnection(QString dirPath);

signals:
    controlReady();
    controlDisable();
    controlEnable();
    controlReset();
    closeApp();
    cargarEstado(int);

};

#endif // BASE_EVENTHANDLER_H
