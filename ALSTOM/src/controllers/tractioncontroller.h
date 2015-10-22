#ifndef TRACTIONCONTROLLER_H
#define TRACTIONCONTROLLER_H

#include <QObject>
#include "src/models/subtestate.h"
#include "alstomtractionlever.h"
#include "alstomselectormodoconduccion.h"

class TractionController: public QObject
{
    Q_OBJECT

public:
    TractionController(SubteState *subte, AlstomTractionLever *tractionLever, AlstomSelectorModoConduccion *modoConduccion);
    ~TractionController();

private:
    bool seActivoFreno = false;
    SubteState *m_subte;
    AlstomTractionLever *m_tractionLever;
    AlstomSelectorModoConduccion *m_modoConduccion;

private slots:
    void processTractionPosition(int);
    void setClrMode();
    void setNeutroMode();
    void setCocheraMode();
    void setAdelanteMode();
};

#endif // TRACTIONCONTROLLER_H
