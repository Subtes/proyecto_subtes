#include "subtestatus.h"

SubteStatus::SubteStatus()
{
    horn = false;
    emergencyOverride = false;
    leftDoors = CLOSE;
    rightDoors = CLOSE;
    CSCP = false;
    speed = 0;


    //=== eNet setup ===

    ENetClient *eNetClient = new ENetClient();

    ElCliente->OnCambioValClave = &ClientCambioValClave;

    ElCliente->Conectar("127.0.0.1", 5000, "ClienteCPP");
    ElCliente->CambiarValorClave("clave", "valor");
    ElCliente->Suscribirse("Cliente_65","faba");


}

SubteStatus::~SubteStatus()
{
}

void SubteStatus::wiperOn()
{
    //qDebug() << "wiperON";
}

void SubteStatus::hornOn()
{
    qDebug() << "horn = true";
    horn = true;
}

void SubteStatus::hornOff()
{
    qDebug() << "horn = false";
    horn = false;
}

void SubteStatus::wiperOff()
{
    //qDebug() << "wiper Off";
    speed -= 10;
    emit speedChanged(speed);
}

void SubteStatus::washer()
{
    //qDebug() << "washer";
    speed++;
    emit speedChanged(speed);
}

void SubteStatus::tractionLeverInZero(){
    qDebug() << "zero :0";
}

void SubteStatus::tractionReceived(int value){
    qDebug() << "traction: " << value;
}

void SubteStatus::brakeReceived(int value){
    qDebug() << "brake: " << value;
}

void SubteStatus::emergencyBrakeActived(){
    qDebug() << "emergency brake!!!!!";
}

void SubteStatus::ranaAD(){
    qDebug() << "rana ADELANTE ---> Activated";
}

void SubteStatus::ranaCERO(){
    qDebug() << "rana CERO ---> Activated";
}

void SubteStatus::ranaAT(){
    qDebug() << "rana ATRAS ---> Activated";
}
void SubteStatus::hombreVivoPressed(){
    qDebug() << "HV";
}

void SubteStatus::hombreVivoReleased(){
    qDebug() << "HV released";
}

void SubteStatus::emergencyOverrideClicked(){
    emergencyOverride = !emergencyOverride;
    qDebug() << "emergency Override Clicked, EmOv: " << emergencyOverride ;
}

void SubteStatus::CSCPBypassed()
{
    CSCP=true;
    qDebug() << "CSCP bypassed";
}

void SubteStatus::CSCPActivated()
{
    CSCP = !leftDoors && !rightDoors;
    qDebug() << "CSCP actived";
}

void SubteStatus::openLeftDoors()
{
    leftDoors = OPEN;
    CSCP= false;
    emit CSCPChanged(CSCP);
}

void SubteStatus::openRightDoors()
{
    rightDoors = OPEN;
    CSCP= false;
    emit CSCPChanged(CSCP);

}

void SubteStatus::closeLeftDoors()
{
    leftDoors = CLOSE;
    CSCP= !rightDoors;
    emit CSCPChanged(CSCP);

}

void SubteStatus::closeRightDoors()
{
    rightDoors = CLOSE;
    CSCP= !leftDoors;
    emit CSCPChanged(CSCP);

}

bool SubteStatus::CSCPStatus()
{
    return CSCP;
}

void SubteStatus::setaActivated(){
    qDebug() << "---> Model Seta Activated ";
    this->m_seta = true;
}

void SubteStatus::setaDeactivated(){
    qDebug() << "---> Model Seta Deactivated ";
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

void SubteStatus::processValueChanged(std::string unHost, std::string unaClave, std::string unValor){

}
