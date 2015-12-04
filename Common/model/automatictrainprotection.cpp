#include "automatictrainprotection.h"

AutomaticTrainProtection::AutomaticTrainProtection(){
    reset();
}

AutomaticTrainProtection::~AutomaticTrainProtection(){
}

bool AutomaticTrainProtection::tractionReady(){
    return m_traction;
}

void AutomaticTrainProtection::reset(){
    m_allowedSpeed = 0;
    m_targetSpeed = 0;
    m_code = "";
}

double AutomaticTrainProtection::allowedSpeed() const{
    return m_allowedSpeed;
}

void AutomaticTrainProtection::setAllowedSpeed(double allowedSpeed){
    m_allowedSpeed = allowedSpeed;
}

double AutomaticTrainProtection::targetSpeed() const{
    return m_targetSpeed;
}

void AutomaticTrainProtection::setTargetSpeed(double targetSpeed){
    m_targetSpeed = targetSpeed;
}

std::string AutomaticTrainProtection::code() const{
    return m_code;
}

void AutomaticTrainProtection::setCode(const std::string &code){
    m_code = code;
}

void AutomaticTrainProtection::cutTraction(){
    m_traction = false;
}

void AutomaticTrainProtection::enableTraction(){
    m_traction = true;
}
