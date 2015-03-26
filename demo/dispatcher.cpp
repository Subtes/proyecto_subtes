#include "dispatcher.h"

Dispatcher::Dispatcher(SimulacionSubteFisica *subteFisica,SubteStatus *subte)
{
    m_subteFisica = subteFisica;
    m_subte = subte;

    connect(subte,SIGNAL(tractionChanged(int)),subteFisica,SLOT(updateTraction(int)));
    connect(subteFisica,SIGNAL(speedChanged(double)),subte,SLOT(changeSpeed(double)));
}

Dispatcher::~Dispatcher()
{

}
