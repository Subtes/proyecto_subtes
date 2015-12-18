#include "subtestatus.h"
SubteStatus::SubteStatus() : SubteStateBase(){
    m_effort = 0;

    m_horn = false;
    m_emergencyOverride = false;
    m_seta = false;
    m_keyATP = false;
    m_rana = "0";
    m_drivingMode = 0;
    m_modeOperation = 0;

    //AUXILIARY PANELS
    m_switch.append("DEFAULT-COCHE;DEFAULT-PANEL;DEFAULT-THERMAL;DEFAULT-STATE");
}

SubteStatus::~SubteStatus(){
    delete m_cscp;
    delete m_brake;
    delete m_atp;
    delete m_traction;
}

void SubteStatus::reset(){
    SubteStateBase::reset();
    m_rana = "0";
    m_seta = false;
    m_keyATP = false;

    //AUXILIARY PANELS
    m_switch.append("DEFAULT-COCHE;DEFAULT-PANEL;DEFAULT-THERMAL;DEFAULT-STATE");
}

double SubteStatus::targetSpeed() const{
    return m_atp->targetSpeed();
}

double SubteStatus::allowedSpeed() const{
    return m_atp->allowedSpeed();
}

bool SubteStatus::horn() const{
    return m_horn;
}

bool SubteStatus::emergencyOverride() const{
    return m_emergencyOverride;
}

bool SubteStatus::seta() const{
    return m_seta;
}

bool SubteStatus::keyTopBoard() const{
    return m_keyATP;
}

std::string SubteStatus::rana() const{
    return m_rana;
}

// SLOTS ///////////////////
/**
 * @brief SubteStatus::updateSpeed:
 *  +   en caso de volver a velocidad 0 reactiva la evaluacion del sistema de cierre
 *      de puertas.
 *  +   si la velocidad supera los 4km/h, cierra las puertas
 *  +   si la velocidad vuelve a cero, quita el freno por ATP
 * @param value: nueva velocidad
 */
bool SubteStatus::updateSpeed(double value){
    if(SubteStateBase::updateSpeed(value)){

        if( m_speed <= 0 && m_cscp->getBypass()){
            m_cscp->setBypass(false);
            emit DoorsChanged(m_cscp->evalCircuit());
        }

        if( m_speed <= 0 && m_brake->getEmergencyBrake()){
            m_brake->setEmergencyBrake_atp(false);
        }

        if((m_speed>4) && (m_cscp->leftDoors() || m_cscp->rightDoors())){
            m_cscp->notifyActionLeftDoors(Doors::CLOSE);
            m_cscp->notifyActionRightDoors(Doors::CLOSE);
        }
    }
}

void SubteStatus::updateTargetSpeed(double value){
    m_atp->setTargetSpeed(value);
    emit targetSpeedChanged(value);
}

void SubteStatus::updateAllowedSpeed(double value){
    m_atp->setAllowedSpeed(value);
    emit allowedSpeedChanged(value);
}

void SubteStatus::wiperOn(){
    m_eventHandler->notifyValueChanged("c_limpiaParabrisas","on");
}

void SubteStatus::wiperOff(){
    m_eventHandler->notifyValueChanged("c_limpiaParabrisas","off");
}

void SubteStatus::washer(){
    m_eventHandler->notifyValueChanged("c_lavaParabrisas","on");
}

/**
 * @brief SubteStatus::disyuntoresCON: Para poder conectar los disyuntores, es necesario:
    Tensión normal de Batería
    Tensión suficiente en el Hilo de Trabajo
    Rana en AD o AT, con mando en su cabina
    Regulador de Mando en posición “0”
    Pulsar “CON”
 */
void SubteStatus::disyuntoresCon(){
    m_eventHandler->notifyValueChanged("c_disyuntor","con");
    emit senalDisyuntorCon();
    qDebug() << "Pressed CON Disyuntor";
}

/**
 * @brief SubteStatus::disyuntoresDes:  Para desconectar los disyuntores, solo se pulsa “DES”, en cualquiera de las cabinas de conducción.
 */
void SubteStatus::disyuntoresDes(){
    m_eventHandler->notifyValueChanged("c_disyuntor","des");
    emit senalDisyuntorDes();
    qDebug() << "Pressed DES Disyuntor";
    }

void SubteStatus::hornOn(){
    qDebug() << "c_bocina: on";
    m_eventHandler->notifyValueChanged("c_bocina","on");
    m_horn = true;
}

void SubteStatus::hornOff(){
    qDebug() << "c_bocina: off";
    m_eventHandler->notifyValueChanged("c_bocina","Off");
    m_horn = false;
}

void SubteStatus::emergencyOverridePressed(){
    m_emergencyOverride = !m_emergencyOverride;
    if(m_emergencyOverride){
        qDebug() << "c_emergencyOverride: con";
        m_eventHandler->notifyValueChanged("c_emergencyOverride","con");
    }else{
        qDebug() << "c_emergencyOverride: des";
        m_eventHandler->notifyValueChanged("c_emergencyOverride","des");
    }
}

void SubteStatus::keyActivated(){
    m_keyATP = true;
    m_eventHandler->notifyValueChanged("c_llave_atp","con");
    emit atpOn();
    qDebug() << "keyATP Model: " << m_keyATP;
}

void SubteStatus::keyDeactivated(){
    m_keyATP = false;
    m_eventHandler->notifyValueChanged("c_llave_atp","des");
    emit atpOff();
    qDebug() << "keyATP Model: " << m_keyATP;
}

void SubteStatus::ranaAD(){
    m_rana = "ad";
    m_traction->setDirection(Traction::TRACTION_MODE::ADELANTE);
    m_eventHandler->notifyValueChanged("c_rana","ad");
    qDebug() << "c_rana: AD";
}

void SubteStatus::ranaCERO(){
    m_rana = "0";
    m_traction->setDirection(Traction::TRACTION_MODE::NEUTRO);
    m_eventHandler->notifyValueChanged("c_rana","0");
    m_traction->notifyTraction();
    qDebug() << "c_rana: 0";
    qDebug() << "c_traccion: " << m_traction->getTraction();
}

void SubteStatus::ranaAT(){
    m_rana = "at";
    m_traction->setDirection(Traction::TRACTION_MODE::REVERSA);
    m_eventHandler->notifyValueChanged("c_rana","at");
    qDebug() << "c_rana: AT";
}

void SubteStatus::setBatteryConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_pulsador_bateria","con");
        emit bateriaCon();
        qDebug() << "c_pulsador_bateria: con";
    }else{
        m_eventHandler->notifyValueChanged("c_pulsador_bateria","des");
        emit bateriaDes();
        qDebug() << "c_pulsador_bateria: des";
    }
}

void SubteStatus::setConmutadorPuestaServicio(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio","automatica");
        emit conmutadorServicioAutomatic();
        qDebug() << "c_conmutador_puesta_en_servicio: automatica";
    }else{
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio","manual");
        emit conmutadorServicioManual();
        qDebug() << "c_conmutador_puesta_en_servicio :manual";
    }
}

void SubteStatus::setConmutadorPuestaServicioAutomatica(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio_automatica","con");
        qDebug() << "c_conmutador_puesta_en_servicio_automatica :con";
    }else{
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio_automatica","des");
        qDebug() << "c_conmutador_puesta_en_servicio_automatica: des";
    }
}

void SubteStatus::setPantographConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_pantografo","con");
        emit pantografoCon();
        qDebug() << "c_conmutador_pantografo :con";
    }else{
        m_eventHandler->notifyValueChanged("c_pantografo","des");
        emit pantografoDes();
        qDebug() << "c_conmutador_pantografo: des";
    }
}

void SubteStatus::setCompressorAuxConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_compresorAux","con");
        emit compresorAuxCon();
        qDebug() << "c_compresorAux :con";
    }else{
        m_eventHandler->notifyValueChanged("c_compresorAux","des");
        emit compresorAuxDes();
        qDebug() << "c_compresorAux: des";
    }
}

void SubteStatus::setConverterConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_convertidor","con");
        emit convertidorCon();
        qDebug() << "c_convertidor :con";
    }else{
        m_eventHandler->notifyValueChanged("c_convertidor","des");
        emit convertidorDes();
        qDebug() << "c_convertidor: des";
    }
}

void SubteStatus::setMainCompressorConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_compresorPpal","con");
        emit compresorPpalCon();
        qDebug() << "c_compresorPpal :con";
    }else{
        m_eventHandler->notifyValueChanged("c_compresorPpal","des");
        emit compresorPpalDes();
        qDebug() << "c_compresorPpal: des";
    }
}

void SubteStatus::setLightingConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_alumbrado","con");
        emit alumbradoCon();
        qDebug() << "c_alumbrado :con";
    }else{
        m_eventHandler->notifyValueChanged("c_alumbrado","des");
        emit alumbradoDes();
        qDebug() << "c_alumbrado: des";
    }
}

void SubteStatus::setAirConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_aireAcondicionado","con");
        emit aireAcondicionadoCon();
        qDebug() << "c_aireAcondicionado :con";
    }else{
        m_eventHandler->notifyValueChanged("c_aireAcondicionado","des");
        emit aireAcondicionadoDes();
        qDebug() << "c_aireAcondicionado: des";
    }
}

void SubteStatus::setMegaphoneConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_megafonia","con");
        emit megafoniaCon();
        qDebug() << "c_megafonia :con";
    }else{
        m_eventHandler->notifyValueChanged("c_megafonia","des");
        emit megafoniaDes();
        qDebug() << "c_megafonia: des";
    }
}

void SubteStatus::setParkingBrakeConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_freno_estacionamiento","con");
        qDebug() << "c_freno_estacionamiento: con";
        m_cscp->setParkingBrake(true);
        emit DoorsChanged(m_cscp->evalCircuit());
        emit frenoEstacionamientoCon();
    }else{
        m_eventHandler->notifyValueChanged("c_freno_estacionamiento","des");
        qDebug() << "c_freno_estacionamiento: des";
        m_cscp->setParkingBrake(false);
        emit DoorsChanged(m_cscp->evalCircuit());
        emit frenoEstacionamientoDes();
    }
}

void SubteStatus::updateEffort(double value){
    m_effort = value;
    emit effortChanged(m_effort);
}

void SubteStatus::updatestatecabine(int state_cabine)
{
    m_estado_coche = state_cabine;
    emit cabinChanged(m_estado_coche);
}

void SubteStatus::bypassBrake(bool status){
    m_brake->setBypass(status);
    if(status){
        m_eventHandler->notifyValueChanged("c_bypass_freno","con");
        qDebug() << "Brake bypassed";
    } else {
        m_eventHandler->notifyValueChanged("c_bypass_freno","des");
        qDebug() << "Brake reactivated";
    }
    emit hiloLazoChanged(getHiloLazo());
    m_traction->notifyTraction();
    m_brake->notifyEmergencyBrake();
}

void SubteStatus::bypassCSCP(bool status){
    if(status){
        m_cscp->setBypass(true);
        m_eventHandler->notifyValueChanged("c_bypass_traccion","con");
        qDebug() << "CSCP bypassed";
    } else {
        if(m_speed <= 0) {
            m_cscp->setBypass(false);
            qDebug() << "CSCP re-actived";
        }
        m_eventHandler->notifyValueChanged("c_bypass_traccion","des");
    }
    m_traction->notifyTraction();
    emit DoorsChanged(m_cscp->evalCircuit());
    qDebug() << "DoorsChanged " + m_cscp->evalCircuit();
}

void SubteStatus::updateLeftDoorsButtons(bool state) {
    m_cscp->notifyActionLeftDoors(state);
}

void SubteStatus::updateRightDoorsButtons(bool state) {
    m_cscp->notifyActionRightDoors(state);
}

void SubteStatus::setDrivingModeATP(int status){
    m_drivingMode = status;
    emit modeDrivingChanged(m_drivingMode);
}

int SubteStatus::getDrivingModeATP(){
    return m_drivingMode;
}

void SubteStatus::setTractionFailure(){
    m_traction->setAveria(true);
    m_traction->notifyTraction();
}

void SubteStatus::setBrakeFailure(){
    m_brake->setAveria(true);
    m_brake->notifyEmergencyBrake();
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStatus::setCSCPFailure(){
    m_cscp->setAveria(true);
    emit DoorsChanged(m_cscp->evalCircuit());
}

void SubteStatus::resolveTractionFailure(){
    m_traction->setAveria(false);
    m_traction->notifyTraction();
}

void SubteStatus::resolveBrakeFailure(){
    m_brake->setAveria(false);
    m_brake->notifyEmergencyBrake();
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStatus::resolveCSCPFailure(){
    m_cscp->setAveria(false);
    emit DoorsChanged(m_cscp->evalCircuit());
}

void SubteStatus::setManiobraMode(){
    m_eventHandler->notifyValueChanged("c_modo_conduccion","maniobra");
    emit estadoManioAcople();
}

void SubteStatus::setAtpMode(){
    m_eventHandler->notifyValueChanged("c_modo_conduccion","atp");
    emit estadoNormal();
}

void SubteStatus::setAcopleMode(){
    m_eventHandler->notifyValueChanged("c_modo_conduccion","acople");
    emit estadoManioAcople();
}

void SubteStatus::setSicasOk(){
    m_eventHandler->notifyValueChanged("c_estado_sicas","ok");
    qDebug() << "c_estado_sicas: ok";
}

void SubteStatus::setModeOperation(int m){
    m_modeOperation = m;
    emit modeOperation(m);
}

void SubteStatus::setSwitch(QString s){
    m_switch = s;
    emit changeSwitch(s);
}
