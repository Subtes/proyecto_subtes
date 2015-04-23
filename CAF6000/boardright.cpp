#include "boardright.h"
#include "ui_boardright.h"

BoardRight::BoardRight(QWidget *parent, SubteStatus * subte) :
    QMainWindow(parent),
    ui(new Ui::BoardRight)
{
    if (subte==NULL){
        subte = new SubteStatus();
    }
    //SUBTE Model
    m_subte = subte;

    ui->setupUi(this);
}

BoardRight::~BoardRight()
{
    delete ui;
}
