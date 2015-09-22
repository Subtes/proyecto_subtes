#include "boardleft.h"
#include "ui_boardleft.h"

BoardLeft::BoardLeft(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardLeft)
{
    ui->setupUi(this);

    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
    connect(m_eventHandler,SIGNAL(cargarEstado(int)),this,SLOT(loadState(int)));

    m_atp = NULL;
}

BoardLeft::~BoardLeft()
{
    delete ui;
    delete m_atp;
}

void BoardLeft::startBoard()
{
    qDebug() << "board Left startBoard";

    m_atp = new Atp_Controller(m_subte,ui->widget_atp,m_eventHandler);

    this->setEnabled(false);
}

void BoardLeft::enableScreen()
{
    this->setEnabled(true);
}

void BoardLeft::disableScreen()
{
    this->setEnabled(false);
}

/**
 * @brief BoardLeft::resetControls: vuelve al ultimo estado cargado. por defecto es APAGADO
 */
void BoardLeft::resetControls(){
    loadState(lastState);
}

/**
 * @brief BoardLeft::loadState: ejecuta un reseteo
 * comun a todos los estados y luego, segun el estado,
 * ejecutas las modificaciones correspondientes
 * @param state
 */
void BoardLeft::loadState(int state){

    if(state == APAGADO){
        lastState = APAGADO;
        if (m_atp){
            m_atp->resetATP();
        }
    }
    else if(state == EN_MARCHA){
        lastState = EN_MARCHA;
        if (m_atp){
            m_atp->initATP();
        }
    }
}
