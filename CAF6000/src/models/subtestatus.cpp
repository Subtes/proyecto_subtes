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
