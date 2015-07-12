#include "hardwareboard.h"
#include "ui_hardwareboard.h"

HardwareBoard::HardwareBoard(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::HardwareBoard)
{
    //SUBTE Model
    m_subte = subte;
    m_eventHandler = eventHandler;

    ui->setupUi(this);
    //    ui->horn->setVisible(false);
    //    ui->ranaDevice->setVisible(false);
    //    ui->setaButton->setVisible(false);
    //    ui->traction->setVisible(false);

        //ui->splash->setVisible(true);
        //ui->splash->resize(this->width(),this->height());

        connect(eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
        connect(eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
        connect(eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
        connect(eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
        connect(eventHandler,SIGNAL(bPressed()),this,SLOT(bocinaON()));
        connect(eventHandler,SIGNAL(bReleased()),this,SLOT(bocinaOFF()));
        connect(eventHandler,SIGNAL(aPressed()),this,SLOT(ranaAD()));
        connect(eventHandler,SIGNAL(ceroPressed()),this,SLOT(ranaCERO()));
        connect(eventHandler,SIGNAL(rPressed()),this,SLOT(ranaAT()));
        connect(eventHandler,SIGNAL(fPressed()),this,SLOT(setaON()));
        connect(eventHandler,SIGNAL(tPressed()),this,SLOT(setaOFF()));

        //Load Board
    //    connect(eventHandler,SIGNAL(downLoaderBoarders()),this,SLOT(downLoadBoard()));

        //Splash
        //connect(this,SIGNAL(readyLoad()),eventHandler, SLOT());
}

HardwareBoard::~HardwareBoard()
{
    delete ui;
}


//bool BoardHardware::loadOk(){
//    emit readyLoad();
//    return true;
//}

void HardwareBoard::downLoadBoard(){
    qDebug()<<"bajando tablerooooo";
}

void HardwareBoard::startBoard(){
    qDebug() << "board hardware startBoard";

//    m_horn = new Horn_Controller(m_subte,ui->horn);
//    m_tractionLever = new TractionLever_Controller(m_subte,ui->traction);
//    m_rana = new Rana_Controller(m_subte,ui->ranaDevice);
//    m_hombreVivo = new HombreVivo_Controller(m_subte,ui->traction);
//    m_setaButton = new Seta_Controller(m_subte, ui->setaButton);

//    ui->horn->setVisible(true);
//    ui->ranaDevice->setVisible(true);
//    ui->setaButton->setVisible(true);
//    ui->traction->setVisible(true);

    //ui->splash->setVisible(false);
    //ui->splash->resize(0,0);
    //this->raise();

//    this->setEnabled(false);
}

void HardwareBoard::enableScreen()
{
    this->setEnabled(true);
}

void HardwareBoard::disableScreen()
{
    this->setEnabled(false);
}

void HardwareBoard::resetControls()
{
//MMB
//    m_tractionLever->setValue(0);
//    m_rana->setValue(0);
//    m_setaButton->resetToOff();
}

void HardwareBoard::bocinaON(){
    m_horn->setBocina(true);
}

void HardwareBoard::bocinaOFF(){
    m_horn->setBocina(false);
}

void HardwareBoard::ranaAD(){
    m_rana->setValue(1);
}

void HardwareBoard::ranaCERO(){
    m_rana->setValue(0);
}

void HardwareBoard::ranaAT(){
    m_rana->setValue(-1);
}

void HardwareBoard::setaON(){
    m_setaButton->setaPressed();
}

void HardwareBoard::setaOFF(){
    m_setaButton->setaReleased();
}
