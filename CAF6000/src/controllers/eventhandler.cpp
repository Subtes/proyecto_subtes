#include "eventhandler.h"

EventHandler::EventHandler()
{
    m_eNetClient = new ENetClient();
    m_eNetHelper = new ENetHelper(m_eNetClient);

    splashPassed = false;

    KeyPressEater *kel = KeyPressEater::instance();
    kel->setConnected(TRUE);
    connect(kel,SIGNAL(keyPressed(DWORD)),this,SLOT(processKey(DWORD)));
}

EventHandler::~EventHandler()
{
}

void EventHandler::initConnection()
{
    m_eNetHelper->initENet(m_eNetClient, this);
}

void EventHandler::setModel(SubteStatus *subte)
{
    m_subte = subte;
}

void EventHandler::notifyValueChanged(std::string key, std::string value)
{
    m_eNetClient->CambiarValorClave(key,value);
}

void EventHandler::processValueChanged(std::string host, std::string key, std::string value){
    qDebug() << "processValueChanged:: host:" << host.c_str() << " key:"<< key.c_str() << " value:" << value.c_str() ;

    if(key.compare("i_estado_simulador") == 0){
        if (value.compare("0") == 0){

            qDebug() << "i_estado_simulador 0 recibido" ;
            m_eNetClient->CambiarValorClave("c_listo","0");

            if(!splashPassed){
                qDebug() << "!splashPassed" ;
                splashPassed = true;
                emit controlReady();
            }

            m_eNetClient->Suscribirse(m_eNetHelper->instructionsHostName,"i_iniciar_simulador");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_velocidad");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_tramo_vel");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_esfuerzo");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_intensidad");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_voltaje");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_llego_senial");

            m_subte->reset();
            emit controlReset();

            m_eNetClient->CambiarValorClave("c_rana",m_subte->rana());
            m_eNetClient->CambiarValorClave("c_regulador_mando",std::to_string((int)m_subte->tractionLeverPosition()));
            m_eNetClient->CambiarValorClave("c_traccion",std::to_string((int)m_subte->traction()));
            m_eNetClient->CambiarValorClave("c_freno_emergencia","des");

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

    else if(key.compare("v_llego_senial") == 0){
        std::string state = "";
        // find the last occurrence of ';'
        size_t pos = value.find_last_of(";");
        // make sure the poisition is valid
        if (pos != std::string::npos)
            state = value.substr(pos+1);
        else
            qDebug() << "No se pudo encontrar 'separador ;' en el codigo de via recibido";

        if (state.compare("0")==0){
            m_subte->setaActivated();
            qDebug() << "c_freno_emergencia: con";
            m_eNetClient->CambiarValorClave("c_freno_emergencia","con");
            m_subte->tractionReceived(0);
            qDebug() << "c_traccion: " << m_subte->traction();
            m_eNetClient->CambiarValorClave("c_traccion",std::to_string(m_subte->traction()));
        }
    }

    else if(key.compare("v_velocidad") == 0){
        qDebug() << "cambio de velocidad recibido." ;
        m_subte->updateSpeed(std::stod(value));
    }

    else if(key.compare("v_tramo_vel") == 0){
        qDebug() << "cambio de velocidad objetivo recibido." ;
        m_subte->updateTargetSpeed(std::stod(value));
    }

}

void EventHandler::processKey(DWORD k)
{
    if ( k == _F1 ) {
        qDebug() << "F1 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_estado_simulador", "0");
    }else if ( k == _F2 ) {
        qDebug() << "F2 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_estado_simulador", "1");
    }
}
