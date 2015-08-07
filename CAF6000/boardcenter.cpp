#include "boardcenter.h"
#include "ui_boardcenter.h"

BoardCenter::BoardCenter(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::BoardCenter)
{
    //SUBTE Model
    m_subte = subte;
    m_eventHandler = eventHandler;

    ui->setupUi(this);
    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
}

BoardCenter::~BoardCenter()
{
    delete ui;
}

void BoardCenter::startBoard()
{
    qDebug() << "board center startBoard";

    Wiper_Controller *wiper = new Wiper_Controller(m_subte,ui->wiper);
    EmergencyOverride_Controller *emergencyOverride = new EmergencyOverride_Controller(m_subte,ui->anulacionEmergencia);
    TractionBypass_Controller *tractionBypass = new TractionBypass_Controller(m_subte,ui->bypassTraccion);
    SpeedGaugeLeds_Controller *speedGauge = new SpeedGaugeLeds_Controller(m_subte,ui->velocimetro);

    ui->cerrarDerecha->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->cerrarIzquierda->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->abrirDerecha->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->abrirIzquierda->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->silbato->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->megafonia->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->antivaho->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->iluminacionReducPulsad->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->iluminacionPulsadores->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->faros->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->luzCabina->setButtonImage(QUrl("qrc:/resources/luzcabinaON.png"),QUrl("qrc:/resources/luzcabina.png"));
    ui->publicoCabina->setButtonImage(QUrl("qrc:/resources/publico-cabinaR.png"),QUrl("qrc:/resources/publico-cabinaL.png"));
    ui->modoConduccion->setClearColor(Qt::transparent);
    ui->modoConduccion->setAttribute(Qt::WA_AlwaysStackOnTop);

    this->setEnabled(false);
}

void BoardCenter::enableScreen()
{
    this->setEnabled(true);
}

void BoardCenter::disableScreen()
{
    this->setEnabled(false);
}

void BoardCenter::resetControls(){
    ui->cerrarDerecha->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->cerrarIzquierda->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->abrirDerecha->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->abrirIzquierda->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));
    ui->silbato->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->megafonia->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->antivaho->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->iluminacionReducPulsad->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->iluminacionPulsadores->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->faros->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blueplane.png"));
    ui->luzCabina->setButtonImage(QUrl("qrc:/resources/luzcabinaON.png"),QUrl("qrc:/resources/luzcabina.png"));
    ui->publicoCabina->setButtonImage(QUrl("qrc:/resources/publico-cabinaR.png"),QUrl("qrc:/resources/publico-cabinaL.png"));
    ui->modoConduccion->setClearColor(Qt::transparent);
    ui->modoConduccion->setAttribute(Qt::WA_AlwaysStackOnTop);

    ui->bypassFreno->turnOff();
    ui->bypassTraccion->turnOff();
    ui->anulacionEmergencia->turnOff();
    ui->velocimetro->updateSpeed(0.0);
    ui->velocimetro->updateTargetSpeed(0.0);
}
