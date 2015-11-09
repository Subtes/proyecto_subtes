#include "boardauxiliarypanel.h"
#include "ui_boardauxiliarypanel.h"

BoardAuxiliaryPanel::BoardAuxiliaryPanel(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardAuxiliaryPanel)
{
    ui->setupUi(this);

    connect(m_eventHandler, SIGNAL(kPressed()),ui->centralwidget,SLOT(level1()));
   // connect(ui->centralwidget->m_qmlView1,SIGNAL(pedalPressed(int)),ui->centralwidget,SLOT(level2(int)));
}

BoardAuxiliaryPanel::~BoardAuxiliaryPanel()
{
    delete ui;
}

void BoardAuxiliaryPanel::startBoard()
{

}

void BoardAuxiliaryPanel::enableScreen()
{
    this->setEnabled(true);
}

void BoardAuxiliaryPanel::disableScreen()
{
    this->setEnabled(false);
}

void BoardAuxiliaryPanel::resetControls(){

}

void BoardAuxiliaryPanel::loadState(int state){
    //Cambiar por 6 en caso de precisar, falta configurar, queda no habilitado por ahora hasta desarrollarce.
    //m_eventHandler->enableDiffusion();
}
