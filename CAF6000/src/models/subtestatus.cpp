#include "subtestatus.h"

SubteStatus::SubteStatus()
{
    horn = false;
    emergencyOverride = false;
    leftDoors = CLOSE;
    rightDoors = CLOSE;
    CSCP = false;
    speed = 0;
}

void SubteStatus::initENet(){
    //=== eNet setup ===
    serverIp = "127.0.0.1";
    serverPort = 5000;
    controlsHostName = "P1_control";
    visualHostName = "P1_visualizador";
    instructionsHostName = "P1_instruccion";
    eNetClient = new ENetClient();
    std::function<void(std::string,std::string,std::string)> receiverFunction = &processValueChanged;
    eNetClient->OnCambioValClave = receiverFunction;
    eNetClient->Suscribirse(visualHostName,"v_velocidad");
}

SubteStatus::~SubteStatus()
{
}

void SubteStatus::hornOn()
{
    qDebug() << "c_bocina: on";
    eNetClient->CambiarValorClave("c_bocina","on");
    horn = true;
}

void SubteStatus::hornOff()
{
    qDebug() << "c_bocina: off";
    eNetClient->CambiarValorClave("c_bocina","Off");
    horn = false;
}

void SubteStatus::wiperOn()
{
    qDebug() << "c_limpiaParabrisas: on";
    eNetClient->CambiarValorClave("c_limpiaParabrisas","on");
}

void SubteStatus::wiperOff()
{
    qDebug() << "c_limpiaParabrisas: off";
    eNetClient->CambiarValorClave("c_limpiaParabrisas","off");
}

void SubteStatus::washer()
{
    qDebug() << "c_lavaParabrisas: on";
    eNetClient->CambiarValorClave("c_lavaParabrisas","on");
}

void SubteStatus::tractionLeverInZero(){
    qDebug() << "c_movimiento y c_regulador_de_mando: 0";
    eNetClient->CambiarValorClave("c_regulador_de_mando","0");
    eNetClient->CambiarValorClave("c_movimiento","0");
}

void SubteStatus::tractionReceived(int value){
    qDebug() << "c_movimiento y c_regulador_de_mando: "<< value;
    eNetClient->CambiarValorClave("c_regulador_de_mando",std::to_string(value));
    eNetClient->CambiarValorClave("c_movimiento",std::to_string(value));
}

void SubteStatus::brakeReceived(int value){
    qDebug() << "c_movimiento y c_regulador_de_mando: "<< -value;
    eNetClient->CambiarValorClave("c_regulador_de_mando",std::to_string(-value));
    eNetClient->CambiarValorClave("c_movimiento",std::to_string(-value));
}

void SubteStatus::emergencyBrakeActived(){
    qDebug() << "c_movimiento y c_regulador_de_mando: "<< -100;
    eNetClient->CambiarValorClave("c_regulador_de_mando",std::to_string(-100));
    eNetClient->CambiarValorClave("c_movimiento",std::to_string(-100));
    eNetClient->CambiarValorClave("c_freno_emergencia","con");
}

void SubteStatus::ranaAD(){
    qDebug() << "c_rana: AD";
    eNetClient->CambiarValorClave("c_rana","ad");
}

void SubteStatus::ranaCERO(){
    qDebug() << "c_rana: 0";
    eNetClient->CambiarValorClave("c_rana","0");
}

void SubteStatus::ranaAT(){
    qDebug() << "c_rana: AT";
    eNetClient->CambiarValorClave("c_rana","at");
}

void SubteStatus::hombreVivoPressed(){
    qDebug() << "c_hombreVivo: pressed";
    eNetClient->CambiarValorClave("c_hombreVivo","pressed");
}

void SubteStatus::hombreVivoReleased(){
    qDebug() << "c_hombreVivo: released";
    eNetClient->CambiarValorClave("c_hombreVivo","released");
}

void SubteStatus::emergencyOverrideClicked(){
    emergencyOverride = !emergencyOverride;
    if(emergencyOverride){
        qDebug() << "c_emergencyOverride: con";
        eNetClient->CambiarValorClave("c_emergencyOverride","con");

    }else{
        qDebug() << "c_emergencyOverride: des";
        eNetClient->CambiarValorClave("c_emergencyOverride","des");
    }
}

void SubteStatus::CSCPBypassed()
{
    CSCP=true;
    qDebug() << "CSCP bypassed";
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);

}

void SubteStatus::CSCPActivated()
{
    CSCP = !leftDoors && !rightDoors;
    qDebug() << "CSCP actived";
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);

}

void SubteStatus::openLeftDoors()
{
    leftDoors = OPEN;
    CSCP= false;
    emit CSCPChanged(CSCP);
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);

}

void SubteStatus::openRightDoors()
{
    rightDoors = OPEN;
    CSCP= false;
    emit CSCPChanged(CSCP);
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);


}

void SubteStatus::closeLeftDoors()
{
    leftDoors = CLOSE;
    CSCP= !rightDoors;
    emit CSCPChanged(CSCP);
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);


}

void SubteStatus::closeRightDoors()
{
    rightDoors = CLOSE;
    CSCP= !leftDoors;
    emit CSCPChanged(CSCP);
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);


}

bool SubteStatus::CSCPStatus()
{
    return CSCP;
}

void SubteStatus::setaActivated(){
    qDebug() << "---> Model Seta Activated ";
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);

    this->m_seta = true;
}

void SubteStatus::setaDeactivated(){
    qDebug() << "---> Model Seta Deactivated ";
    eNetClient->Conectar(serverIp, serverPort, controlsHostName);

    this->m_seta = false;
    
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
    speed = value;
    emit speedChanged(speed);
}

SubteStatus::keySet hashKey(std::string inString) {
   if (inString == "v_velocidad") return SubteStatus::v_velocidad;
   if (inString == "c_movimiento") return SubteStatus::c_movimiento;
   if (inString == "c_regulador_de_mando") return SubteStatus::c_regulador_de_mando;
}

void SubteStatus::processValueChanged(std::string host, std::string key, std::string value){
    switch (hashKey(key)) {
        case v_velocidad:
            qDebug() << "cambio de velocidad recibido." ;
            updateSpeed(std::stod(value));
            break;
        default:
            qDebug() << "La clave: \""<< key.c_str() <<"\" no es reconocida.";
            break;
        }
}
