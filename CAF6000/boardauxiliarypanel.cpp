#include "boardauxiliarypanel.h"
#include "ui_boardauxiliarypanel.h"

BoardAuxiliaryPanel::BoardAuxiliaryPanel(QWidget *parent, SubteStatus * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardAuxiliaryPanel)
{
    ui->setupUi(this);

    m_ready = 0;
    m_modelSubway.clear();
    m_view = ui->centralwidget;

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

        bool ok = ui->centralwidget->level1(m_modelSubway);
        connect(m_view,SIGNAL(switchSelected(QString)),this,SLOT(processSelection(QString)));

        qDebug()<< "Configuration recibed to load auxiliary panel OK: "<< ok;
    }
}
/**
 * @brief BoardAuxiliaryPanel::processSelection
 * @param s
 * Emit selection to extern world through EventHandler
 * m_eventHandler->notifyValueChanged("c_termico_33f1"+nrocoche.toStdString(),"con");
 */
void BoardAuxiliaryPanel::processSelection(QString s){

  if (s.contains(";")){

      QStringList keyValue = s.split(";");
      //m_eventHandler->notifyValueChanged((keyValue.at(0)).toStdString(),(keyValue.at(1)).toStdString());

      qDebug()<<"Switch y estado seleccionado:...."<<keyValue.at(0)<<" "<<keyValue.at(1);

    }else{
      qDebug()<<"Error in format selection message from Panel Auxiliary";
  }

}


