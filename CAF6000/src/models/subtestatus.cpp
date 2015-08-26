#include "subtestatus.h"

//TODO:: cambiar los notifyValueChanged por signal/slot
//el modelo emite señales y el event handler los intercepta y conecta
#include <QThread>
#include <QSplashScreen>
#include <QPixmap>

SubteStatus::SubteStatus()
{
    m_cscp = new CSCP();
    m_brake = new Brake();
    m_ATP_model = new ATP_model();
    m_traction = new Traction(m_brake,m_cscp, m_ATP_model);

    m_speed = 0;
    m_effort = 0;
    m_volts = 0;
    m_amps = 0;

    //Manometer
    m_pressure_red=0;
    m_pressure_white = 0;

    m_horn = false;
    m_emergencyOverride = false;
    m_seta = false;
    m_rana = "0";
    m_CMC = true;
}

SubteStatus::~SubteStatus()
{
    delete m_cscp;
    delete m_brake;
    delete m_ATP_model;
    delete m_traction;
}

void SubteStatus::setHandler(EventHandler *eventHandler)
{
    m_eventHandler = eventHandler;
}

void SubteStatus::reset()
{
    //STATUS
    m_cscp->reset();
    m_brake->reset();
    m_ATP_model->reset();
    m_traction->reset();
    m_speed = 0;

    //CONTROLS
    m_rana = "0";
    m_seta = false;
}

bool SubteStatus::cscp() const
{
    return m_cscp->evalCircuit();
}

bool SubteStatus::leftDoors() const
{
    return m_cscp->leftDoors();
}

bool SubteStatus::rightDoors() const
{
    return m_cscp->rightDoors();
}

double SubteStatus::speed() const
{
    return m_speed;
}

double SubteStatus::targetSpeed() const
{
    return m_ATP_model->targetSpeed();
}

double SubteStatus::allowedSpeed() const
{
    return m_ATP_model->allowedSpeed();
}

int SubteStatus::traction() const
{
    return m_traction->getTraction();
}

int SubteStatus::brake() const
{
    return m_brake->getBrake();
}

bool SubteStatus::emergencyBrake() const
{
    return m_brake->getEmergencyBrake();
}

/**
 * @brief SubteStatus::getHiloLazo
 * @return true si se cumple, o false si esta el freno de emergencia activado o existe alguna averia.
 */
bool SubteStatus::getHiloLazo()
{
    return !m_brake->getEmergencyBrake(); // || averia!
}

bool SubteStatus::horn() const
{
    return m_horn;
}

bool SubteStatus::emergencyOverride() const
{
    return m_emergencyOverride;
}

bool SubteStatus::seta() const
{
    return m_seta;
}

std::string SubteStatus::rana() const
{
    return m_rana;
}

int SubteStatus::tractionLeverPosition() const
{
    return m_traction->position();
}

// SLOTS ///////////////////
/**
 * @brief SubteStatus::updateSpeed: checkea que haya un cambio de velocidad, si hay,
 * actualiza el valor en el modelo y en caso de volver a velocidad 0 reactiva la
 * evaluacion del sistema de cierre de puertas.
 * @param value: nueva velocidad
 */
void SubteStatus::updateSpeed(double value){
    if(m_speed != value){
        m_speed = value;
        emit speedChanged(m_speed);
        if( m_speed <= 0 && m_cscp->getBypass()){
            m_cscp->setBypass(false);
            emit CSCPChanged(m_cscp->evalCircuit());
        }
    }
}

void SubteStatus::updateTargetSpeed(double value){
    m_ATP_model->setTargetSpeed(value);
    emit targetSpeedChanged(value);
}

void SubteStatus::updateAllowedSpeed(double value){
    m_ATP_model->setAllowedSpeed(value);
    emit allowedSpeedChanged(value);
}

void SubteStatus::wiperOn()
{
    qDebug() << "c_limpiaParabrisas: on";
    m_eventHandler->notifyValueChanged("c_limpiaParabrisas","on");
}

void SubteStatus::wiperOff()
{
    qDebug() << "c_limpiaParabrisas: off";
    m_eventHandler->notifyValueChanged("c_limpiaParabrisas","off");
}

void SubteStatus::washer()
{
    qDebug() << "c_lavaParabrisas: on";
    m_eventHandler->notifyValueChanged("c_lavaParabrisas","on");
}

/**
 * @brief SubteStatus::tractionReceived: Cambia la posicion de la palanca de traccion
 * desde el widget o harware, y se conecta a este slot. El subsistema de traccion decide
 * si hay traccion o no. en caso de que la diferencia entre la ultima traccion emitida y
 * la nueva sea mayor a 5, se notifica el cambio en blackboard.
 * @param value: posicion de la palanca
 */
void SubteStatus::tractionReceived(int value){
    double tractionToEmit = m_traction->updateTraction(value);
    qDebug() << "c_traccion: "<< tractionToEmit;
    if((value<10) || (abs(tractionToEmit - m_traction->lastTraction()) >= 5)){
        m_eventHandler->notifyValueChanged("c_traccion",std::to_string(tractionToEmit));
        qDebug() << "c_traccion: "<< tractionToEmit;
        m_traction->setLastTraction(tractionToEmit);
    }
}

void SubteStatus::brakeReceived(int value){
    m_brake->setBrake(value);
    m_traction->updateTraction();
    if((value<10) || (abs(value - m_brake->lastBrake()) >= 5)){
        m_eventHandler->notifyValueChanged("c_freno",std::to_string(value));
        qDebug() << "c_freno: "<< value;
        m_brake->setLastBrake(value);
    }
}

/**
 * @brief SubteStatus::emergencyBrakeActived: se corta el hilo de lazo
 */
void SubteStatus::emergencyBrakeActived(){
    m_brake->setEmergencyBrake(true);
    m_eventHandler->notifyValueChanged("c_freno_emergencia","con");
    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));
    qDebug() << "c_traccion: "<< m_traction->getTraction();
    qDebug() << "c_freno_emergencia: con";
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStatus::emergencyBrakeReleased(){
    m_brake->setEmergencyBrake(false);
    m_eventHandler->notifyValueChanged("c_freno_emergencia","des");
    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));
    qDebug() << "c_traccion: "<< m_traction->getTraction();
    qDebug() << "c_freno_emergencia: des";
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStatus::hombreVivoPressed(){
    if(m_speed == 0){
        m_traction->setHombreVivo(true);
        m_eventHandler->notifyValueChanged("c_hombreVivo","con");
        qDebug() << "c_hombreVivo: pressed";
    }
}

void SubteStatus::hombreVivoReleased(){
    m_traction->setHombreVivo(false);
    m_eventHandler->notifyValueChanged("c_hombreVivo","des");
    qDebug() << "c_hombreVivo: released";

    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));
    qDebug() << "c_traccion: "<< m_traction->getTraction();

    if(m_speed > 0){
        m_brake->setEmergencyBrake(true);
        m_eventHandler->notifyValueChanged("c_freno_emergencia","con");
    }
}

/**
 * @brief SubteStatus::pressedCON: Para poder conectar los disyuntores, es necesario:
    Tensión normal de Batería
    Tensión suficiente en el Hilo de Trabajo
    Rana en AD o AT, con mando en su cabina
    Regulador de Mando en posición “0”
    Pulsar “CON”
 */
void SubteStatus::pressedCON(){
    qDebug() << "Pressed CON Disyuntor";
}

/**
 * @brief SubteStatus::pressedDES: /* Para desconectar los disyuntores, solo se pulsa “DES”, en cualquiera de las cabinas de conducción.
 */
void SubteStatus::pressedDES(){
    qDebug() << "Pressed DES Disyuntor";
    }

void SubteStatus::hornOn()
{
    qDebug() << "c_bocina: on";
    m_eventHandler->notifyValueChanged("c_bocina","on");
    m_horn = true;
}

void SubteStatus::hornOff()
{
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

void SubteStatus::setaActivated(){
    emergencyBrakeActived();
    m_seta = true;
    m_eventHandler->notifyValueChanged("c_seta_emergencia","con");
    qDebug() << "c_seta_emergencia: con";
}

void SubteStatus::setaDeactivated(){
    emergencyBrakeReleased();
    m_seta = false;
    m_eventHandler->notifyValueChanged("c_seta_emergencia","des");
    qDebug() << "c_seta_emergencia: des";
}

void SubteStatus::ranaAD(){
    m_rana = "ad";
    m_traction->setDirection(Traction::RANA::AD);
    m_eventHandler->notifyValueChanged("c_rana","ad");
    qDebug() << "c_rana: AD";
}

void SubteStatus::ranaCERO(){
    m_rana = "0";
    m_traction->setDirection(Traction::RANA::CERO);
    m_eventHandler->notifyValueChanged("c_rana","0");
    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));
    qDebug() << "c_rana: 0";
    qDebug() << "c_traccion: " << m_traction->getTraction();
}

void SubteStatus::ranaAT(){
    m_rana = "at";
    m_traction->setDirection(Traction::RANA::AT);
    m_eventHandler->notifyValueChanged("c_rana","at");
    qDebug() << "c_rana: AT";
}

void SubteStatus::tractionLeverChanged(int value){
    m_traction->setPosition(value);
    if((value<10) || (abs(value - m_traction->lastPosition())>=5)){
        m_eventHandler->notifyValueChanged("c_regulador_de_mando",std::to_string(value));
        m_traction->setLastPosition(value);
    }
}

void SubteStatus::cutTraction(){
    qDebug() << "SubteStatus::cutTraction()";
    m_ATP_model->cutTraction();
}

void SubteStatus::enableTraction(){
    qDebug() << "SubteStatus::enableTraction()";
    m_ATP_model->enableTraction();
}

void SubteStatus::setBatteryConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_pulsador_bateria","con");
        qDebug() << "c_pulsador_bateria: con";
    }else{
        m_eventHandler->notifyValueChanged("c_pulsador_bateria","des");
        qDebug() << "c_pulsador_bateria: des";
    }
}
void SubteStatus::setConmutadorPuestaServicio(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio","automatica");
        qDebug() << "c_conmutador_puesta_en_servicio: automatica";
    }else{
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio","manual");
        qDebug() << "c_conmutador_puesta_en_servicio :manual";
    }
}

void SubteStatus::setConmutadorPuestaServicioAutomatica(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_estado_sicas","ok");
        qDebug() << "c_estado_sicas: ok";
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio_automatica","con");
        qDebug() << "c_conmutador_puesta_en_servicio_automatica :con";
        m_eventHandler->notifyValueChanged("c_disyuntor","con");
        qDebug() << "c_disyuntor: con";
    }else{
        m_eventHandler->notifyValueChanged("c_conmutador_puesta_en_servicio_automatica","des");
        qDebug() << "c_conmutador_puesta_en_servicio_automatica: des";
    }
}

void SubteStatus::setPantographConnector(bool status){}
void SubteStatus::setCompressorAuxConnector(bool status){}
void SubteStatus::setConverterConnector(bool status){}
void SubteStatus::setMainCompressorConnector(bool status){}
void SubteStatus::setLightingConnector(bool status){}
void SubteStatus::setAirConnector(bool status){}
void SubteStatus::setMegaphoneConnector(bool status){}
void SubteStatus::setRetentionBrakeConnector(bool status){
    if (status){
        m_eventHandler->notifyValueChanged("c_freno_estacionamiento","con");
        qDebug() << "c_freno_estacionamiento: con";
    }else{
        m_eventHandler->notifyValueChanged("c_freno_estacionamiento","des");
        qDebug() << "c_freno_estacionamiento: des";
    }
}

void SubteStatus::updateEffort(double value)
{
    m_effort = value;
    emit effortChanged(m_effort);
}

void SubteStatus::updateVolt(double value)
{
    m_volts = value;
    emit voltChanged(m_volts);
}

void SubteStatus::updateAmm(double value)
{
    m_amps = value;
    emit ampsChanged(m_amps);
}

void SubteStatus::bypassBrake(bool status)
{
    m_brake->setBypass(status);
    emit tractionChanged(m_traction->getTraction());
}

void SubteStatus::bypassCSCP(bool status)
{
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

    emit tractionChanged(m_traction->getTraction());
    emit CSCPChanged(m_cscp->evalCircuit());
    qDebug() << "CSCPChanged " + m_cscp->evalCircuit();
}

void SubteStatus::openLeftDoors()
{
    m_cscp->openLeftDoors();
    emit CSCPChanged(m_cscp->evalCircuit());
    qDebug() << "CSCPChanged " + m_cscp->evalCircuit();
}

void SubteStatus::openRightDoors()
{
    m_cscp->openRightDoors();
    emit CSCPChanged(m_cscp->evalCircuit());
    qDebug() << "CSCPChanged " + m_cscp->evalCircuit();
}

void SubteStatus::closeLeftDoors()
{
    m_cscp->closeLeftDoors();
    emit CSCPChanged(m_cscp->evalCircuit());
    qDebug() << "CSCPChanged " + m_cscp->evalCircuit();
}

void SubteStatus::closeRightDoors()
{
    m_cscp->closeRightDoors();
    emit CSCPChanged(m_cscp->evalCircuit());
    qDebug() << "CSCPChanged " + m_cscp->evalCircuit();
}
void SubteStatus::updatePreassureRed(double value)
{
    m_pressure_red = value;
    emit manometerRedChange(m_pressure_red);
}
void SubteStatus::updatePreassureWhite(double value)
{
    m_pressure_white = value;
    emit manometerWhiteChange(m_pressure_white);
}

double SubteStatus::getPressureRed() const
{
    return m_pressure_red;
}

double SubteStatus::getPressureWhite() const
{
    return m_pressure_white;

void SubteStatus::setDrivingModeATP(bool status){
    m_CMC = status;
}

bool SubteStatus::getDrivingModeATP(){
    return m_CMC;

}
