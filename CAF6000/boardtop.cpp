#include "boardtop.h"
#include "ui_boardtop.h"

BoardTop::BoardTop(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::BoardTop)
{
    //SUBTE Model
    m_subte = subte;
    m_eventHandler = eventHandler;

    ui->setupUi(this);

    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
    connect(m_eventHandler,SIGNAL(cargarEstado(int)),this,SLOT(cargarEstado(int)));
}

BoardTop::~BoardTop()
{
    delete m_subte;
    delete m_eventHandler;
    delete ui;
}

void BoardTop::startBoard()
{
    qDebug() << "board top startBoard";

    ui->seta->setClearColor(Qt::transparent);
    ui->seta->setAttribute(Qt::WA_AlwaysStackOnTop);

    ui->llave->setClearColor(Qt::transparent);
    ui->llave->setAttribute(Qt::WA_AlwaysStackOnTop);

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
    m_connectors->setRetentionBrake(ui->frenoCON,ui->frenoDES);

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
    m_connectors->reset();
}

void BoardTop::cargarEstado(int nivel)
{
    if(nivel==0){
        m_connectors->setNivel(0);
    }else if(nivel==1){
        m_connectors->setNivel(1);
    }else if(nivel==2){
        m_connectors->setNivel(2);
    }
    m_connectors->reset();
}
