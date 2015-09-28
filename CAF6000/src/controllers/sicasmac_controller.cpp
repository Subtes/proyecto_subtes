#include "sicasmac_controller.h"

SicasMac_Controller::SicasMac_Controller(SubteStatus * subte,SicasMac * sicasmac)
    : Base_Controller(subte)
{
    m_subte = subte;
    m_sicasmac = sicasmac;
    cantPantallasSicas=1;
    renglon=0;
    indiceArre = 0;
    cantCochesTotal=6;
    DatosPorCoche=8;
    pantallasicas.clear();
    saveId.clear();
//MODELAR LAS FALLAS COMO UN VECTOR DE INT
//cargoCoches("1;des;con;cerrado;abierto;abierto;cerrado;abierto;cerrado;cerrado;abierto;2;con;con;abierto;abierto;abierto;abierto;abierto;cerrado;cerrado;abierto;3;des;con;abierto;abierto;cerrado;cerrado;abierto;abierto;cerrado;cerrado;4;con;con;abierto;abierto;cerrado;cerrado;abierto;abierto;abierto;abierto;5;con;con;abierto;abierto;cerrado;cerrado;cerrado;abierto;abierto;abierto;6;con;con;abierto;abierto;abierto;cerrado;abierto;abierto;cerrado;abierto;");

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

    if(mensaje != ""){
        QStringList strList;
        strList = separoCaracteres(mensaje);
        if(strList.at(3)=="alta"){
            if(saveId.contains(mensaje.split(';')[0])){
               int posicion = buscoPosicion(mensaje.split(';')[0]);
               if (posicion != -1){
                    pantallasicas.replace(posicion,mensaje);
                    m_sicasmac->textEditSicas(strList[0],strList[1],strList[2],posicion);
                  }
            }
            else
            {
                saveId.push_back(strList[0]);
                pantallasicas.push_back(mensaje);
                m_sicasmac->textEditSicas(strList[0],strList[1],strList[2],renglon);
                renglon= renglon + 1;
                indiceArre = indiceArre +1;
                m_sicasmac->actualizarTamArreRenglon(renglon,indiceArre);

                if (renglon==5){
                    cantPantallasSicas++;
                    renglon=0;
              //      renglon = (int)(renglon/cantPantallasSicas);
                }
            }
        }
    else
       {
   //     qDebug() << " NO COMPÁRA BIEN LOS STRING  ";
        bajaMensaje(strList[0]);
        }
    }
}
void SicasMac_Controller::visualizarArreglo(){

    for (int var = 0; var < pantallasicas.size(); ++var) {
        qDebug() << " visualizo los valores del arreglo pantallasicas  "<< pantallasicas.at(var);

    }
}
//BIEN
void SicasMac_Controller::bajaMensaje(QString texto){
    int posicion = buscoPosicion(texto);
    if(posicion !=-1){
            pantallasicas.removeAt(posicion);
            refrescoVista();
          }

}
//BIEN
int SicasMac_Controller::buscoPosicion(QString mensaje){

    for (int var = 0; var < saveId.size(); ++var) {
            if (saveId[var] == mensaje)
                 return var;
    }
    return -1;

}



void SicasMac_Controller::refrescoVista(){
    QStringList  strList;
    for (int var = 0; var < renglon; ++var)
         m_sicasmac->textEditSicas("","","",var);
    renglon--;
    indiceArre--;
    for (int var = 0; var < pantallasicas.size(); ++var) {
        strList = separoCaracteres(pantallasicas[var]);
        m_sicasmac->textEditSicas(strList[0],strList[1],strList[2],var);
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
            //m_sicasmac->insertTrainSicas(tren, estFreno,estTrac);
            for (int datos = 0; datos < DatosPorCoche; ++datos) {
//                qDebug() << " estado puerta  " << cochesList[index] <<"  coche  " << cantPuertas;
                verificoEstPuertas(cochesList[index],cantPuertas); //manda las puertas
                cantPuertas++;
                 index++;
            }
        }
    }
}

void SicasMac_Controller::verificoEstPuertas(QString falla, int cantPuertas){
    if(falla=="abierto"){
        m_sicasmac->turnOnDoors(cantPuertas);}
    if(falla=="cerrado"){
        m_sicasmac->turnOffDoors(cantPuertas);}
 /*   if(falla=="inhab")
       m_sicasmac->turnInhabFailure(coche);
    if(falla=="blink")
       m_sicasmac->turnBlinkFailure(coche);*/
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
