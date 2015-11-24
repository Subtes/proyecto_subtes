#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H

#include <QObject>

/**
 * @brief The EventHandler class
 * Clase comun virtual-abstracta para abstraer el comportamiento
 * comun del manejador de eventos de red, como transmitir un mensaje
 * o mutear la difusion.
 */
class EventHandler : public QObject
{
    Q_OBJECT

private:

public:
    EventHandler();
    ~EventHandler();
};

#endif // EVENTHANDLER_H
