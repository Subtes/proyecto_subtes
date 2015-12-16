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

        bool ok = ui->centralwidget->level1(m_modelSubway);
        connect(m_view,SIGNAL(switchSelected(QString)),this,SLOT(processSelection(QString)));

        qDebug()<< "Configuration recibed to load auxiliary panel OK: "<< ok;
    }else{
        this->m_modelSubway.append("-");
    }
}
/**
 * @brief BoardAuxiliaryPanel::processSelection
 * @param s
 * Emit selection to extern world through EventHandler
 * m_eventHandler->notifyValueChanged("c_termico_33f1"+nrocoche.toStdString(),"con");
 */
void BoardAuxiliaryPanel::processSelection(QString s){
    //"c_grifo;b-120;coche1;des"
    QString namePanel,numberWagon,numberSwtich,stateSwitch = "";
    QString moncho;

  if (s.contains(";")){

          QStringList keyValue = s.split(";");
          namePanel.append(keyValue.at(0));
          numberSwtich.append(keyValue.at(1));
          numberWagon.append(keyValue.at(2));
          stateSwitch.append(keyValue.at(3));

          moncho.append(numberWagon+";").append(namePanel+";").append(numberSwtich+";").append(stateSwitch);
          qDebug()<< "Informacion de paneles para SICAS:---->" << moncho;

          if ((keyValue.size() == 4) && (namePanel != "" && numberSwtich != "" && numberWagon != "" && stateSwitch != "") ){

//              if(numberWagon == "1"){
//                  m_eventHandler->notifyValueChanged((namePanel.append(numberSwtich)).toStdString(),
//                                                         stateSwitch.toStdString());
//              }else{
//                  m_eventHandler->notifyValueChanged((namePanel.append(numberSwtich+"_"+numberWagon)).toStdString(),
//                                                         stateSwitch.toStdString());
//              }
                  if (numberWagon == "1"){
                      m_eventHandler->notifyValueChanged(namePanel.append(numberSwtich).toStdString(),
                                                         stateSwitch.toStdString());
                      //Agrego esta lines asi le pega a todos los coches 1, despues de integracion la saco.
                      m_eventHandler->notifyValueChanged((namePanel.append(numberSwtich)).toStdString(),
                                                         numberWagon.toStdString(),
                                                         stateSwitch.toStdString());
                  }else{
                      m_eventHandler->notifyValueChanged((namePanel.append(numberSwtich)).toStdString(),
                                                         numberWagon.toStdString(),
                                                         stateSwitch.toStdString());
                  }
              m_subte->setSwitch(moncho);
              qDebug()<<"Panel, Switch, Vagon y Estado seleccionado:...."<<namePanel<<" "<<numberSwtich<<" "<<numberWagon<<" "<<stateSwitch;
        //size == 4 && ...
        }else{
              qDebug()<<"Error en parametros recibidos en seleccion de Paneles Auxiliares, "
                        "tienen espacio vacio o menor a 4 parametros, los cuales no pueden ser emitidos por enet ...>"<< s;
          }
     //contains ";"
    }else{
      qDebug()<<"Error in format selection message from Panel Auxiliary";
  }

}//processSelection


