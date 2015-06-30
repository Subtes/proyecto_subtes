#include "boardhardware.h"
#include "ui_boardhardware.h"

BoardHardware::BoardHardware(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::BoardHardware)
{
    //SUBTE Model
    m_subte = subte;
    m_eventHandler = eventHandler;

    ui->setupUi(this);

    ui->horn->setVisible(false);
    ui->ranaDevice->setVisible(false);
    ui->setaButton->setVisible(false);
    ui->traction->setVisible(false);

    //ui->splash->setVisible(true);
    //ui->splash->resize(this->width(),this->height());

    connect(eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
}

BoardHardware::~BoardHardware()
{
    delete ui;
}

void BoardHardware::startBoard(){
    qDebug() << "board hardware startBoard";

    m_horn = new Horn_Controller(m_subte,ui->horn);
    m_tractionLever = new TractionLever_Controller(m_subte,ui->traction);
    m_rana = new Rana_Controller(m_subte,ui->ranaDevice);
    m_hombreVivo = new HombreVivo_Controller(m_subte,ui->traction);
    m_setaButton = new Seta_Controller(m_subte, ui->setaButton);

    ui->horn->setVisible(true);
    ui->ranaDevice->setVisible(true);
    ui->setaButton->setVisible(true);
    ui->traction->setVisible(true);

    //ui->splash->setVisible(false);
    //ui->splash->resize(0,0);
    this->raise();

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
    m_tractionLever->setValue(0);
    m_rana->setValue(0);
    m_setaButton->resetToOff();
}

