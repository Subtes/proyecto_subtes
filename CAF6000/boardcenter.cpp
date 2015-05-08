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
    EmergencyOverride_Controller *emergencyOverride = new EmergencyOverride_Controller(m_subte,ui->emerencyOverride);
}

BoardCenter::~BoardCenter()
{
    delete ui;
}
