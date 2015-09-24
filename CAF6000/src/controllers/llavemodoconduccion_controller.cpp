#include "llavemodoconduccion_controller.h"

LlaveModoConduccion_Controller::LlaveModoConduccion_Controller(SubteStatus *subte, LlaveModoConduccion *llave)
    : Base_Controller(subte)
{
    m_subte = subte;
    m_llave = llave;

    connect(m_llave,SIGNAL(acopleMode()),this,SLOT(setAcopleMode()));
    connect(m_llave,SIGNAL(atpMode()),this,SLOT(setAtpMode()));
    connect(m_llave,SIGNAL(maniobraMode()),this,SLOT(setManiobraMode()));
}

LlaveModoConduccion_Controller::~LlaveModoConduccion_Controller()
{

}

void LlaveModoConduccion_Controller::setManiobraMode(){
    m_subte->setManiobraMode();
}

void LlaveModoConduccion_Controller::setAtpMode(){
    m_subte->setAtpMode();
}

void LlaveModoConduccion_Controller::setAcopleMode(){
    m_subte->setAcopleMode();
}