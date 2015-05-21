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

    /********************/
    ui->calientapies->setButtonImage(QUrl("qrc:/resources/blueON.png"),QUrl("qrc:/resources/blue.png"));
    ui->desacople->setButtonImage(QUrl("qrc:/resources/greenON.png"),QUrl("qrc:/resources/green.png"));

    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
}

BoardRight::~BoardRight()
{
    delete ui;
}
