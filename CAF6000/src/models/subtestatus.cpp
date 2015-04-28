#include "subtestatus.h"

SubteStatus::SubteStatus()
{
    horn = false;
}

SubteStatus::~SubteStatus()
{

}

void SubteStatus::hornOn(){
    horn = true;
}

void SubteStatus::hornOff(){
    horn = false;
}
