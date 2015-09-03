#include "eventhandler.h"
#include <QSplashScreen>
#include <QPixmap>
#include <Qt>
#include <stdio.h>

EventHandler::EventHandler(QDesktopWidget *desktop)
{
    F1_down = false;
    F2_down = false;
    F3_down = false;
    F4_down = false;
    F5_down = false;
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

    m_imageSplash = QPixmap(":/resources/splash.jpg");

    if(desktop->screenCount() == 4){
        qDebug() << "Entre en For de pantallas igual 4: ";

        m_splash1 = new QSplashScreen(m_imageSplash);
        m_splash1->setWindowFlags(Qt::WindowStaysOnTopHint);
        m_splash2 = new QSplashScreen(m_imageSplash);
        m_splash2->setWindowFlags(Qt::WindowStaysOnTopHint);
        m_splash3 = new QSplashScreen(m_imageSplash);
        m_splash3->setWindowFlags(Qt::WindowStaysOnTopHint);
        m_splash4 = new QSplashScreen(m_imageSplash);
        m_splash4->setWindowFlags(Qt::WindowStaysOnTopHint);


        QRect s0 = desktop->screenGeometry(0);
        QRect s1 = desktop->screenGeometry(1);
        QRect s2 = desktop->screenGeometry(2);
        QRect s3 = desktop->screenGeometry(3);


        m_splash1->move(s0.topLeft());
        m_splash2->move(s1.topLeft());
        m_splash3->move(s2.topLeft());
        m_splash4->move(s3.topLeft());

        m_splash1->showMaximized();
        m_splash2->showMaximized();
        m_splash3->showMaximized();
        m_splash4->showMaximized();

    }else{
        m_splash1 = new QSplashScreen(m_imageSplash);
        m_splash1->setWindowFlags(Qt::WindowStaysOnTopHint);
        m_splash1->showMaximized();
    }


}

EventHandler::~EventHandler(){
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

    if(key.compare("i_iniciar_simulador") == 0){
        //Cargar Splash
        if (value.compare("con") == 0){
            qDebug() << "i_iniciar_simulador con recibido" ;
            m_eNetClient->CambiarValorClave("c_listo","0");

            if(!splashPassed){
                qDebug() << "!splashPassed" ;
                splashPassed = true;
                emit controlReady();
                    //Bajar splash
                if(desktop->screenCount() == 4){
                    m_splash1->hide();
                    m_splash2->hide();
                    m_splash3->hide();
                    m_splash4->hide();
                }else{
                    m_splash1->hide();
                }

                qDebug() << "Bajando Splashhh";
            }

            m_eNetClient->Suscribirse(m_eNetHelper->instructionsHostName,"i_estado_simulador");
            m_eNetClient->Suscribirse(m_eNetHelper->instructionsHostName,"i_cargar_estado");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_velocidad");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_tramo_vel");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_esfuerzo");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_intensidad");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_voltaje");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_llego_senial");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_esfuerzo");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_intensidad");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_voltaje");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_presion_cilindro");
            m_eNetClient->Suscribirse(m_eNetHelper->visualHostName,"v_presion_freno");
            m_subte->reset();
            emit controlReset();

            m_eNetClient->CambiarValorClave("c_rana",m_subte->rana());
            m_eNetClient->CambiarValorClave("c_regulador_mando",std::to_string((int)m_subte->tractionLeverPosition()));
            m_eNetClient->CambiarValorClave("c_traccion",std::to_string((int)m_subte->traction()));
            m_eNetClient->CambiarValorClave("c_freno_emergencia","des");

            emit controlDisable();
            m_eNetClient->CambiarValorClave("c_listo","1");

        }else if (value.compare("des") == 0){
            m_eNetClient->CambiarValorClave("c_listo","0");
            m_eNetClient->CambiarValorClave("c_regulador_mando","");
            m_eNetClient->CambiarValorClave("c_llave_atp","");
            m_eNetClient->CambiarValorClave("c_modo_conduccion","");

            Sleep(1000);
            emit closeApp();
        }
    }

    else if(key.compare("i_estado_simulador") == 0){
        if (value.compare("0") == 0){

            qDebug() << "i_estado_simulador 0 recibido" ;

            m_eNetClient->CambiarValorClave("c_listo","0");

            m_subte->reset();
            emit controlReset();

            m_eNetClient->CambiarValorClave("c_rana",m_subte->rana());
            m_eNetClient->CambiarValorClave("c_regulador_de_mando",std::to_string((int)m_subte->tractionLeverPosition()));
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
        std::string direction = "";
        // find the last occurrence of ';'
        size_t pos = value.find_last_of(";");
        // make sure the poisition is valid
        if (pos != std::string::npos)
            direction = value.substr(pos+1);
        else
            qDebug() << "No se pudo encontrar 'separador ;' en el codigo de via recibido";

        if(direction.compare("0")==0){
            qDebug() << "entro por sentido" <<direction.c_str();
            std::string state = "";
            // find the first occurrence of ';'
            pos = value.find_first_of(";");

            // make sure the poisition is valid
            if (pos != std::string::npos)
                state = value.substr(pos+1,1);
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
    }

    else if(key.compare("v_velocidad") == 0){
        qDebug() << "cambio de velocidad recibido." ;
        m_subte->updateSpeed(std::stod(value));
    }

    else if(key.compare("v_tramo_vel") == 0){
        qDebug() << "cambio de velocidad objetivo recibido." ;
        m_subte->updateTargetSpeed(std::stod(value));
    }

    else if(key.compare("i_cambio_senial") == 0){
        if (value.compare("1") == 0){
            emit iCambioSenial1();
            qDebug() << "senial salida anden recibida, 1";
        }
    }

    else if(key.compare("c_freno_estacionamiento") == 0){
        if (value.compare("con") == 0){
        }
    }

    else if(key.compare("i_cargar_estado") == 0){
        qDebug() << "carga de ejercicio recibida." ;
        emit cargarEstado(std::stoi(value));
    }

    else if(key.compare("v_voltaje") == 0){
        qDebug() << "cambio de voltaje recibido." ;
        m_subte->updateVolt(std::stod(value));
    }

    else if(key.compare("v_intensidad") == 0){
        qDebug() << "cambio de intensidad recibido." ;
        m_subte->updateAmm(std::stod(value));
    }

    else if(key.compare("v_esfuerzo") == 0){
        qDebug() << "cambio de esfuerzo recibido." ;
        m_subte->updateEffort(std::stod(value));
    }
    else if(key.compare("v_presion_cilindro") == 0){
        qDebug() << "cambio de Presion de cilindro recibido." ;
        try{
            m_subte->updatePreassureRed(std::stod(value));
        }
        catch (...) {
            qDebug() << "Presion de cilindro incorrecta." ;
        }

        }
    else if(key.compare("v_presion_freno") == 0){
        qDebug() << "cambio de presion de frenado recibido." ;
        try{
            m_subte->updatePreassureWhite(std::stod(value));
        }
        catch(...){
             qDebug() << "presion de frenado incorrecta." ;
        }
    }

}

void EventHandler::processKeyPressed(DWORD k)
{
    if ( k == _F1 && !F1_down) {
        F1_down = true;
        qDebug() << "F1 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_iniciar_simulador", "con");
    } else if ( k == _F2 && !F2_down) {
        F2_down = true;
        qDebug() << "F2 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_iniciar_simulador", "des");
    } else if ( k == _F3 && !F3_down) {
        F3_down = true;
        qDebug() << "F3 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_estado_simulador", "0");
    } else if ( k == _F4 && !F4_down) {
        F4_down = true;
        qDebug() << "F4 key pressed";
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_estado_simulador", "1");
    } else if ( k == _F5 && !F5_down  ){
        F5_down = true;
        this->processValueChanged(m_eNetHelper->instructionsHostName, "i_cambio_senial", "1");
        qDebug() << "F5 key pressed";
    }  else if ( k == _K && !K_down ){
        this->notifyValueChanged("c_llave_atp","con");
        this->notifyValueChanged("c_modo_conduccion","atp");
        K_down = true;
        qDebug() << "K key pressed";
        emit kPressed();
    } else if ( k == _L && !L_down ){
        this->notifyValueChanged("c_llave_atp","des");
        L_down = true;
        qDebug() << "L key pressed";
        emit lPressed();
    } else if ( k == _A && !A_down ){
        A_down = true;
        emit aPressed();
        qDebug() << "A key pressed";
    } else if ( k == _R  && !R_down ){
        R_down = true;
        emit rPressed();
        qDebug() << "R key pressed";
    } else if ( k == _tF && !F_down ){
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
        emit cPressed();
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
        emit frenoEstDes();
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
    } else if ( k == _F3 ) {
        qDebug() << "F3 key released";
        F3_down = false;
    } else if ( k == _F4 ) {
        qDebug() << "F4 key released";
        F4_down = false;
    } else if ( k == _F5 ) {
        qDebug() << "F5 key released";
        F5_down = false;
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
    } else if ( k == _tF ){
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

