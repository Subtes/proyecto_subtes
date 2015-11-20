#include "boardauxiliarypanel.h"
#include "ui_boardauxiliarypanel.h"

BoardAuxiliaryPanel::BoardAuxiliaryPanel(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardAuxiliaryPanel)
{
    ui->setupUi(this);

    m_ready = 0;
    m_modelSubway.clear();

    connect(m_eventHandler,SIGNAL(configWagon(QString)),this,SLOT(setSubte(QString)));
    connect(m_eventHandler,SIGNAL(modelSubwayReceived(QString)),this,SLOT(setSubte(QString)));
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

    m_ready = 0;
    m_modelSubway.clear();
    qDebug()<<"Reset Controls: "<< "Ready: "<< m_ready<<" Model Subway: "<< m_modelSubway;
}

void BoardAuxiliaryPanel::loadState(int state){
    //Cambiar por 6 en caso de precisar, falta configurar, queda no habilitado por ahora hasta desarrollarce.
    //m_eventHandler->enableDiffusion();
}

void BoardAuxiliaryPanel::setSubte(QString s){

    this->m_modelSubway.append(s);
    m_ready ++;

    qDebug()<<"Append to Model Subte " <<m_modelSubway <<" configuration: "<< s <<"Ready: "<< m_ready;

    if (m_ready == 2){
        //Q_ASSERT(!(ui->centralwidget->level1(m_modelSubway)));
        qDebug()<<"Entro en if m_ready";
        bool ok = ui->centralwidget->level1(m_modelSubway);
        qDebug()<< "OK: "<< ok;
    }
}
