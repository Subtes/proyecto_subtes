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

    m_horn = false;
    m_emergencyOverride = false;
    m_seta = false;
    m_rana = "0";

    //initENet();

//    m_pixMapSplash = QPixmap(":/subtewidgets/resources/splash.jpg");
//    this->m_splash = new QSplashScreen(m_pixMapSplash);
//    this->m_splash->setWindowFlags(Qt::WindowStaysOnTopHint);

    //connect(this,SIGNAL(controlReady()),this,SLOT(loadFinish()));
}

SubteStatus::~SubteStatus()
{
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
void SubteStatus::updateSpeed(double value){
    m_speed = value;
    emit speedChanged(m_speed);
}

void SubteStatus::updateTargetSpeed(double value){
    //m_atp->setTargetSpeed(value);
    emit targetSpeedChanged(value);
}

void SubteStatus::updateAllowedSpeed(double value){
    //m_atp->setAllowedSpeed(value);
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

void SubteStatus::emergencyBrakeActived(){
    m_brake->setEmergencyBrake(true);
    m_eventHandler->notifyValueChanged("c_freno_emergencia","con");
    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));
    qDebug() << "c_traccion: "<< m_traction->getTraction();
    qDebug() << "c_freno_emergencia: con";
    emit setaFired();
}

void SubteStatus::emergencyBrakeReleased(){
    m_brake->setEmergencyBrake(false);
    m_eventHandler->notifyValueChanged("c_freno_emergencia","des");
    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));
    qDebug() << "c_traccion: "<< m_traction->getTraction();
    qDebug() << "c_freno_emergencia: des";
}

void SubteStatus::hombreVivoPressed(){
    if(m_speed == 0){
        m_traction->setHombreVivo(true);
        m_eventHandler->notifyValueChanged("c_dispositivo_hombre_muerto","con");
        qDebug() << "c_dispositivo_hombre_muerto: pressed";
    }
}

void SubteStatus::hombreVivoReleased(){
    m_traction->setHombreVivo(false);
    m_eventHandler->notifyValueChanged("c_dispositivo_hombre_muerto","des");
    qDebug() << "c_dispositivo_hombre_muerto: released";

    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));
    qDebug() << "c_traccion: "<< m_traction->getTraction();

    if(m_speed > 0){
        m_brake->setEmergencyBrake(true);
        m_eventHandler->notifyValueChanged("c_freno_emergencia","con");
    }
}

void SubteStatus::CSCPBypassed()
{
    m_cscp->setBypass(true);
    qDebug() << "CSCP bypassed";
}

void SubteStatus::CSCPActivated()
{
    m_cscp->setBypass(false);
    qDebug() << "CSCP actived";
}

void SubteStatus::openLeftDoors()
{
    m_cscp->openLeftDoors();
}

void SubteStatus::openRightDoors()
{
    m_cscp->openRightDoors();
}

void SubteStatus::closeLeftDoors()
{
    m_cscp->closeLeftDoors();
}

void SubteStatus::closeRightDoors()
{
    m_cscp->closeRightDoors();
}

void SubteStatus::pressedCON(){
    qDebug() << "---> Pressed, CON Disyuntor";
    /*
    Para poder conectar los disyuntores, es necesario:
    Tensión normal de Batería
    Tensión suficiente en el Hilo de Trabajo
    Rana en AD o AT, con mando en su cabina
    Regulador de Mando en posición “0”
    Pulsar “CON”
    */
}

void SubteStatus::pressedDES(){
    qDebug() << "---> Pressed, DES Disyuntor";
    /* Para desconectar los disyuntores, solo se pulsa “DES”, en cualquiera de las cabinas de conducción. */
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
    m_brake->setEmergencyBrake(true);
    m_seta = true;
    m_eventHandler->notifyValueChanged("c_freno_emergencia","con");
    m_eventHandler->notifyValueChanged("c_seta_emergencia","con");
    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));

    qDebug() << "c_freno_emergencia: con";
    qDebug() << "c_seta_emergencia: con";
    qDebug() << "c_traccion: " << m_traction->getTraction();
}

void SubteStatus::setaDeactivated(){
    m_brake->setEmergencyBrake(false);
    m_seta = false;
    m_eventHandler->notifyValueChanged("c_freno_emergencia","des");
    m_eventHandler->notifyValueChanged("c_seta_emergencia","des");
    m_eventHandler->notifyValueChanged("c_traccion",std::to_string(m_traction->getTraction()));

    qDebug() << "c_freno_emergencia: des";
    qDebug() << "c_seta_emergencia: des";
    qDebug() << "c_traccion: " << m_traction->getTraction();
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

void SubteStatus::loadFinish(){
    this->m_splash->setHidden(true);
}

void SubteStatus::loadStart(){
    this->m_splash->showMaximized();
}

void SubteStatus::cutTraction(){
    qDebug() << "SubteStatus::cutTraction()";
    m_ATP_model->cutTraction();
}

void SubteStatus::enableTraction(){
    qDebug() << "SubteStatus::enableTraction()";
    m_ATP_model->enableTraction();
}
