#include "subtestatebase.h"

SubteStateBase::SubteStateBase(){
    m_cscp = new Doors();
    m_brake = new Brakes();
    m_atp = new AutomaticTrainProtection();
    m_traction = new Traction();

    m_brake->linkTraction(m_traction);
    m_traction->linkBrake(m_brake);
    m_traction->linkCSCP(m_cscp);
    m_traction->linkATP(m_atp);

    m_speed = 0;
    m_cylinder_pressure=0;
    m_main_pressure = 0;
    m_volts = 0;
    m_amps = 0;
}

SubteStateBase::~SubteStateBase(){
}

void SubteStateBase::reset(){
    m_cscp->reset();
    m_brake->reset();
    m_atp->reset();
    m_traction->reset();
    m_speed = 0;
}

void SubteStateBase::setHandler(Base_EventHandler *eventHandler){
    m_eventHandler = eventHandler;
    m_brake->setHandler(eventHandler);
    m_traction->setHandler(eventHandler);
    m_cscp->setHandler(eventHandler);
}

double SubteStateBase::speed() const
{
    return m_speed;
}

double SubteStateBase::getCylinderPressure() const{
    return m_cylinder_pressure;
}

double SubteStateBase::getMainPressure() const{
    return m_main_pressure;
}

/**
 * @brief SubteStatus::getHiloLazo
 * @return true si se cumple, o false si esta el freno de emergencia activado o existe alguna averia.
 */
bool SubteStateBase::getHiloLazo()
{
    return m_brake->getHiloLazo();
}

int SubteStateBase::traction() const
{
    return m_traction->getTraction();
}

int SubteStateBase::brake() const
{
    return m_brake->getBrake();
}

bool SubteStateBase::emergencyBrake() const
{
    return m_brake->getEmergencyBrake();
}

bool SubteStateBase::doorsCircuit() const
{
    return m_cscp->evalCircuit();
}

bool SubteStateBase::leftDoors() const
{
    return m_cscp->leftDoors();
}

bool SubteStateBase::rightDoors() const
{
    return m_cscp->rightDoors();
}

// SLOTS ///////////////////
/**
 * @brief Base updateSpeed: checkea que haya un cambio de velocidad, si hay,
 * actualiza el valor en el modelo.
 * @param value: nueva velocidad
 */
bool SubteStateBase::updateSpeed(double value){
    if(m_speed != value){
        m_speed = value;
        emit speedChanged(m_speed);
        return true;
    }
    return false;
}

void SubteStateBase::updateCylinderPreassure(double value){
    m_cylinder_pressure = value;
    emit cylinderPressureChange(m_cylinder_pressure);
}

void SubteStateBase::updateMainPreassure(double value){
    m_main_pressure = value;
    emit mainPressureChange(m_main_pressure);
}

/**
 * @brief SubteStatus::tractionReceived: Cambia la posicion de la palanca de traccion
 * desde el widget o harware, y se conecta a este slot. El subsistema de traccion decide
 * si hay traccion o no. en caso de que la diferencia entre la ultima traccion emitida y
 * la nueva sea mayor a 5, se notifica el cambio en blackboard.
 * @param value: posicion de la palanca
 */
void SubteStateBase::tractionReceived(int value){
    m_traction->updateTraction(value);
}

void SubteStateBase::brakeReceived(int value){
    m_brake->setBrake(value);
}

/**
 * @brief SubteStatus::emergencyBrakeActived: se corta el hilo de lazo
 */
void SubteStateBase::ATP_emergencyBrakeActivated(){
    m_brake->setEmergencyBrake_atp(true);
    m_traction->notifyTraction();
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStateBase::ATP_emergencyBrakeReleased(){
    m_brake->setEmergencyBrake_atp(false);
    m_traction->notifyTraction();
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStateBase::hombreMuertoPressed(){
    m_traction->setHombreMuerto(true);
    m_traction->notifyTraction();
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStateBase::hombreMuertoReleased(){
    m_traction->setHombreMuerto(false);
    m_traction->notifyTraction();
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStateBase::openLeftDoors()
{
    m_cscp->openLeftDoors();
    emit DoorsChanged(m_cscp->evalCircuit());
    qDebug() << "DoorsChanged " + m_cscp->evalCircuit();
}

void SubteStateBase::openRightDoors()
{
    m_cscp->openRightDoors();
    emit DoorsChanged(m_cscp->evalCircuit());
    qDebug() << "DoorsChanged " + m_cscp->evalCircuit();
}

void SubteStateBase::closeLeftDoors()
{
    m_cscp->closeLeftDoors();
    emit DoorsChanged(m_cscp->evalCircuit());
    qDebug() << "DoorsChanged " + m_cscp->evalCircuit();
}

void SubteStateBase::closeRightDoors()
{
    m_cscp->closeRightDoors();
    emit DoorsChanged(m_cscp->evalCircuit());
    qDebug() << "DoorsChanged " + m_cscp->evalCircuit();
}

void SubteStateBase::setaActivated(){
    m_seta = true;
    m_brake->setEmergencyBrake_seta(true);
    m_traction->notifyTraction();
    m_eventHandler->notifyValueChanged("c_seta_emergencia","con");
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStateBase::setaDeactivated(){
    m_seta = false;
    m_brake->setEmergencyBrake_seta(false);
    m_traction->notifyTraction();
    m_eventHandler->notifyValueChanged("c_seta_emergencia","des");
    emit hiloLazoChanged(getHiloLazo());
}

void SubteStateBase::cutTraction(){
    qDebug() << "SubteStatus::cutTraction()";
    m_atp->cutTraction();
}

void SubteStateBase::enableTraction(){
    qDebug() << "SubteStatus::enableTraction()";
    m_atp->enableTraction();
}

void SubteStateBase::updateVolt(double value){
    m_volts = value;
    emit voltChanged(m_volts);
}

void SubteStateBase::updateAmm(double value){
    m_amps = value;
    emit ampsChanged(m_amps);
}

void SubteStateBase::setRetentionBrakeBypass(bool state)
{
    m_brake->setAnulacionFrenoRetencion(state);

    if(state){
        m_eventHandler->notifyValueChanged("c_anulacion_freno_retencion","con");
    }else{
        m_eventHandler->notifyValueChanged("c_anulacion_freno_retencion","des");
    }
}

void SubteStateBase::setRetentionBrake(bool state)
{
    m_brake->setRetentioBrake(state);
    qDebug() << "emitida la senial retencion: " << m_brake->retentioBrake();
    emit retentionBrakeChanged(m_brake->retentioBrake());
}
