#include "boardcenter.h"
#include "ui_boardcenter.h"

BoardCenter::BoardCenter(QWidget *parent, SubteStatus * subte) :
    QMainWindow(parent),
    ui(new Ui::BoardCenter)
{
    if (subte==NULL){
        subte = new SubteStatus();
    }
    //SUBTE Model
    m_subte = subte;

    ui->setupUi(this);

    Wiper_Controller *wiper = new Wiper_Controller(m_subte,ui->wiper);
    EmergencyOverride_Controller *emergencyOverride = new EmergencyOverride_Controller(m_subte,ui->anulacionEmergencia);
    TractionBypass_Controller *tractionBypass = new TractionBypass_Controller(m_subte,ui->bypassTraccion);
    SpeedGaugeLeds_Controller *speedGauge = new SpeedGaugeLeds_Controller(subte,ui->velocimetro);

    /***************************/
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
}

BoardCenter::~BoardCenter()
{
    delete ui;
}
