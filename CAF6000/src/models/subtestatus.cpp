#include "subtestatus.h"

SubteStatus::SubteStatus()
{
    horn = false;
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
    horn = true;
}

void SubteStatus::hornOff()
{
    horn = false;
}

void SubteStatus::wiperOff()
{
    qDebug() << "wiperOff";
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