#ifndef DISPATCHER_H
#define DISPATCHER_H
#include <QObject>
#include "src/models/subtestatus.h"
#include "simulacionsubtefisica.h"

class Dispatcher : public QObject
{
    Q_OBJECT
private:
    SimulacionSubteFisica *m_subteFisica;
    SubteStatus *m_subte;

public:
    Dispatcher(SimulacionSubteFisica *subteFisica,SubteStatus *subte);
    ~Dispatcher();
};

#endif // DISPATCHER_H
