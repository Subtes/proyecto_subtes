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
    estAnteriorFallaCocheSicas.clear();

    connect(m_sicasmac,SIGNAL(onPressSigRow()),this,SLOT(onPressSigRow()));
    connect(m_sicasmac,SIGNAL(onPressAntRow()),this,SLOT(onPressAntRow()));
    connect(m_subte,SIGNAL(bateriaCon()),m_sicasmac,SLOT(turnOnSicas()));
    connect(m_subte,SIGNAL(bateriaDes()),m_sicasmac,SLOT(turnOffSicas()));
    connect(m_sicasmac,SIGNAL(sicasOk()),m_subte,SLOT(setSicasOk()));
    //connect(m_subte,SIGNAL(retentionBrakeChanged(bool)),this,SLOT(ActivoYDesactivoFrenoRetencion(bool)));
}

SicasMac_Controller::~SicasMac_Controller()
{
}


void SicasMac_Controller::cargoVectorEstadoAnteriorFalla(){
    for (int var = 0; var <cantCochesTotal ; ++var) {
        estAnteriorFallaCocheSicas.push_back("normal");
    }
}
/**
 * @brief SicasMac_Controller::onPressSigRow
 *  Actualiza el valor de reenglon siguiente
 * @param mensaje
 */
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

/**
 * @brief SicasMac_Controller::onPressAntRow
 *  Actualizar la posicion del renglon anterior
 * @param mensaje
 */
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
                    generoRenglonesSicas(strList[0],strList[1],strList[2],posicion);
                }
            }
            else
            {
                saveId.push_back(strList[0]);
                pantallasicas.push_back(mensaje);
                renglon++;
                if (renglon<5){
                    generoRenglonesSicas(strList[0],strList[1],strList[2],renglon);
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

/**
 * @brief SicasMac_Controller::generoRenglonesSicas
 *  Genera el Bink en los trenes en los casos en que haya un error en el tren especifico
 * @param mensaje
 */

void SicasMac_Controller::generoRenglonesSicas(QString texto, QString trenes, QString letra, int index){
    QStringList cocheXcoche = trenes.split(" ");
    QString sepCocheLetra;
    QString trenesSinBlink;
    QString trenesConBlink;
    QStringList cocheYLetra;
    QString valorI = "I";
    bool parpadeo = false;
    for (int var = 0; var < cocheXcoche.size(); ++var) {
        trenesSinBlink.push_back("  ");
        trenesConBlink.push_back("  ");
        sepCocheLetra = cocheXcoche[var];

        cocheYLetra =sepCocheLetra.split(",");
        if(cocheYLetra.size()>1){
            if (cocheYLetra[1] == valorI){
                parpadeo = true;
                trenesConBlink.push_back("  ");
            }
            else{
                trenesConBlink.push_back(cocheYLetra[0]);
            }
        }
            trenesSinBlink.push_back(cocheYLetra[0]);

    }
    m_sicasmac->generarTrenesBlink(trenesConBlink, index, parpadeo);

    m_sicasmac->textEditSicas(texto,trenesSinBlink,letra,index);
}

/**
 * @brief SicasMac_Controller::bajaMensaje
 * Borra el mensaje y actualiza la vista
 * @param mensaje
 */

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

/**
 * @brief SicasMac_Controller::buscoPosicion
 *  Buscal posicion exacta del mensaje en el arreglo
 * @param mensaje
 */

int SicasMac_Controller::buscoPosicion(QString mensaje){

    for (int var = 0; var < saveId.size(); var++) {
        if (saveId[var] == mensaje)
            return var;
    }
    return -1;
}

/**
 * @brief SicasMac_Controller::borrarPantallaSicas
 * Refresca la vista del sicas, borrando todos los campos del mismo va de 0 a 4
 * @param mensaje
 */

void SicasMac_Controller::borrarPantallaSicas(){
    for (int var = 0; var < 5; var++){
        m_sicasmac->textEditSicas(" "," "," ",var);
        m_sicasmac->borrarArregloBlinkSicas(" ",var);

    }
}

/**
 * @brief SicasMac_Controller::refrescoVista
 *  Refresca la vista del sicas en los casos en que busque siguiente o anterior.
 * @param mensaje
 */

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
        generoRenglonesSicas(strList[0],strList[1],strList[2],actual);
    }
}


QStringList SicasMac_Controller::separoCaracteres(QString mensaje){
     return (mensaje.split(';'));
}

/**
 * @brief SicasMac_Controller::cargoCoches
 *  Carga las F (fallas) de cada tren, y ademas cada una de las puertas de cada tren
 * @param mensaje
 */

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
            estAnteriorFallaCocheSicas.insert(coche,estFreno);
            for (int datos = 0; datos < DatosPorCoche; ++datos) {
                verificoEstPuertas(cochesList[index],cantPuertas); //manda las puertas
                cantPuertas++;
                index++;
            }
        }
    }
}

/**
 * @brief SicasMac_Controller::frenoRetencionActivado
 *  Carga la Señal cuando se activan el freno y se muestra en el SicasMac
 *  que el freno se activo del mismo modo que si se descativa el mismo es borrado
 * @param mensaje
 */

void SicasMac_Controller::ActivoYDesactivoFrenoRetencion(bool state){
    if(state){
        for (int var = 0; var < cantCochesTotal; ++var) {
            if (estAnteriorFallaCocheSicas[var] == "normal" )
                verificoEstFalla("con",var);
        }
        pantallasicas.push_front("Freno de Retencion; 1,F 2,F 3,F 4,F 5,F 6,F;A;alta");
        renglon++;
        m_sicasmac->actualizarTamArreRenglon(renglon);
        refrescoVista();
    }
    else{
        bajaMensaje("Freno de Retencion");
        for (int var = 0; var < cantCochesTotal; var++) {
            if (estAnteriorFallaCocheSicas[var] == "normal" ){
                verificoEstFalla("des",var);
            }
        }
    }
}

    /**
 * @brief SicasMac_Controller::verificoEstPuertas
 * verifica y pinta el estado de las puertas del tren
 * @param mensaje
 */

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

/**
 * @brief SicasMac_Controller::verificoEstFalla
 * verifica y pinta el estado de las fallas del tren
 * @param mensaje
 */

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
/**
 * @brief SicasMac_Controller::cargarDestinoSicas
 * Carga el Destino en el Sicas, dependiendo de lo que nos pasa instrucciones
 * @param mensaje
 */

void SicasMac_Controller::cargarDestinoSicas(QString destino){
    m_sicasmac->cargoDestinoSicas(destino);
}

void SicasMac_Controller::resetSicas(){
    for (int var = 0; var <= pantallasicas.size(); var++) {
          pantallasicas.removeAt(var);
          saveId.removeAt(var);
    }
    borrarPantallaSicas();
    m_sicasmac->actualizarTamArreRenglon(pantallasicas.size());
    m_sicasmac->initRenglonSicas();
    cargoVectorEstadoAnteriorFalla();

}
