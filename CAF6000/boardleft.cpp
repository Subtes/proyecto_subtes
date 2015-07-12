#include "boardleft.h"
#include "ui_boardleft.h"

BoardLeft::BoardLeft(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::BoardLeft)
{
    //SUBTE Model
    m_subte = subte;
    m_eventHandler = eventHandler;

    ui->setupUi(this);

    //m_atp = new Atp_Controller(subte, ui->widget_atp, eventHandler);

    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));
}

void BoardLeft::startBoard(){
    this->m_atp = new Atp_Controller(this->m_subte,this->ui->widget_atp,this->m_eventHandler);
        qDebug() << "board Left ATP startBoard";
}
void BoardLeft::enableScreen()
{
    this->setEnabled(true);
}
void BoardLeft::disableScreen()
{
    //this->setEnabled(false);
}
void BoardLeft::resetControls(){
    if (m_atp){
       // m_atp->initATP();
        //m_atp->updateSpeed(0.0);
        m_atp->updateTargetSpeed(5.0);

    }
}

void BoardLeft::probarATP(double s){
    m_atp->updateSpeed(s);
    m_atp->updateTargetSpeed(60.0);
    qDebug() << "Velocidad boardLeft: " << s;

}

BoardLeft::~BoardLeft()
{
    delete ui;
    delete m_atp;
}
