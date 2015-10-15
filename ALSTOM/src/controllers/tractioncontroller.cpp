#include "tractioncontroller.h"

TractionController::TractionController(SubteState *subte, AlstomTractionLever *tractionLever, AlstomSelectorModoConduccion *modoConduccion)
{
    m_subte = subte;
    m_tractionLever = tractionLever;
    m_modoConduccion = modoConduccion;

    connect(m_tractionLever,SIGNAL(hmPressed()),m_subte,SLOT(hmPressed()));
    connect(m_tractionLever,SIGNAL(hmReleased()),m_subte,SLOT(hmReleased()));
    connect(m_tractionLever,SIGNAL(positionChanged(int)),this,SLOT(processTractionPosition(int)));

    connect(m_modoConduccion,SIGNAL(clr()),this,SLOT(setClrMode()));
    connect(m_modoConduccion,SIGNAL(neutro()),this,SLOT(setNeutroMode()));
    connect(m_modoConduccion,SIGNAL(cochera()),this,SLOT(setCocheraMode()));
    connect(m_modoConduccion,SIGNAL(adelante()),this,SLOT(setAdelanteMode()));
}

TractionController::~TractionController()
{

}

void TractionController::processTractionPosition(int value)
{
    if(value > 15){
        int tr = static_cast<int>((((double)value-15.0)/85.0)*100.0);
        m_subte->setTraction(tr);
    }else if((value <= 15)&&(value >= -15)){
        m_subte->setTraction(0.0);
        m_subte->setBrake(0.0);
    }else if ((value < -15) && (value >= -95)){
        int br = static_cast<int>((((double)((-1)*value)-15.0)/80.0)*100.0);
        m_subte->setBrake(br);
        if(seActivoFreno){
            m_subte->setEmergencyBeake(false);
            seActivoFreno = false;
        }
    }else if (value < -95){
        m_subte->setEmergencyBeake(true);
        seActivoFreno = true;
    }
}

void TractionController::setClrMode(){
    m_subte->setMode(0);
}

void TractionController::setNeutroMode(){
    m_subte->setMode(1);
}

void TractionController::setCocheraMode(){
    m_subte->setMode(2);
}

void TractionController::setAdelanteMode(){
    m_subte->setMode(3);
}
