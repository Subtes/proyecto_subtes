#include "sicasmac_controller.h"

SicasMac_Controller::SicasMac_Controller(SubteStatus * subte,SicasMac * sicasmac)
    : Base_Controller(subte)
{
    m_subte = subte;
    m_sicasmac = sicasmac;
    cantPantallasSicas=1;
    renglon=-1;
    maxRenglonesSicas=4;
    indiceArre = 0;
    cantCochesTotal=6;
    DatosPorCoche=8;
    pantallasicas.clear();
    saveId.clear();
    connect(m_sicasmac,SIGNAL(onPressSigRow()),this,SLOT(onPressSigRow()));
    connect(m_sicasmac,SIGNAL(onPressAntRow()),this,SLOT(onPressAntRow()));
    connect(m_subte,SIGNAL(atpOn()),m_sicasmac,SLOT(turnOnSicas()));
    connect(m_subte,SIGNAL(atpOff()),m_sicasmac,SLOT(turnOffSicas()));
    connect(m_sicasmac,SIGNAL(sicasOk()),m_subte,SLOT(setSicasOk()));

}

SicasMac_Controller::~SicasMac_Controller()
{

}

void SicasMac_Controller::onPressSigRow(){
    int posicion = m_sicasmac->getPosActualRenglon();
    cantPantallasSicas= floor(posicion/5);
    int actual=0;
    if (posicion < pantallasicas.size()){
        m_sicasmac->turnOnSiguiente();
        actual=(posicion%5);
        if(actual>0){
            m_sicasmac->sigPosicionSicas();
            m_sicasmac->turnOnAnterior();
        }
        else{
            refrescoVista();
            m_sicasmac->initRenglonSicas();
        }
    }

    if(m_sicasmac->getPosActualRenglon()==(pantallasicas.size()-1)){
        m_sicasmac->turnOffSiguiente();
        m_sicasmac->turnOnAnterior();
    }
}

void SicasMac_Controller::onPressAntRow(){
    int posicion = m_sicasmac->getPosActualRenglon();
    cantPantallasSicas= floor(posicion/5);
    int actual=0;
    if (posicion>0){
        m_sicasmac->turnOnAnterior();
        m_sicasmac->turnOnSiguiente();
        actual=(posicion%5);
        if(actual>0){
            m_sicasmac->antPositionSicas();
        }
        else{
            m_sicasmac->endRenglonSicas();
            posicion = m_sicasmac->getPosActualRenglon();
            cantPantallasSicas= floor(posicion/5);
            refrescoVista();
        }
    }
    if(m_sicasmac->getPosActualRenglon()==0){
        m_sicasmac->turnOffAnterior();
        m_sicasmac->turnOnSiguiente();
    }

}


/**
 * @brief SicasMac_Controller::separoMensajes
 *  Separa y genera los mensajes en el sicas. Desde todo el mensaje y los encapsula de a 4 por el id! que
 *  donde este no es visualizado.
 * @param mensaje
 */
void SicasMac_Controller::separoMensajes(QString mensaje){
    if(mensaje != ""){
        QStringList strList;
        strList = separoCaracteres(mensaje);
        if(strList.at(3)=="alta"){
            if(saveId.contains(mensaje.split(';')[0])){
                int posicion = buscoPosicion(mensaje.split(';')[0]);
                if (posicion >= 0){
                    pantallasicas.replace(posicion,mensaje);
                    m_sicasmac->textEditSicas(strList[0],strList[1],strList[2],posicion);
                }
            }
            else
            {
                saveId.push_back(strList[0]);
                pantallasicas.push_back(mensaje);
                renglon++;
                if (renglon<5){
                    m_sicasmac->textEditSicas(strList[0],strList[1],strList[2],renglon);
                }
                m_sicasmac->actualizarTamArreRenglon(renglon);
             }
            if (renglon >2){
                m_sicasmac->turnOnSiguiente();
            }
        }
        else //baja
        {
            bajaMensaje(strList[0]);
        }
    }
}


//X para los casos en que la pantalla tiene un valor y este se borra, actualiza lo anterior
void SicasMac_Controller::bajaMensaje(QString texto){
    int posicion = buscoPosicion(texto);
    if(posicion >= 0){
        pantallasicas.removeAt(posicion);
        saveId.removeAt(posicion);
        cantPantallasSicas= floor((posicion-1)/5);//X
        if (posicion==0){
            cantPantallasSicas=0;
        }
        refrescoVista();
        renglon--;
        m_sicasmac->actualizarTamArreRenglon(renglon);
        m_sicasmac->initRenglonSicas();

   }
}
//BIEN
int SicasMac_Controller::buscoPosicion(QString mensaje){

    for (int var = 0; var < saveId.size(); var++) {
        if (saveId[var] == mensaje)
            return var;
    }
    return -1;

}

//REFRESCO LA VISTA DE LOS RENGLONES DEL SICAS siempre es de 0 a 4 no importa la pantalla

void SicasMac_Controller::borrarPantallaSicas(){
    for (int var = 0; var < 5; var++){
        m_sicasmac->textEditSicas(" "," "," ",var);
    }
}



void SicasMac_Controller::refrescoVista(){
    QStringList  strList;
    int actual;
    int inicio = (cantPantallasSicas*5);
    int fin = ((cantPantallasSicas+1)*5);
    if (fin > pantallasicas.size()){
        fin= pantallasicas.size();
    }
    borrarPantallaSicas();
    for (int var = inicio; var < fin ;var++) {
        actual=(var%5);
        strList = separoCaracteres(pantallasicas[var]);
        m_sicasmac->textEditSicas(strList[0],strList[1],strList[2],actual);
    }
}


QStringList SicasMac_Controller::separoCaracteres(QString mensaje){
     return (mensaje.split(';'));
}


void SicasMac_Controller::cargoCoches(QString mensajeCoches){
    int index =0;
    int cantPuertas=0;
    QString tren, estFreno,estTrac;
    if(mensajeCoches != ""){
        QStringList cochesList;
        cochesList = mensajeCoches.split(';');

        for (int coche = 0; coche < cantCochesTotal; ++coche) {
            tren=cochesList[index];
            index++;
            estFreno=cochesList[index];
            index++;
            estTrac=cochesList[index];
            index++;
            verificoEstFalla(estFreno,coche);
            for (int datos = 0; datos < DatosPorCoche; ++datos) {
                verificoEstPuertas(cochesList[index],cantPuertas); //manda las puertas
                cantPuertas++;
                index++;
            }
        }
    }
}

//Senal manda colo
void SicasMac_Controller::frenoRetencionActivado(){


}

void SicasMac_Controller::verificoEstPuertas(QString falla, int cantPuertas){
    if(falla=="abierto"){
        m_sicasmac->turnOnDoors(cantPuertas);}
    if(falla=="cerrado"){
        m_sicasmac->turnOffDoors(cantPuertas);}
       if(falla=="inhab")
       m_sicasmac->turnInhabFailure(cantPuertas);
    if(falla=="int")
       m_sicasmac->turnBlinkFailure(cantPuertas);
}

void SicasMac_Controller::verificoEstFalla(QString falla, int coche){
    if(falla=="con")
        m_sicasmac->turnOnFailure(coche);
    if(falla=="des")
        m_sicasmac->turnOffFailure(coche);
    if(falla=="inhab")
        m_sicasmac->turnInhabFailure(coche);
    if(falla=="int")
        m_sicasmac->turnBlinkFailure(coche);
}
