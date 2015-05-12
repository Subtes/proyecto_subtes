#include "subtestatus.h"

SubteStatus::SubteStatus()
{
    horn = false;
    emergencyOverride = false;
    leftDoors = CLOSE;
    rightDoors = CLOSE;
    CSCP = false;
}

SubteStatus::~SubteStatus()
{
}

void SubteStatus::wiperOn()
{
    qDebug() << "wiperON";
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
    qDebug() << "wiper Off";
}

void SubteStatus::washer()
{
    qDebug() << "washer";
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

