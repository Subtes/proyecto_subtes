#include "subtestatus.h"

SubteStatus::SubteStatus()
{
    splashPassed = false;

    m_horn = false;
    m_emergencyOverride = false;
    m_leftDoors = CLOSE;
    m_rightDoors = CLOSE;
    m_CSCP = false;
    m_speed = 0;
    m_rana = "0";
    m_traction = 0;
    m_tractionLeverPosition = 0;
    m_seta = false;

    initENet();
}

void SubteStatus::initENet(){
    //=== eNet setup ===
    m_serverIp = "127.0.0.1";
    m_serverPort = 5000;
    m_controlsHostName = "P1_control";
    m_visualHostName = "P1_visualizador";
    m_instructionsHostName = "P1_instruccion";

    m_eNetClient = new ENetClient();

    using namespace std::placeholders;
    m_eNetClient->OnCambioValClave = std::bind(&SubteStatus::processValueChanged, this, _1, _2, _3);

    m_eNetClient->Conectar(m_serverIp, m_serverPort, m_controlsHostName);
    m_eNetClient->Suscribirse(m_instructionsHostName,"i_estado_simulador");
}

SubteStatus::~SubteStatus()
{
}

void SubteStatus::hornOn()
{
    qDebug() << "c_bocina: on";
    m_eNetClient->CambiarValorClave("c_bocina","on");
    m_horn = true;
}

void SubteStatus::hornOff()
{
    qDebug() << "c_bocina: off";
    m_eNetClient->CambiarValorClave("c_bocina","Off");
    m_horn = false;
}

void SubteStatus::wiperOn()
{
    qDebug() << "c_limpiaParabrisas: on";
    m_eNetClient->CambiarValorClave("c_limpiaParabrisas","on");
}

void SubteStatus::wiperOff()
{
    qDebug() << "c_limpiaParabrisas: off";
    m_eNetClient->CambiarValorClave("c_limpiaParabrisas","off");
}

void SubteStatus::washer()
{
    qDebug() << "c_lavaParabrisas: on";
    m_eNetClient->CambiarValorClave("c_lavaParabrisas","on");
}

void SubteStatus::tractionLeverInZero(){
    m_traction = 0;
    qDebug() << "c_movimiento: 0";
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}

void SubteStatus::tractionReceived(int value){
    if(((m_rana.compare("ad")==0)||(m_rana.compare("at")==0))&&(!m_seta)){
        m_traction = value;
        qDebug() << "RANA ACTIVA! c_movimiento: "<< m_traction;
        qDebug() << "RANA ACTIVA! value: "<< value;
        m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
    }
}

void SubteStatus::brakeReceived(int value){
}

void SubteStatus::emergencyBrakeActived(){
    qDebug() << "c_movimiento: "<< 0;
    m_traction = 0;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
    m_eNetClient->CambiarValorClave("c_freno_emergencia","con");
}

void SubteStatus::ranaAD(){
    m_rana = "ad";
    qDebug() << "c_rana: AD";
    m_eNetClient->CambiarValorClave("c_rana","ad");

    //TODO: refactor this hardcoded!!!
    qDebug() << "m_tractionLeverPosition: " << m_tractionLeverPosition;
    m_traction = static_cast<int>(((m_tractionLeverPosition-15)/85)*100);

    qDebug() << "c_movimiento: " << m_traction;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}

void SubteStatus::ranaCERO(){
    m_rana = "0";
    qDebug() << "c_rana: 0";
    m_eNetClient->CambiarValorClave("c_rana","0");

    m_traction = 0;
    qDebug() << "c_movimiento: " << m_traction;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}

void SubteStatus::ranaAT(){
    m_rana = "at";
    qDebug() << "c_rana: AT";
    m_eNetClient->CambiarValorClave("c_rana","at");

    //TODO: refactor this hardcoded!!!
    m_traction = static_cast<int>(((m_tractionLeverPosition-15)/85)*100);
    qDebug() << "c_movimiento: " << m_traction;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string((int)m_traction));
}

void SubteStatus::hombreVivoPressed(){
    qDebug() << "c_hombreVivo: pressed";
    m_eNetClient->CambiarValorClave("c_hombreVivo","pressed");
}

void SubteStatus::hombreVivoReleased(){
    qDebug() << "c_hombreVivo: released";
    m_eNetClient->CambiarValorClave("c_hombreVivo","released");
}

void SubteStatus::tractionLeverChanged(int value){
    m_tractionLeverPosition = value;
    qDebug() << "c_regulador_de_mando: "<< value;
    m_eNetClient->CambiarValorClave("c_regulador_de_mando",std::to_string(value));
}

void SubteStatus::emergencyOverrideClicked(){
    m_emergencyOverride = !m_emergencyOverride;
    if(m_emergencyOverride){
        qDebug() << "c_emergencyOverride: con";
        m_eNetClient->CambiarValorClave("c_emergencyOverride","con");

    }else{
        qDebug() << "c_emergencyOverride: des";
        m_eNetClient->CambiarValorClave("c_emergencyOverride","des");
    }
}

void SubteStatus::CSCPBypassed()
{
    m_CSCP=true;
    qDebug() << "CSCP bypassed";
}

void SubteStatus::CSCPActivated()
{
    m_CSCP = !m_leftDoors && !m_rightDoors;
    qDebug() << "CSCP actived";
}

void SubteStatus::openLeftDoors()
{
    m_leftDoors = OPEN;
    m_CSCP= false;
    emit CSCPChanged(m_CSCP);
}

void SubteStatus::openRightDoors()
{
    m_rightDoors = OPEN;
    m_CSCP= false;
    emit CSCPChanged(m_CSCP);
}

void SubteStatus::closeLeftDoors()
{
    m_leftDoors = CLOSE;
    m_CSCP= !m_rightDoors;
    emit CSCPChanged(m_CSCP);
}

void SubteStatus::closeRightDoors()
{
    m_rightDoors = CLOSE;
    m_CSCP= !m_leftDoors;
    emit CSCPChanged(m_CSCP);
}

bool SubteStatus::CSCPStatus()
{
    return m_CSCP;
}

void SubteStatus::setaActivated(){
    this->m_seta = true;
    qDebug() << "c_freno_emergencia: con";
    m_eNetClient->CambiarValorClave("c_freno_emergencia","con");

    m_traction = 0;
    qDebug() << "c_movimiento: " << m_traction;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}

void SubteStatus::setaDeactivated(){
    this->m_seta = false;
    qDebug() << "c_freno_emergencia: des";
    m_eNetClient->CambiarValorClave("c_freno_emergencia","des");

    //TODO: refactor this hardcoded!!!
    m_traction = static_cast<int>(((m_tractionLeverPosition-15)/85)*100);
    qDebug() << "c_movimiento: " << m_traction;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}

bool SubteStatus::isSetaActivated(){
    qDebug() << "---> Model, Seta value: " << this->m_seta;
    return this->m_seta;
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

void SubteStatus::updateSpeed(double value){
    m_speed = value;
    emit speedChanged(m_speed);
}

void SubteStatus::processValueChanged(std::string host, std::string key, std::string value){
    if(key.compare("v_velocidad") == 0){
        qDebug() << "cambio de velocidad recibido." ;
        updateSpeed(std::stod(value));
    }

    if(key.compare("i_estado_simulador") == 0){
        if (value.compare("0") == 0){

            qDebug() << "i_estado_simulador 0 recibido" ;

            if(!splashPassed){
                splashPassed = true;

                m_eNetClient->Suscribirse(m_instructionsHostName,"i_iniciar_simulador");
                m_eNetClient->Suscribirse(m_visualHostName,"v_velocidad");
                m_eNetClient->Suscribirse(m_visualHostName,"v_esfuerzo");
                m_eNetClient->Suscribirse(m_visualHostName,"v_intensidad");
                m_eNetClient->Suscribirse(m_visualHostName,"v_voltaje");
                m_eNetClient->Suscribirse(m_visualHostName,"v_llego_senial");

                emit controlReady();
            }

            emit controlReset();

            m_rana = "0";
            m_eNetClient->CambiarValorClave("c_rana",m_rana);
            m_tractionLeverPosition = 0;
            m_eNetClient->CambiarValorClave("c_regulador_mando",std::to_string((int)m_tractionLeverPosition));
            m_traction = 0;
            m_eNetClient->CambiarValorClave("c_movimiento",std::to_string((int)m_traction));
            m_seta = false;
            m_eNetClient->CambiarValorClave("c_freno_emergencia","des");

            emit controlDisable();

            m_eNetClient->CambiarValorClave("c_listo","1");
        }

        else if(value.compare("1") == 0){
            emit controlEnable();
        }

        else if(value.compare("2") == 0){
            emit controlDisable();
        }

    }
}
