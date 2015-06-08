#include "boardleft.h"
#include "ui_boardleft.h"

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

    this->setEnabled(false);

}

BoardLeft::~BoardLeft()
{
    delete ui;
}
