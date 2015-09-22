#include "boardtop.h"
#include "ui_boardtop.h"

BoardTop::BoardTop(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardTop)
{
    ui->setupUi(this);

    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
    connect(m_eventHandler,SIGNAL(cargarEstado(int)),this,SLOT(loadState(int)));
    connect(m_eventHandler,SIGNAL(kPressed()),this,SLOT(keyON()));
    connect(m_eventHandler,SIGNAL(lPressed()),this,SLOT(keyOFF()));

    m_connectors = NULL;
    m_topGauges = NULL;
}

BoardTop::~BoardTop()
{
    delete ui;
}

void BoardTop::startBoard()
{
    qDebug() << "board top startBoard";

    ui->seta->setClearColor(Qt::transparent);
    ui->seta->setAttribute(Qt::WA_AlwaysStackOnTop);

  //  ui->llaveTecho->setClearColor(Qt::transparent);
   // ui->llaveTecho->setAttribute(Qt::WA_AlwaysStackOnTop);

    m_connectors = new TopBoardConnectors_Controller(m_subte);
    m_connectors->setBattery(ui->bateriaCON,ui->bateriaDES);
    m_connectors->setPantograph(ui->pantografoCON,ui->pantografoDES);
    m_connectors->setCompressorAux(ui->compAuxCON,ui->compAuxDES);
    m_connectors->setConverter(ui->convertidorCON,ui->convertidorDES);
    m_connectors->setMainCompressor(ui->compPpalCON,ui->compPpalDES);
    m_connectors->setLighting(ui->alumbradoCON,ui->alumbradoDES);
    m_connectors->setAir(ui->aireCON,ui->aireDES);
    m_connectors->setMegaphone(ui->megaforniaCON,ui->megaforniaDES);
    m_connectors->setConmutadorPuestaServicio(ui->llaveManual,ui->puestaEnMarchaDES,ui->puetaEnMarchaCON,ui->automaticoManualDES,ui->automaticoManualCON);
    m_connectors->setParkingBrake(ui->frenoCON,ui->frenoDES);

    m_topGauges = new TopGauges_Controller(m_subte,ui->voltmeter,ui->ammeter,ui->effortmeter);

    m_keyTopBoard = new Key_TopBoard_Controller(m_subte,ui->llaveTecho);

    this->setEnabled(false);
}

void BoardTop::enableScreen()
{
    this->setEnabled(true);
}

void BoardTop::disableScreen()
{
    this->setEnabled(false);
}

void BoardTop::resetControls(){
    loadState(lastState);
    m_keyTopBoard->resetToOff();
}

/**
 * @brief BoardTop::cargarEstado
 * @param nivel= 0 si es "apagado" - 1 si es "en_marcha"
 */
void BoardTop::loadState(int state)
{
    if(state == APAGADO){
        lastState = APAGADO;
        m_connectors->setEstado(APAGADO);

    } else if(state== EN_MARCHA){
        lastState = EN_MARCHA;
        m_connectors->setEstado(EN_MARCHA);
    }
    m_connectors->reset();
}

void BoardTop::keyON(){
    m_keyTopBoard->keyTurnON();
}

void BoardTop::keyOFF(){
    m_keyTopBoard->keyTurnOFF();
}
