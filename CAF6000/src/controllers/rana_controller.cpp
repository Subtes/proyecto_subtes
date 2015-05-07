#include "rana_controller.h"

Rana_Controller::Rana_Controller(SubteStatus *modelo, Rana *vista){

    this->m_subte = modelo;
    this->m_ranaTraction = vista;

    connect(m_ranaTraction,SIGNAL(ranaAD()),m_subte,SLOT(ranaAD()));
    connect(m_ranaTraction,SIGNAL(ranaCERO()),m_subte,SLOT(ranaCERO()));
    connect(m_ranaTraction,SIGNAL(ranaAT()),m_subte,SLOT(ranaAT()));

}

Rana_Controller::~Rana_Controller(){

}
