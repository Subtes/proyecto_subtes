#include "boardhardware.h"
#include "ui_boardhardware.h"

BoardHardware::BoardHardware(QWidget *parent, SubteStatus * subte) :
    QMainWindow(parent),
    ui(new Ui::BoardHardware)
{
    if (subte==NULL){
        subte = new SubteStatus();
    }
    //SUBTE Model
    m_subte = subte;

    ui->setupUi(this);
}

BoardHardware::~BoardHardware()
{
    delete ui;
}
