#include "boardtop.h"
#include "ui_boardtop.h"

BoardTop::BoardTop(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::BoardTop)
{
    //SUBTE Model
    m_subte = subte;
    m_eventHandler = eventHandler;

    ui->setupUi(this);

//    ui->bateriaCON->setVisible(false);
//    ui->bateriaDES->setVisible(false);
//    ui->pantografoCON->setVisible(false);
//    ui->pantografoDES->setVisible(false);
//    ui->compAuxCON->setVisible(false);
//    ui->compAuxDES->setVisible(false);
//    ui->compPpalCON->setVisible(false);
//    ui->compPpalDES->setVisible(false);
//    ui->convertidorCON->setVisible(false);
//    ui->convertidorDES->setVisible(false);
//    ui->alumbradoCON->setVisible(false);
//    ui->alumbradoDES->setVisible(false);
//    ui->aireCON->setVisible(false);
//    ui->aireDES->setVisible(false);
//    ui->frenoCON->setVisible(false);
//    ui->frenoDES->setVisible(false);
//    ui->megaforniaCON->setVisible(false);
//    ui->megaforniaDES->setVisible(false);
//    ui->automaticoManualCON->setVisible(false);
//    ui->automaticoManualDES->setVisible(false);
//    ui->puetaEnMarchaCON->setVisible(false);
//    ui->puestaEnMarchaDES->setVisible(false);
//    ui->llaveManual->setVisible(false);
//    ui->seta->setVisible(false);
//    ui->seta->setVisible(false);
//    ui->llave->setVisible(false);
//    ui->llave->setVisible(false);
//    ui->emergenciaSICAS->setVisible(false);


//    ui->splash->setVisible(true);
//    ui->splash->resize(this->width(),this->height());

    connect(m_eventHandler,SIGNAL(controlReady()),this,SLOT(startBoard()));
    connect(m_eventHandler,SIGNAL(controlDisable()),this,SLOT(disableScreen()));
    connect(m_eventHandler,SIGNAL(controlEnable()),this,SLOT(enableScreen()));
    connect(m_eventHandler,SIGNAL(controlReset()),this,SLOT(resetControls()));

}

BoardTop::~BoardTop()
{
    delete ui;
}

void BoardTop::startBoard()
{
    qDebug() << "board top startBoard";

//    ui->bateriaCON->setVisible(true);
//    ui->bateriaDES->setVisible(true);
//    ui->pantografoCON->setVisible(true);
//    ui->pantografoDES->setVisible(true);
//    ui->compAuxCON->setVisible(true);
//    ui->compAuxDES->setVisible(true);
//    ui->compPpalCON->setVisible(true);
//    ui->compPpalDES->setVisible(true);
//    ui->convertidorCON->setVisible(true);
//    ui->convertidorDES->setVisible(true);
//    ui->alumbradoCON->setVisible(true);
//    ui->alumbradoDES->setVisible(true);
//    ui->aireCON->setVisible(true);
//    ui->aireDES->setVisible(true);
//    ui->frenoCON->setVisible(true);
//    ui->frenoDES->setVisible(true);
//    ui->megaforniaCON->setVisible(true);
//    ui->megaforniaDES->setVisible(true);
//    ui->automaticoManualCON->setVisible(true);
//    ui->automaticoManualDES->setVisible(true);
//    ui->puetaEnMarchaCON->setVisible(true);
//    ui->puestaEnMarchaDES->setVisible(true);
//    ui->llaveManual->setVisible(true);
//    ui->seta->setVisible(true);
//    ui->seta->setVisible(true);
//    ui->llave->setVisible(true);
//    ui->llave->setVisible(true);
//    ui->emergenciaSICAS->setVisible(true);

    ui->bateriaCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->bateriaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->pantografoCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->pantografoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->compAuxCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->compAuxDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->compPpalCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->compPpalDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->convertidorCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->convertidorDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->alumbradoCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->alumbradoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->aireCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->aireDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->frenoCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->frenoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->megaforniaCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->megaforniaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->emergenciaSICAS->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->automaticoManualCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->automaticoManualDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->puetaEnMarchaCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->puestaEnMarchaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));

    ui->llaveManual->setButtonImage(QUrl("qrc:/resources/techo_manual_down.png"),QUrl("qrc:/resources/techo_manual_up.png"));

    ui->seta->setClearColor(Qt::transparent);
    ui->seta->setAttribute(Qt::WA_AlwaysStackOnTop);

    ui->llave->setClearColor(Qt::transparent);
    ui->llave->setAttribute(Qt::WA_AlwaysStackOnTop);

//    ui->splash->setVisible(false);
//    ui->splash->resize(0,0);
//    this->raise();

    //this->setEnabled(false);
}

void BoardTop::enableScreen()
{
    this->setEnabled(true);
}

void BoardTop::disableScreen()
{
    this->setEnabled(false);
}

void BoardTop::resetControls(){
    ui->bateriaCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->bateriaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->pantografoCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->pantografoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->compAuxCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->compAuxDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->compPpalCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->compPpalDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->convertidorCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->convertidorDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->alumbradoCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->alumbradoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->aireCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->aireDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->frenoCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->frenoDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->megaforniaCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->megaforniaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->emergenciaSICAS->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->automaticoManualCON->setButtonImage(QUrl("qrc:/resources/redON_CON_techo.png"),QUrl("qrc:/resources/red_CON_techo.png"));
    ui->automaticoManualDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
    ui->puetaEnMarchaCON->setButtonImage(QUrl("qrc:/resources/red_CON_techo.png"),QUrl("qrc:/resources/redON_CON_techo.png"));
    ui->puestaEnMarchaDES->setButtonImage(QUrl("qrc:/resources/greenON_DES_techo.png"),QUrl("qrc:/resources/green_DES_techo.png"));
}
