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
}

BoardCenter::~BoardCenter()
{
    delete ui;
}
