#include "boardright.h"
#include "ui_boardright.h"

BoardRight::BoardRight(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardRight)
{
    ui->setupUi(this);

    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
    connect(m_eventHandler,SIGNAL(cargarEstado(int)),this,SLOT(loadState(int)));

    m_manometer = NULL;
    m_CON_Disyuntor = NULL;
    m_DES_Disyuntor = NULL;
}

BoardRight::~BoardRight()
{
    delete ui;
}

void BoardRight::startBoard()
{
    qDebug() << "board right startBoard";

    m_CON_Disyuntor = new CircuitBreakerCON_Controller(m_subte,ui->CONDisy_widget );
    m_DES_Disyuntor = new CircuitBreakerDES_Controller(m_subte,ui->DESDisy_widget );
    m_manometer = new Manometer_Controller(m_subte,ui->manometer);

    ui->calientapies->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blue.png"));
    ui->desacople->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));

    this->setEnabled(false);
}

void BoardRight::enableScreen()
{
    this->setEnabled(true);
}

void BoardRight::disableScreen()
{
    this->setEnabled(false);
}

void BoardRight::resetControls(){
    loadState(lastState);
}

void BoardRight::loadState(int state){
    ui->calientapies->turnOff();
    ui->desacople->turnOff();
    ui->DESDisy_widget->turnOff();
    ui->CONDisy_widget->turnOff();

    if(state == APAGADO){
        ui->manometer->updateNeedleRed(0);
        ui->manometer->updateNeedleWhite(0);
    }
    else if(state == EN_MARCHA){
        ui->manometer->updateNeedleRed(m_subte->getPressureRed());
        ui->manometer->updateNeedleWhite(m_subte->getPressureWhite());
    }
}
