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

    Horn_Controller *horn = new Horn_Controller(subte,ui->horn);
    TractionLever_Controller *tractionLever = new TractionLever_Controller(subte,ui->traction);
    Rana_Controller *rana = new Rana_Controller(subte,ui->ranaDevice);
    HombreVivo_Controller *hombreVivo = new HombreVivo_Controller(subte,ui->traction);
    Seta_Controller * setaButton = new Seta_Controller(m_subte, ui->setaButton);
}

BoardHardware::~BoardHardware()
{
    delete ui;
}
