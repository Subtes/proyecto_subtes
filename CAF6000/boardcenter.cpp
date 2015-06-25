#include "boardcenter.h"
#include "ui_boardcenter.h"

BoardCenter::BoardCenter(QWidget *parent, SubteStatus * subte) :
    QMainWindow(parent),
    ui(new Ui::BoardCenter)
{
    //SUBTE Model TODO: make it singleton
    if (subte==NULL){
        subte = new SubteStatus();
    }

    //SUBTE Model
    m_subte = subte;

    ui->setupUi(this);

    ui->velocimetro->setVisible(false);
    ui->bypassFreno->setVisible(false);
    ui->bypassTraccion->setVisible(false);
    ui->abrirDerecha->setVisible(false);
    ui->abrirIzquierda->setVisible(false);
    ui->cerrarIzquierda->setVisible(false);
    ui->cerrarDerecha->setVisible(false);
    ui->selectorIzquierda->setVisible(false);
    ui->selectorDerecha->setVisible(false);
    ui->wiper->setVisible(false);
    ui->luzCabina->setVisible(false);
    ui->iluminacionPulsadores->setVisible(false);
    ui->silbato->setVisible(false);
    ui->faros->setVisible(false);
    ui->antivaho->setVisible(false);
    ui->iluminacionReducPulsad->setVisible(false);
    ui->megafonia->setVisible(false);
    ui->publicoCabina->setVisible(false);
    ui->anulacionEmergencia->setVisible(false);

    //ui->splash->setVisible(true);
    //ui->splash->resize(this->width(),this->height());

    connect(m_subte,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_subte,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_subte,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_subte,SIGNAL(controlReset()),this,SLOT(resetControls()));
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

    ui->velocimetro->setVisible(true);
    ui->velocimetro->setVisible(true);
    ui->bypassFreno->setVisible(true);
    ui->bypassTraccion->setVisible(true);
    ui->abrirDerecha->setVisible(true);
    ui->abrirIzquierda->setVisible(true);
    ui->cerrarIzquierda->setVisible(true);
    ui->cerrarDerecha->setVisible(true);
    ui->selectorIzquierda->setVisible(true);
    ui->selectorDerecha->setVisible(true);
    ui->wiper->setVisible(true);
    ui->luzCabina->setVisible(true);
    ui->iluminacionPulsadores->setVisible(true);
    ui->silbato->setVisible(true);
    ui->faros->setVisible(true);
    ui->antivaho->setVisible(true);
    ui->iluminacionReducPulsad->setVisible(true);
    ui->megafonia->setVisible(true);
    ui->publicoCabina->setVisible(true);
    ui->anulacionEmergencia->setVisible(true);

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

    //ui->splash->setVisible(false);
    //ui->splash->resize(0,0);
    this->raise();

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
