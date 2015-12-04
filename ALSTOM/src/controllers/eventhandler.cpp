#include "eventhandler.h"

EventHandler::EventHandler():
    Base_EventHandler(){

    m_eNetHelper = new Base_ENetHelper();
}

EventHandler::~EventHandler(){
}

void EventHandler::setModel(SubteState *subte)
{
    m_subte = subte;
}

void EventHandler::processValueChanged(std::string host, std::string key, std::string value){
    qDebug() << "value - key:: host:" << host.c_str() << " key:"<< key.c_str() << " value:" << value.c_str() << "time: " << QTime::currentTime().toString() ;

    if(key.compare("i_iniciar_simulador") == 0){
        if (value.compare("con") == 0){
            qDebug() << "i_iniciar_simulador con recibido" ;
            m_eNetHelper->client()->CambiarValorClave("c_listo","0");
            emit controlReady();
            m_eNetHelper->client()->Suscribirse(m_eNetHelper->instructionsHostName(),"i_estado_simulador");
            m_eNetHelper->client()->Suscribirse(m_eNetHelper->visualHostName(),"v_velocidad");
            m_eNetHelper->client()->Suscribirse(m_eNetHelper->visualHostName(),"v_voltaje");
            m_eNetHelper->client()->Suscribirse(m_eNetHelper->visualHostName(),"v_esfuerzo");
            m_eNetHelper->client()->Suscribirse(m_eNetHelper->visualHostName(),"v_estado_puertas");
            emit controlReset();
            m_eNetHelper->client()->CambiarValorClave("c_rana","at");
            m_eNetHelper->client()->CambiarValorClave("c_regulador_mando","0");
            m_eNetHelper->client()->CambiarValorClave("c_traccion","0");
            m_eNetHelper->client()->CambiarValorClave("c_freno_emergencia","des");
            emit controlDisable();
            m_eNetHelper->client()->CambiarValorClave("c_listo","1");

        }else if (value.compare("des") == 0){
            m_eNetHelper->client()->CambiarValorClave("c_listo","0");
            m_eNetHelper->client()->CambiarValorClave("c_regulador_mando"," ");
            m_eNetHelper->client()->CambiarValorClave("c_llave_atp"," ");
            m_eNetHelper->client()->CambiarValorClave("c_modo_conduccion"," ");
            Sleep(1000);
            emit closeApp();
        }
    }

    else if(key.compare("i_estado_simulador") == 0){
        if (value.compare("0") == 0){

            qDebug() << "i_estado_simulador 0 recibido" ;
            m_eNetHelper->client()->CambiarValorClave("c_listo","0");
            emit controlReset();
            m_eNetHelper->client()->CambiarValorClave("c_rana","at");
            m_eNetHelper->client()->CambiarValorClave("c_regulador_de_mando","0");
            m_eNetHelper->client()->CambiarValorClave("c_traccion","0");
            emit controlDisable();
            m_eNetHelper->client()->CambiarValorClave("c_listo","1");
        }

        else if(value.compare("1") == 0){
            emit controlEnable();
        }

        else if(value.compare("2") == 0){
            emit controlDisable();
        }
    }

    else if(key.compare("v_velocidad") == 0){
        m_subte->updateSpeed(std::stod(value));
        qDebug() << "Velocidad ingresa velocidad correcta." ;
    }
    else if(key.compare("v_voltaje") == 0){
        try{
            m_subte->updateVolt(std::stod(value));
        }
        catch (...) {
            qDebug() << "voltaje incorrecta." ;
        }
    }
    else if(key.compare("v_voltaje") == 0){
        try{
            m_subte->updateVolt(std::stod(value));
        }
        catch (...) {
            qDebug() << "voltaje incorrecta." ;
        }
    }
    else if(key.compare("v_esfuerzo") == 0){
        try{
            m_subte->updateAmm(std::stod(value));
        }
        catch (...) {
            qDebug() << "esfuerzo incorrecta." ;
        }
    }

    else if(key.compare("v_estado_puertas") == 0){
        try{
            qDebug() << "cambio de estado de puertas";

            QString message = value.c_str();
            QStringList parameters = message.split(";");
            std::string side = parameters.at(0).toStdString();
            std::string state = parameters.at(1).toStdString();

            if(side.compare("derecha") == 0){
                if(state.compare("abierto") == 0){
                    m_subte->openRightDoors();
                    qDebug() << "puertas derechas abiertas";
                }
                else if(state.compare("cerrado") == 0){
                    m_subte->closeRightDoors();
                    qDebug() << "puertas derechas cerradas";
                }
            } else {
                if(state.compare("abierto") == 0){
                    m_subte->openLeftDoors();
                    qDebug() << "puertas izquierdas abiertas";
                }
                else if(state.compare("cerrado") == 0){
                    m_subte->closeLeftDoors();
                    qDebug() << "puertas izquierdas cerrado";
                }
            }
        }
        catch (...) {
            qDebug() << "valor puertas incorrecto." ;
        }
    }

}


