#include "boardleft.h"
#include "ui_boardleft.h"
#include "src/controllers/atp_controller.h"

BoardLeft::BoardLeft(QWidget *parent, SubteStatus * subte) :
    QMainWindow(parent),
    ui(new Ui::BoardLeft)
{
    if (subte==NULL){
        subte = new SubteStatus();
    }
    //SUBTE Model
    m_subte = subte;

    ui->setupUi(this);

    //this->m_atp = new Atp_Controller(subte,ui->widget_atp);

    connect(m_subte,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_subte,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_subte,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_subte,SIGNAL(controlReset()),this,SLOT(resetControls()));
}

void BoardLeft::startBoard(){
    this->m_atp = new Atp_Controller(this->m_subte,this->ui->widget_atp);
}
void BoardLeft::enableScreen()
{
    this->setEnabled(true);
}
void BoardLeft::disableScreen()
{
    this->setEnabled(false);
}
void BoardLeft::resetControls(){
    m_atp->updateSpeed(0.0);
    m_atp->updateTargetSpeed(0.0);
}

void BoardLeft::probarATP(double s){
    m_atp->updateSpeed(s);
    m_atp->updateTargetSpeed(50.0);
    qDebug() << "Velocidad boardLeft: " << s;

}

BoardLeft::~BoardLeft()
{
    delete ui;
    delete m_atp;
}
