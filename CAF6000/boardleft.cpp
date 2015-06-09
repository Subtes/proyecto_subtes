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

    Atp_Controller *atp = new Atp_Controller(subte,ui->widget_atp);
}

BoardLeft::~BoardLeft()
{
    delete ui;
}
