#include "sicasmac_controller.h"

SicasMac_Controller::SicasMac_Controller(SubteStatus * subte,SicasMac * sicasmac, TractionHardware *th)
    : Base_Controller(subte)
{
    m_subte = subte;
    m_sicasmac = sicasmac;
    cantPantallasSicas=0;
    renglon=-1;
    maxRenglonesSicas=4;
    indiceArre = 0;
    cantCochesTotal=6;
    DatosPorCoche=8;
    pantallasicas.clear();
    saveId.clear();
    estAnteriorFallaCocheSicas.clear();
    sicasOn = false;
    offsetCantRows=5;// cantidad de renglones por
    cantdoorsicas=4;//cantidad de puestas por lado de cada coche
    m_hardwareSupport = th;
    m_coche_maquina =1;



    connect(m_sicasmac,SIGNAL(onPressSigRow()),this,SLOT(onPressSigRow()));
    connect(m_sicasmac,SIGNAL(onPressAntRow()),this,SLOT(onPressAntRow()));
    connect(m_subte,SIGNAL(bateriaCon()),this,SLOT(prendoSicas()));
    connect(m_subte,SIGNAL(bateriaDes()),this,SLOT(apagoSicas()));
    connect(m_sicasmac,SIGNAL(sicasOk()),m_subte,SLOT(setSicasOk()));
    connect(m_subte,SIGNAL(hiloLazoChanged(bool)),this,SLOT(estadoFreno(bool)));
    connect(m_subte,SIGNAL(CSCPChanged(bool)),this,SLOT(logicaPuertasSicas(bool)));
    connect(m_subte,SIGNAL(senalDisyuntorDes()),this,SLOT(cargarMensajeDisyuntor()));
    connect(m_subte,SIGNAL(senalDisyuntorCon()),this,SLOT(sacoMensajeDisyuntor()));
    connect(m_subte,SIGNAL(compresorAuxCon()),this,SLOT(sacoMensajeCompDesconectado()));
    connect(m_subte,SIGNAL(compresorAuxDes()),this,SLOT(cargarMensajeCompDesconectado()));
    connect(m_subte,SIGNAL(convertidorCon()),this,SLOT(sacoMensajeConvFueraServicio()));
    connect(m_subte,SIGNAL(convertidorDes()),this,SLOT(cargarMensajeConvFueraServicio()));
    connect(m_subte,SIGNAL(frenoEstacionamientoCon()),this,SLOT(cargarMensajeFrenoEstacAplicado()));
    connect(m_subte,SIGNAL(frenoEstacionamientoDes()),this,SLOT(sacoMensajeFrenoEstacAplicado()));
    connect(m_subte,SIGNAL(estadoManioAcople()),this,SLOT(cargarMensajeAcople()));
    connect(m_subte,SIGNAL(estadoNormal()),this,SLOT(sacoMensajeAcople()));
    connect(m_subte,SIGNAL(cabinChanged(int)),this,SLOT(changeStateCabin(int)));
    connect((m_subte,SIGNAL(changeSwitch(QString)),this,SLOT(updateSwitchMsj(QString))));
    cargoVectorEstadoAnteriorFalla();

}

SicasMac_Controller::~SicasMac_Controller()
{
}


void SicasMac_Controller::cargoVectorEstadoAnteriorFalla(){
    for (int var = 0; var <cantCochesTotal ; var++) {
        estAnteriorFallaCocheSicas.push_back("norm");
    }
}
/**
 * @brief SicasMac_Controller::onPressSigRow
 *  Actualiza el valor de reenglon siguiente
 * @param mensaje
 */
void SicasMac_Controller::onPressSigRow(){
    int posicion = m_sicasmac->getPosActualRenglon();
    cantPantallasSicas= floor(posicion/offsetCantRows);
    int actual=0;
    if (posicion < pantallasicas.size()){
        m_sicasmac->turnOnSiguiente();
        actual=(posicion%offsetCantRows);
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
    cantPantallasSicas= floor(posicion/offsetCantRows);
    int actual=0;
    if (posicion>0){
        m_sicasmac->turnOnAnterior();
        m_sicasmac->turnOnSiguiente();
        actual=(posicion%offsetCantRows);
        if(actual>0){
            m_sicasmac->antPositionSicas();
        }
        else{
            m_sicasmac->endRenglonSicas();
            posicion = m_sicasmac->getPosActualRenglon();
            cantPantallasSicas= floor(posicion/offsetCantRows);
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
 *  donde este no es visualizado. la lógica de los grifos se cargan cuando se desconectan
 * @param mensaje
 */
void SicasMac_Controller::separoMensajes(QString mensaje){
    if(mensaje != ""){
        QStringList strList;
        strList = separoCaracteres(mensaje);
        if((strList.at(3)=="alta")||(strList.at(3)=="des")){
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
                    refrescoVista();
                }
                m_sicasmac->actualizarTamArreRenglon(renglon);
            }
            if (renglon >2){
                m_sicasmac->turnOnSiguiente();
            }
        }
        else if((strList.at(3)=="baja")||(strList.at(3)=="con"))

        {
            bajaMensaje(strList[0]);
        }
        if (strList[2]=="A" && sicasOn){
            emit playSound(2);
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
    int  actual=(index%offsetCantRows);
    QString trenesConBlink;
    QStringList cocheYLetra;
    QString valorI = "I";
    QString valorD = "D";
    bool guion = false;
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
            else if (cocheYLetra[1] == valorD){
                guion = true;
                trenesConBlink.push_back(" - ");
                trenesSinBlink.push_back(" - ");

            }
            else{
                trenesConBlink.push_back(cocheYLetra[0]);
            }
        }
        else{
            trenesConBlink.push_back(cocheYLetra[0]);
        }
        if(!guion){
            trenesSinBlink.push_back(cocheYLetra[0]);
        }
    }
    m_sicasmac->generarTrenesBlink(trenesConBlink, actual, parpadeo);
    m_sicasmac->textEditSicas(texto,trenesSinBlink,letra,actual);
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
        cantPantallasSicas= floor((posicion-1)/offsetCantRows);//X
        if (posicion==0){
            cantPantallasSicas=0;
        }
        renglon--;
        m_sicasmac->actualizarTamArreRenglon(renglon);
        m_sicasmac->initRenglonSicas();
        if (pantallasicas.size()==0){
            m_sicasmac->ponerOnSicasSinIncidencia();
        }
        else{
            m_sicasmac->ponerValoresInicio(cantPantallasSicas);
        }

        if (pantallasicas.size()<=1){
            m_sicasmac->turnOffAnterior();
            m_sicasmac->turnOffSiguiente();

        }
        m_sicasmac->ponerOnSicasSinIncidencia();
        refrescoVista();
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
    for (int var = 0; var < offsetCantRows; var++){
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
    int inicio = (cantPantallasSicas*offsetCantRows);
    int fin = ((cantPantallasSicas+1)*offsetCantRows);
    if (fin > pantallasicas.size()){
        fin= pantallasicas.size();
    }
    borrarPantallaSicas();
    for (int var = inicio; var < fin ;var++) {
        actual=(var%offsetCantRows);
        strList = separoCaracteres(pantallasicas[var]);
        generoRenglonesSicas(strList[0],strList[1],strList[2],actual);
    }
    if(actual > 0){
        m_sicasmac->turnOnSiguiente();
    }
    if (pantallasicas.size()==0){
        m_sicasmac->ponerOnSicasSinIncidencia();
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
    bool mensajePuertas=false;
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
                verificoEstPuertas(cochesList[index],cantPuertas); //las puertas
                if (cochesList[index]== "abierto"){
                    mensajePuertas=true;
                }
                cantPuertas++;
                index++;
            }
        }
        if (mensajePuertas){
            separoMensajes("Puertas Abiertas;1,F 2,F 3,F 4,F 5,F 6,F;C;alta");
            refrescoVista();
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

/**
 * @brief SicasMac_Controller::resetSicas
 * Inicializo todos los valores del sicas
 * @param mensaje
 */

void SicasMac_Controller::resetSicas(){
    pantallasicas.clear();
    saveId.clear();
    cantPantallasSicas=0;
    renglon=-1;
   for (int var = 0; var <= pantallasicas.size(); var++) {
        pantallasicas.removeAt(var);
          saveId.removeAt(var);
    }
    borrarPantallaSicas();
    m_sicasmac->actualizarTamArreRenglon(pantallasicas.size());
    m_sicasmac->initRenglonSicas();
    m_sicasmac->ponerOnSicasSinIncidencia();
    cargoVectorEstadoAnteriorFalla();
    cargarMensajeAcople();

}

/**
 * @brief SicasMac_Controller::estadoHombreMuerto
 * aplica el mensaje de aviso presion freno en los casos en que se aplique algun freno
 * @param mensaje
 */

//agregar para que cambie tambien los coches afectados

void SicasMac_Controller::estadoFreno(bool state){
    QString mensaje="Aviso Presion Frenos;";
    QString s ;
    if(!state){
        for (int var = 0; var < cantCochesTotal; var++) {
            s = QString::number(var+1);
            if (estAnteriorFallaCocheSicas[var] == "norm" ){
                verificoEstFalla("con",var);
                mensaje.append(s);
                mensaje.append(",F ");
            }
            else if (estAnteriorFallaCocheSicas[var] == "int" ){
                mensaje.append(s);
                mensaje.append(",I ");
            }
            else if (estAnteriorFallaCocheSicas[var] == "des" ){
                mensaje.append(s);
                mensaje.append(",D ");
            }
            else{
                mensaje.append(s);
                mensaje.append(",F ");
            }
        }
        mensaje.append(";C;alta");
        separoMensajes(mensaje);
        refrescoVista();
    }
    else{
        bajaMensaje("Aviso Presion Frenos");
        for (int var = 0; var < cantCochesTotal; var++) {
            if (estAnteriorFallaCocheSicas[var] == "norm" ){
                verificoEstFalla("des",var);
            }
        }
    }
}

void SicasMac_Controller::recorridoDePuertas_1Der_2Izq(QString state){
 int cantPuertas=0;
    for (int var = 0; var < cantCochesTotal; var++) {
        for (int datos = 0; datos < cantdoorsicas; datos++) {
            verificoEstPuertas(state,cantPuertas); //las puertas
            cantPuertas++;
        }
        cantPuertas = cantPuertas + cantdoorsicas;
    }
}

void SicasMac_Controller::recorridoDePuertas_1Izq_2Der(QString state){
 int cantPuertas=0;
    for (int var = 0; var < cantCochesTotal; var++) {
        cantPuertas = cantPuertas + cantdoorsicas;
        for (int datos = 0; datos < cantdoorsicas; datos++) {
            verificoEstPuertas(state,cantPuertas); //las puertas
            cantPuertas++;
        }
    }
}

 /**
 * @brief SicasMac_Controller::logicaPuertasSicas
 * genera los guines en el coche para la visual de las puertas abiertas y cerradas
 * @param mensaje
 */
void SicasMac_Controller::logicaPuertasSicas(bool b){
    if(m_subte->leftDoors()){
        recorridoDePuertas_1Izq_2Der("abierto");
        separoMensajes("Puertas Abiertas;1,F 2,F 3,F 4,F 5,F 6,F;C;alta");
        refrescoVista();
    }
    else{
        recorridoDePuertas_1Izq_2Der("cerrado");
        bajaMensaje("Puertas Abiertas");
   }
    if(m_subte->rightDoors()){
        recorridoDePuertas_1Der_2Izq("abierto");
        separoMensajes("Puertas Abiertas;1,F 2,F 3,F 4,F 5,F 6,F;C;alta");
        refrescoVista();
    }
    else{
        recorridoDePuertas_1Der_2Izq("cerrado");
        bajaMensaje("Puertas Abiertas");
    }
}

void SicasMac_Controller::prendoSicas(){
    refrescoVista();
    m_sicasmac->turnOnSicas();
    sicasOn = true;
    changeStateCabin(m_coche_maquina);
}

void SicasMac_Controller::apagoSicas(){
    m_sicasmac->turnOffSicas();
    sicasOn = false;
}


/**
* @brief SicasMac_Controller::logicaPuertasSicas
* verifico en que cabina se encuentra el motorman
* @param mensaje
*/
void SicasMac_Controller::changeStateCabin(int stateCabin){
    m_coche_maquina=stateCabin;
    m_sicasmac->cambiarEstadoCabina(stateCabin);
    if(cargoAcople){
        sacoMensajeAcople();
        cargarMensajeAcople();
    }
}

/**
* @brief SicasMac_Controller::logicaPuertasSicas
* carga el renglon del mensaje donde se verifica el estado de los coches
* @param mensaje
*/

QString SicasMac_Controller::specificMsjWagon(QString wagon){
QString rowMsjWagon;
int numberWagon;
    for (int var = 0; var < cantCochesTotal; var++){
        numberWagon=var+1;
        if (wagon.toInt()==numberWagon){
            rowMsjWagon.append(wagon);
            rowMsjWagon.append(",I ");
        }
        else{
            rowMsjWagon.append("-,F ");
        }
     }
    rowMsjWagon.append(";");
    qDebug()<<"mensaje  "<< rowMsjWagon;
  return rowMsjWagon;
}
/**
* @brief SicasMac_Controller::logicaPuertasSicas
* genero el mensaje cuando se actualiza un grifo o una termica
* @param mensaje
*/

void SicasMac_Controller::updateSwitchMsj(QString msjSwitch){
    QStringList  msjData = msjSwitch.split(";");
    QString wagon = msjData[0];
    QString namePanel= msjData[1];
    QString nroThermal= msjData[2];
    QString state= msjData[3];
    QString msnComplet;

    msnComplet.append(namePanel);
    msnComplet.append(" ");
    msnComplet.append(nroThermal);
    if(state=="des"){
        msnComplet.append(";");
        msnComplet.append(specificMsjWagon(wagon));
        msnComplet.append("A;");
        msnComplet.append(state);
        verificoEstFalla("int", wagon.toInt());
        separoMensajes(msnComplet);
        estAnteriorFallaCocheSicas[wagon.toInt()]="int";
    }
    else if (state =="con"){
        bajaMensaje(msnComplet);
        verificoEstFalla("norm", wagon.toInt());
        estAnteriorFallaCocheSicas[wagon.toInt()]="norm";
    }
    refrescoVista();
}

//***************************MENSAJES SICAS PUESTA SERVICIO ********************************************

void SicasMac_Controller::cargarMensajeAcople(){
    cargoAcople=true;
    if (m_coche_maquina==1){
        separoMensajes("Conmutador Acop/Manio;1,F -,F -,F -,F -,F -,F;A;alta");
    }
    else if (m_coche_maquina==6){
        separoMensajes("Conmutador Acop/Manio;-,F -,F -,F -,F -,F 6,F;A;alta");
    }
    refrescoVista();
}

void SicasMac_Controller::sacoMensajeAcople(){
    cargoAcople=false;
    bajaMensaje("Conmutador Acop/Manio");
}

void SicasMac_Controller::cargarMensajeCompDesconectado(){
    separoMensajes("Comp. Desconectado;1,F 2,F 3,F 4,F 5,F 6,F;C;alta");
    refrescoVista();
}

void SicasMac_Controller::sacoMensajeCompDesconectado(){
    bajaMensaje("Comp. Desconectado");
}

void SicasMac_Controller::cargarMensajeConvFueraServicio(){
    separoMensajes("Conv. Fuera Servicio;1,F 2,F 3,F 4,F 5,F 6,F;A;alta");
    refrescoVista();
}

void SicasMac_Controller::sacoMensajeConvFueraServicio(){
    bajaMensaje("Conv. Fuera Servicio");
}

void SicasMac_Controller::cargarMensajeFrenoEstacAplicado(){
    separoMensajes("Freno Estac. Aplicado;1,F 2,F 3,F 4,F 5,F 6,F;C;alta");
    refrescoVista();
}

void SicasMac_Controller::sacoMensajeFrenoEstacAplicado(){
    bajaMensaje("Freno Estac. Aplicado");
}

void SicasMac_Controller::cargarMensajeDisyuntor(){
    separoMensajes("Disyuntor Desconectado;1,F 2,F 3,F 4,F 5,F 6,F;C;alta");
    refrescoVista();
}

void SicasMac_Controller::sacoMensajeDisyuntor(){
    bajaMensaje("Disyuntor Desconectado");
}
