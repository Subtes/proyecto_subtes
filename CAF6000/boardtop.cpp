#include "boardtop.h"
#include "ui_boardtop.h"

BoardTop::BoardTop(QWidget *parent, SubteStatus * subte) :
    QMainWindow(parent),
    ui(new Ui::BoardTop)
{
    if (subte==NULL){
        subte = new SubteStatus();
    }
    //SUBTE Model
    m_subte = subte;

    ui->setupUi(this);

    ui->bateriaCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->bateriaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->pantografoCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->pantografoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->compAuxCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->compAuxDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->compPpalCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->compPpalDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->convertidorCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->convertidorDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->alumbradoCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->alumbradoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->aireCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->aireDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->frenoCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->frenoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->megaforniaCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->megaforniaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));

    ui->automaticoManualCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->automaticoManualDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->puetaEnMarchaCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->puestaEnMarchaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));

    ui->llaveManual->setButtonImage(QUrl("qrc:/resources/techo_manual_down.png"),QUrl("qrc:/resources/techo_manual_up.png"));

    ui->seta->setClearColor(Qt::transparent);
    ui->seta->setAttribute(Qt::WA_AlwaysStackOnTop);

    ui->llave->setClearColor(Qt::transparent);
    ui->llave->setAttribute(Qt::WA_AlwaysStackOnTop);

}

BoardTop::~BoardTop()
{
    delete ui;
}
