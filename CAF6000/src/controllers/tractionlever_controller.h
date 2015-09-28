#ifndef TRACTIONLEVER_CONTROLLER_H
#define TRACTIONLEVER_CONTROLLER_H
#include <tractionlever.h>
#include <tractionhardware.h>
#include "src/models/subtestatus.h"
class TractionLever_Controller : public QObject
{
    Q_OBJECT

public:
    TractionLever_Controller(SubteStatus * subte, TractionLever * slider, TractionHardware *th);
    ~TractionLever_Controller();
    void setValue(int v);

public slots:
    void processValue(int);
    void processBrake();

private:
    TractionLever * m_tractionLever;
    TractionHardware *m_tractionHardware;
    SubteStatus * m_subte;

    QTimer *m_checkJ;
};

#endif // TRACTIONLEVER_CONTROLLER_H
