#ifndef TRACTIONLEVER_CONTROLLER_H
#define TRACTIONLEVER_CONTROLLER_H
#include <tractionlever.h>
#include "src/models/subtestatus.h"
class TractionLever_Controller : public QObject
{
    Q_OBJECT

public:
    TractionLever_Controller(SubteStatus * subte, TractionLever * slider);
    ~TractionLever_Controller();
    void setValue(int v);

private:
    TractionLever * m_tractionLever;
    SubteStatus * m_subte;
};

#endif // TRACTIONLEVER_CONTROLLER_H
