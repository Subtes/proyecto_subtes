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
    m_sicasmac = NULL;
    m_modoConduccion = NULL;
    m_frenoRetencion = NULL;
}

BoardRight::~BoardRight()
{
    delete ui;
}

void BoardRight::startBoard()
{
    qDebug() << "board right startBoard";

    ui->calientapies->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blue.png"));
    ui->desacople->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));

    m_CON_Disyuntor = new CircuitBreakerCON_Controller(m_subte,ui->CONDisy_widget );
    m_DES_Disyuntor = new CircuitBreakerDES_Controller(m_subte,ui->DESDisy_widget );
    m_manometer = new Manometer_Controller(m_subte,ui->manometer);
    m_sicasmac = new SicasMac_Controller(m_subte,ui->sicasmac);
    m_modoConduccion = new LlaveModoConduccion_Controller(m_subte,ui->modoConduccion);
    m_frenoRetencion = new FrenoRetencion_Controller(m_subte,ui->frenoRetencion);

    connect(m_eventHandler,SIGNAL(cargarMensaje(QString)),m_sicasmac,SLOT(separoMensajes(QString)));
    connect(m_eventHandler,SIGNAL(cargarMensajeCocheSicas(QString)),m_sicasmac,SLOT(cargoCoches(QString)));
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
    m_frenoRetencion->turnOff();

    if(state == APAGADO){
        m_manometer->updatePressureRed(0);
        m_manometer->updatePressureWhite(0);
        m_modoConduccion->setManiobraMode();
    }
    else if(state == EN_MARCHA){
        m_manometer->updatePressureRed(m_subte->getPressureRed());
        m_manometer->updatePressureWhite(m_subte->getPressureWhite());
    }
}
