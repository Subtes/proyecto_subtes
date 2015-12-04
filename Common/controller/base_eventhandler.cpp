#include "base_eventhandler.h"

Base_EventHandler::Base_EventHandler(){
}

Base_EventHandler::~Base_EventHandler(){
}

void Base_EventHandler::notifyValueChanged(std::string key, std::string value)
{
    m_eNetHelper->client()->CambiarValorClave(key,value);
}

void Base_EventHandler::notifyValueChanged(std::string key, std::string subKey, std::string value)
{
    m_eNetHelper->client()->CambiarValorClave(key,subKey,value);
}

void Base_EventHandler::initConnection(QString dirPath){
    m_eNetHelper->initENet(this,dirPath);
}

void Base_EventHandler::enableDiffusion(){
    m_boardsReady++;
    if(m_boardsReady==5){
        m_eNetHelper->client()->CambiarEstadoDifusion(true);
        m_boardsReady = 0;
        if(!m_cargandoEstado.compare("")==0)
            m_eNetHelper->client()->CambiarValorClave("c_estado_cargado",m_cargandoEstado);
        m_cargandoEstado = " ";
    }
}
