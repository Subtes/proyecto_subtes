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

    CircuitBreakerCON_Controller * CON_Disyuntor = new CircuitBreakerCON_Controller(subte,ui->CONDisy_widget );
    CircuitBreakerDES_Controller * DES_Disyuntor = new CircuitBreakerDES_Controller(subte,ui->DESDisy_widget );
}

BoardRight::~BoardRight()
{
    delete ui;
}
