#include "subtestatus.h"

SubteStatus::SubteStatus()
{
    horn = false;
    emergencyOverride = false;
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
