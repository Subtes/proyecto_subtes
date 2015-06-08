#include "boardright.h"
#include "ui_boardright.h"

BoardRight::BoardRight(QWidget *parent, SubteStatus * subte) :
    QMainWindow(parent),
    ui(new Ui::BoardRight)
{
    //SUBTE Model TODO: make it singleton
    if (subte==NULL){
        subte = new SubteStatus();
    }

    //SUBTE Model
    m_subte = subte;

    ui->setupUi(this);

    ui->maniobra->setVisible(false);
    ui->manometro->setVisible(false);
    ui->DESDisy_widget->setVisible(false);
    ui->CONDisy_widget->setVisible(false);
    ui->calientapies->setVisible(false);
    ui->frenoRetencion->setVisible(false);
    ui->desacople->setVisible(false);

    ui->splash->setVisible(true);
    ui->splash->resize(this->width(),this->height());

    connect(m_subte,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_subte,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_subte,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_subte,SIGNAL(controlReset()),this,SLOT(resetControls()));
}

BoardRight::~BoardRight()
{
    delete ui;
}

void BoardRight::startBoard()
{
    qDebug() << "board right startBoard";

    ui->maniobra->setVisible(true);
    ui->manometro->setVisible(true);
    ui->DESDisy_widget->setVisible(true);
    ui->CONDisy_widget->setVisible(true);
    ui->calientapies->setVisible(true);
    ui->frenoRetencion->setVisible(true);
    ui->desacople->setVisible(true);

    CircuitBreakerCON_Controller * CON_Disyuntor = new CircuitBreakerCON_Controller(m_subte,ui->CONDisy_widget );
    CircuitBreakerDES_Controller * DES_Disyuntor = new CircuitBreakerDES_Controller(m_subte,ui->DESDisy_widget );

    /********************/
    ui->calientapies->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blue.png"));
    ui->desacople->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));

    ui->manometro->setClearColor(Qt::transparent);
    ui->manometro->setAttribute(Qt::WA_AlwaysStackOnTop);

    ui->splash->setVisible(false);
    ui->splash->resize(0,0);
    this->raise();

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
    ui->calientapies->turnOff();
    ui->desacople->turnOff();
    ui->DESDisy_widget->turnOff();
    ui->CONDisy_widget->turnOff();
}
