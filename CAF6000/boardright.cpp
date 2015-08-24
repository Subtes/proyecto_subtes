#include "boardright.h"
#include "ui_boardright.h"

BoardRight::BoardRight(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::BoardRight)
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

BoardRight::~BoardRight()
{
    delete ui;
}

void BoardRight::startBoard()
{
    qDebug() << "board right startBoard";

    CircuitBreakerCON_Controller * CON_Disyuntor = new CircuitBreakerCON_Controller(m_subte,ui->CONDisy_widget );
    CircuitBreakerDES_Controller * DES_Disyuntor = new CircuitBreakerDES_Controller(m_subte,ui->DESDisy_widget );

    /********************/
    ui->calientapies->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blue.png"));
    ui->desacople->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));


    m_manometer = new Manometer_Controller(m_subte,ui->manometer);

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
