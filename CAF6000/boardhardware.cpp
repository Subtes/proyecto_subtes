#include "boardhardware.h"
#include "ui_boardhardware.h"

BoardHardware::BoardHardware(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardHardware)
{
    ui->setupUi(this);

    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
    connect(m_eventHandler,SIGNAL(cargarEstado(int)),this,SLOT(loadState(int)));
    connect(m_eventHandler,SIGNAL(bPressed()),this,SLOT(bocinaON()));
    connect(m_eventHandler,SIGNAL(bReleased()),this,SLOT(bocinaOFF()));
    connect(m_eventHandler,SIGNAL(aPressed()),this,SLOT(ranaAD()));
    connect(m_eventHandler,SIGNAL(ceroPressed()),this,SLOT(ranaCERO()));
    connect(m_eventHandler,SIGNAL(rPressed()),this,SLOT(ranaAT()));
    connect(m_eventHandler,SIGNAL(fPressed()),this,SLOT(setaON()));
    connect(m_eventHandler,SIGNAL(tPressed()),this,SLOT(setaOFF()));

    m_horn = NULL;
    m_tractionLever = NULL;
    m_rana = NULL;
    m_hombreVivo = NULL;
    m_setaButton = NULL;

}

BoardHardware::~BoardHardware()
{
    delete ui;
}

void BoardHardware::startBoard()
{
    qDebug() << "board hardware startBoard";

    m_horn = new Horn_Controller(m_subte,ui->horn);
    m_tractionLever = new TractionLever_Controller(m_subte,ui->traction);
    m_rana = new Rana_Controller(m_subte,ui->ranaDevice);
    m_hombreVivo = new HombreVivo_Controller(m_subte,ui->traction);
    m_setaButton = new Seta_Controller(m_subte, ui->setaButton);

    this->setEnabled(false);
}

void BoardHardware::enableScreen()
{
    this->setEnabled(true);
}

void BoardHardware::disableScreen()
{
    this->setEnabled(false);
}

void BoardHardware::resetControls()
{
    loadState(lastState);
}

void BoardHardware::bocinaON()
{
    m_horn->setBocina(true);
}

void BoardHardware::bocinaOFF()
{
    m_horn->setBocina(false);
}

void BoardHardware::ranaAD()
{
    m_rana->setValue(1);
}

void BoardHardware::ranaCERO()
{
    m_rana->setValue(0);
}

void BoardHardware::ranaAT()
{
    m_rana->setValue(-1);
}

void BoardHardware::setaON()
{
    m_setaButton->setaPressed();
}

void BoardHardware::setaOFF()
{
    m_setaButton->setaReleased();
}

void BoardHardware::loadState(int state){

    m_tractionLever->setValue(0);
    m_rana->setValue(0);
    m_setaButton->resetToOff();

    if(state == APAGADO){
        lastState = APAGADO;
    }
    else if(state == EN_MARCHA){
        lastState = EN_MARCHA;
    }
}
