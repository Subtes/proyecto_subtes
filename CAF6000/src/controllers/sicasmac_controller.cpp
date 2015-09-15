#include "sicasmac_controller.h"

SicasMac_Controller::SicasMac_Controller(SubteStatus * subte,SicasMac * sicasmac)
    : Base_Controller(subte)
{
    m_subte = subte;
    m_sicasmac = sicasmac;
    m_sicasmac->setBackgroudImage(QUrl("qrc:/resources/sicas_bkg.jpg"));
    m_sicasmac->setGlassImage(QUrl("qrc:/resources/sicas_glass.png"));
    m_sicasmac->setStartTrain(QUrl("qrc:/resources/sicas_azul.png"));
    m_sicasmac->setEndTrain(QUrl("qrc:/resources/sicas_azul.png"));
    renglon=0;

//MODELAR LAS FALLAS COMO UN VECTOR DE INT



}

SicasMac_Controller::~SicasMac_Controller()
{

}

/**
 * @brief SicasMac_Controller::separoMensajes
 *  Separa y genera los mensajes en el sicas. Desde todo el mensaje y los encapsula de a 4 por el id! que
 *  donde este no es visualizado.
 * @param mensaje
 */
void SicasMac_Controller::separoMensajes(QString mensaje){

    QStringList strList;
    strList = mensaje.split(';');
    qDebug() << " error  "<< mensaje ;
     // if(strList[3]=="alta"){
        pantallasicas[renglon].append(mensaje);
        int mens=0;
        QString error;QString trenes;QString letra;
        //while (mens < strList.size()){
       // mens = mens+1;
        error=strList[mens];
        mens = mens+1;
        trenes=strList[mens];
        mens = mens+1;
        letra = strList[mens];
       qDebug() << " error  "<< error << "  trenes  "<< trenes << " letra " << letra << "  pantallasicas[renglon]  "<< pantallasicas[renglon] ;
        m_sicasmac->textEditSicas(error,trenes,letra,renglon);
        mens = mens+1;
        renglon= renglon + 1;
        if (renglon==5)
             renglon = 0;
      /*  }
    else
        bajaMensajes(strList[0]);*/
    }



void SicasMac_Controller::bajaMensajes(QString mensaje){


  /*  for (int var = 0; var < pantallasicas[var].size(); ++var) {
            if (pantallasicas[var].split(';')[0]==mensaje)
                moverArriba(var,pantallasicas[var].size());
    }*/
}

void SicasMac_Controller::moverArriba(int var,int fin){
   /* while(var<=fin)
    {
        if (var+1<=fin)
         {
            pantallasicas[var] = pantallasicas[var+1];
          }
       var=var+1;
    }*/
}
