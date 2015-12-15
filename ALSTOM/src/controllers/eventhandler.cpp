#include "eventhandler.h"

EventHandler::EventHandler()
{
    m_eNetClient = new ENetClient();
    m_eNetHelper = new ENetHelper(m_eNetClient);
}

EventHandler::~EventHandler()
{

}

void EventHandler::processValueChanged(std::string host, std::string key, std::string value){
    qDebug() << "value - key:: host:" << host.c_str() << " key:"<< key.c_str() << " value:" << value.c_str() << "time: " << QTime::currentTime().toString() ;

    if(key.compare("i_iniciar_simulador") == 0){
        if (value.compare("con") == 0){
            qDebug() << "i_iniciar_simulador con recibido" ;
            m_eNetClient->CambiarValorClave("c_listo","0");
            emit controlReady();
            m_eNetClient->Suscribirse(m_eNetHelper->instructionsHostName,"i_estado_simulador");


            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_velocidad");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_voltajeizq");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_voltajeder");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_esfuerzo");

//------------------------------------SACAR SOLO PARA PROBAR PUERTAS--------

            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_doors");


            emit controlReset();
            m_eNetClient->CambiarValorClave("c_rana","at");
            m_eNetClient->CambiarValorClave("c_regulador_mando","0");
            m_eNetClient->CambiarValorClave("c_traccion","0");
            m_eNetClient->CambiarValorClave("c_freno_emergencia","des");
            emit controlDisable();
            m_eNetClient->CambiarValorClave("c_listo","1");

        }else if (value.compare("des") == 0){
            m_eNetClient->CambiarValorClave("c_listo","0");
            m_eNetClient->CambiarValorClave("c_regulador_mando"," ");
            m_eNetClient->CambiarValorClave("c_llave_atp"," ");
            m_eNetClient->CambiarValorClave("c_modo_conduccion"," ");
            Sleep(1000);
            emit closeApp();
        }
    }

    else if(key.compare("i_estado_simulador") == 0){
        if (value.compare("0") == 0){

            qDebug() << "i_estado_simulador 0 recibido" ;
            m_eNetClient->CambiarValorClave("c_listo","0");
            emit controlReset();
            m_eNetClient->CambiarValorClave("c_rana","at");
            m_eNetClient->CambiarValorClave("c_regulador_de_mando","0");
            m_eNetClient->CambiarValorClave("c_traccion","0");
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

    else if(key.compare("v_velocidad") == 0){
        m_subte->updateneedleVelocityTcms(std::stod(value));
        qDebug() << "Velocidad ingresa velocidad correcta." ;
    }
    else if(key.compare("v_voltajeizq") == 0){
        try{
            m_subte->updateVoltimetroLeftTCMS(std::stod(value));
        }
        catch (...) {
            qDebug() << "voltaje incorrecta." ;
        }
    }
    else if(key.compare("v_voltajeder") == 0){
        try{
            m_subte->updateVoltimetroRightTCMS(std::stod(value));
        }
        catch (...) {
            qDebug() << "voltaje incorrecta." ;
        }
    }
    else if(key.compare("v_esfuerzo") == 0){
        try{
            m_subte->updateneedleamperimetro(std::stod(value));
        }
        catch (...) {
            qDebug() << "esfuerzo incorrecta." ;
        }
    }

//------------------------------------SACAR SOLO PARA PROBAR PUERTAS--------

    else if(key.compare("v_doors") == 0){
        try{
            m_subte->updatevaluedoors(std::stod(value));
        }
        catch (...) {
            qDebug() << "valor puertas incorrecto." ;
        }
    }

}

void EventHandler::notifyValueChanged(std::string key, std::string value)
{
    m_eNetClient->CambiarValorClave(key,value);
}

void EventHandler::initConnection()
{
    m_eNetHelper->initENet(m_eNetClient, this);
}

void EventHandler::setModel(SubteState *subte)
{
    m_subte = subte;
}
