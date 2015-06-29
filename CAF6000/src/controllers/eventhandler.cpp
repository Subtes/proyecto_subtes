#include "eventhandler.h"

EventHandler::EventHandler()
{
    F1_down = false;
    F2_down = false;
    K_down = false;
    L_down = false;
    A_down = false;
    R_down = false;
    F_down = false;
    T_down = false;
    B_down = false;
    C_down = false;
    CERO_down = false;
    UNO_down = false;
    DOS_down = false;
    TRES_down = false;
    CUATRO_down = false;
    CINCO_down = false;
    SEIS_down = false;
    SIETE_down = false;
    OCHO_down = false;
    NUEVE_down = false;

    m_eNetClient = new ENetClient();
    m_eNetHelper = new ENetHelper(m_eNetClient);

    splashPassed = false;

    KeyPressEater *kel = KeyPressEater::instance();
    kel->setConnected(TRUE);
    connect(kel,SIGNAL(keyPressed(DWORD)),this,SLOT(processKeyPressed(DWORD)));
    connect(kel,SIGNAL(keyReleased(DWORD)),this,SLOT(processKeyReleased(DWORD)));

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

void EventHandler::processKeyPressed(DWORD k)
{
    if ( k == _F1 && !F1_down) {
        F1_down = true;
        qDebug() << "F1 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_estado_simulador", "0");
    }else if ( k == _F2 && !F2_down) {
        F2_down = true;
        qDebug() << "F2 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_estado_simulador", "1");
    } else if ( k == _K && !K_down ){
        this->notifyValueChanged("c_llave_atp","con");
        K_down = true;
        qDebug() << "K key pressed";
    } else if ( k == _L && !L_down ){
        this->notifyValueChanged("c_llave_atp","des");
        L_down = true;
        qDebug() << "L key pressed";
    } else if ( k == _A && !A_down ){
        A_down = true;
        emit aPressed();
        qDebug() << "A key pressed";
    } else if ( k == _R  && !R_down ){
        R_down = true;
        emit rPressed();
        qDebug() << "R key pressed";
    } else if ( k == _F && !F_down ){
        F_down = true;
        qDebug() << "F key pressed";
        emit fPressed();
    } else if ( k == _T && !T_down ){
        T_down = true;
        qDebug() << "T key pressed";
        emit tPressed();
    } else if ( k == _B && !B_down){
        B_down = true;
        qDebug() << "B key pressed";
        emit bPressed();
    } else if ( k == 0x43 && !C_down){
        C_down = true;
        qDebug() << "C key pressed";
        this->notifyValueChanged("c_freno_estacionamiento","con");
    } else if ( k == _CERO && !CERO_down  ){
        CERO_down = true;
        emit ceroPressed();
        qDebug() << "0 key pressed";
    } else if ( k == _UNO && !UNO_down  ){
        UNO_down = true;
        this->notifyValueChanged("c_pulsador_bateria","con");
        qDebug() << "1 key pressed";
    } else if ( k == _DOS && !DOS_down  ){
        DOS_down = true;
        this->notifyValueChanged("c_conmutador_puesta_en_servicio","automatica");
        qDebug() << "2 key pressed";
    } else if ( k == _TRES && !TRES_down  ){
        TRES_down = true;
        qDebug() << "3 key pressed";
        this->notifyValueChanged("c_estado_sicas","ok");
    } else if ( k == _CUATRO && !CUATRO_down  ){
        CUATRO_down = true;
        this->notifyValueChanged("c_conmutador_puesta_en_servicio_automatica","con");
        qDebug() << "4 key pressed";
    } else if ( k == _CINCO && !CINCO_down  ){
        CINCO_down = true;
        this->notifyValueChanged("c_disyuntor","con");
        qDebug() << "5 key pressed";
    } else if ( k == _SEIS && !SEIS_down  ){
        SEIS_down = true;
        this->notifyValueChanged("c_freno_estacionamiento","des");
        qDebug() << "6 key pressed";
    } else if ( k == _SIETE && !SIETE_down  ){
        SIETE_down = true;
        this->notifyValueChanged("c_modo_conduccion","atp");
        qDebug() << "7 key pressed";
    } else if ( k == _OCHO && !OCHO_down  ){
        OCHO_down = true;
        this->notifyValueChanged("c_conmutador_puesta_en_servicio_automatica","des");
        qDebug() << "8 key pressed";
    } else if ( k == _NUEVE && !NUEVE_down  ){
        NUEVE_down = true;
        this->notifyValueChanged("c_pulsador_bateria","des");
        qDebug() << "9 key pressed";
    }
}

void EventHandler::processKeyReleased(DWORD k){
    if ( k == _F1 ) {
        qDebug() << "F1 key released";
        F1_down = false;
    } else if ( k == _F2 ) {
        qDebug() << "F2 key released";
        F2_down = false;
    } else if ( k == _K ){
        qDebug() << "K key released";
        K_down = false;
    } else if ( k == _L ){
        qDebug() << "L key released";
        L_down = false;
    } else if ( k == _A ){
        qDebug() << "A key released";
        A_down = false;
    } else if ( k == _R ){
        qDebug() << "R key released";
        R_down = false;
    } else if ( k == _F ){
        qDebug() << "F key released";
        F_down = false;
    } else if ( k == _T ){
        qDebug() << "T key released";
        T_down = false;
    } else if ( k == _B ){
        B_down = false;
        qDebug() << "B key released";
        emit bReleased();
    } else if ( k == 0x43 ){
        qDebug() << "C key released";
        C_down = false;
    } else if ( k == _CERO ){
        qDebug() << "0 key released";
        CERO_down = false;
    } else if ( k == _UNO ){
        qDebug() << "1 key released";
        UNO_down = false;
    } else if ( k == _DOS ){
        qDebug() << "2 key released";
        DOS_down = false;
    } else if ( k == _TRES ){
        TRES_down = false;
        qDebug() << "3 key released";
    } else if ( k == _CUATRO ){
        CUATRO_down = false;
        qDebug() << "4 key released";
    } else if ( k == _CINCO ){
        CINCO_down = false;
        qDebug() << "5 key released";
    } else if ( k == _SEIS ){
        SEIS_down = false;
        qDebug() << "6 key released";
    } else if ( k == _SIETE ){
        SIETE_down = false;
        qDebug() << "7 key released";
    } else if ( k == _OCHO ){
        OCHO_down = false;
        qDebug() << "8 key released";
    } else if ( k == _NUEVE ){
        NUEVE_down = false;
        qDebug() << "9 key released";
    }
}

