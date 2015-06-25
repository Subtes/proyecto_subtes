#include "subtestatus.h"
#include <QThread>
#include <QSplashScreen>
#include <QPixmap>

SubteStatus::SubteStatus(){
    splashPassed = false;

    m_horn = false;
    m_emergencyOverride = false;
    m_leftDoors = CLOSE;
    m_rightDoors = CLOSE;
    m_CSCP = false;
    m_speed = 0;
    m_targetSpeed = 0;
    m_allowedSpeed = 0;
    m_rana = "0";
    m_traction = 0;
    m_lastTraction = 0;
    m_tractionLeverPosition = 0;
    m_lastPosition = 0;

    m_seta = false;

    //initENet();

    m_pixMapSplash = QPixmap(":/subtewidgets/resources/splash.jpg");
    this->m_splash = new QSplashScreen(m_pixMapSplash);
    this->m_splash->setWindowFlags(Qt::WindowStaysOnTopHint);
    this->m_splash->showMaximized();

    //connect(this,SIGNAL(controlEnable()),this,SLOT(loadFinish()));
    connect(this,SIGNAL(controlReady()),this,SLOT(loadFinish()));
    //connect(this,SIGNAL(controlReset()),this,SLOT(loadStart()));

    //Timer ATP
    //this->m_timer_ATP_Allowed = new QTimer();

    //Creo los timer para debugeo :P
    //i_estado_simulador
//    this->m_timer_ies0 = new QTimer();
//    this->m_timer_ies1 = new QTimer();
//    this->m_timer_ies2 = new QTimer();
//    //v_llego_senial
//    this->m_timer_vls0 = new QTimer();
//    this->m_timer_vls1 = new QTimer();
//    //v_velocidad
//    this->m_timer_vvX1 = new QTimer();
//    this->m_timer_vvX2 = new QTimer();
//    //v_tramo_vel
//    this->m_timer_vtvT = new QTimer();

//    signalMapper = new QSignalMapper(this);
//    signalMapper->setMapping(m_timer_ies0, QString("ies0"));
//    signalMapper->setMapping(m_timer_ies1, QString("ies1"));
//    signalMapper->setMapping(m_timer_ies2, QString("ies2"));
//    signalMapper->setMapping(m_timer_vls0, QString("vls0"));
//    signalMapper->setMapping(m_timer_vls1, QString("vls1"));
//    signalMapper->setMapping(m_timer_vvX1, QString("vvX1"));
//    signalMapper->setMapping(m_timer_vvX2, QString("vvX2"));
//    signalMapper->setMapping(m_timer_vtvT, QString("vtvT"));

//    connect(m_timer_ies0, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));
//    connect(m_timer_ies1, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));
//    connect(m_timer_ies2, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));
//    connect(m_timer_vls0, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));
//    connect(m_timer_vls1, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));
//    connect(m_timer_vvX1, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));
//    connect(m_timer_vvX2, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));
//    connect(m_timer_vtvT, SIGNAL(timeout()),
//        signalMapper, SLOT (map()));

//    connect(signalMapper, SIGNAL(mapped(QString)),
//        this, SLOT(debugSignal(QString)));
}

void SubteStatus::debugSignal(QString s){

    if (s.compare("ies0")==0){
            this->processValueChanged("localHost", "i_estado_simulador", "0");
            this->m_timer_ies1->setInterval(2000);
            this->m_timer_ies1->start();
    }else if (s.compare("ies1")==0){
            this->processValueChanged("localHost", "i_estado_simulador", "1");
            this->m_timer_vtvT->setInterval(1000);
            this->m_timer_vtvT->start();
    }else if (s.compare("ies2")==0){
            this->processValueChanged("localHost", "i_estado_simulador", "2");
    }else if (s.compare("vls0")==0){
            this->processValueChanged("localHost", "v_llego_senial", "0");
    }else if (s.compare("vls1")==0){
            this->processValueChanged("localHost", "v_llego_senial", "1");
    }else if (s.compare("vvX1")==0){
            this->processValueChanged("localHost", "v_velocidad", "60");
            this->m_timer_vvX2->setInterval(2000);
            this->m_timer_vvX2->start();
    }else if (s.compare("vvX2")==0){
            this->processValueChanged("localHost", "v_velocidad", "10");
    }else if (s.compare("vtvT")==0){
            this->processValueChanged("localHost", "v_tramo_vel", "30");
            this->m_timer_vvX1->setInterval(3000);
            this->m_timer_vvX1->start();

    }else{
        qDebug() << "Senial QTimer: Opcion Debugeo Senales" << s;
    }

}

void SubteStatus::initENet(){
    //this->loadStart();
    //this->m_splash->showMaximized();
    //this->m_splash->showFullScreen();

    //=== eNet setup ===
    readIni();

    m_eNetClient = new ENetClient();

    using namespace std::placeholders;
    m_eNetClient->OnCambioValClave = std::bind(&SubteStatus::processValueChanged, this, _1, _2, _3);

    if (!m_eNetClient->Conectar(m_serverIp, m_serverPort, m_controlsHostName)){
        qDebug() << "ERROR AL CONECTAR CON EL SERVIDOR";
        qDebug() << "Intento conectar con:: servidor " << m_serverIp.c_str() << " , puerto "<< m_serverPort << " , host "<< m_controlsHostName.c_str();
    }
    m_eNetClient->Suscribirse(m_instructionsHostName,"i_estado_simulador");
    m_eNetClient->CambiarValorClave("c_listo","0");


    //Debugeo MM
//    this->m_timer_ies0->setInterval(5000);
//    this->m_timer_ies0->start();


}

void SubteStatus::readIni(){
    QDomDocument xml;

    QString fileName = QDir(qApp->applicationDirPath())
            .absoluteFilePath("etc/control.ini");

    qDebug() << "LECTURA DEL ARCHIVO DE CONFIGURACION .INI: " ;
    qDebug() << "Ubicacion del archivo: " << fileName;

    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly)){
        qDebug() << "Error en la carga del archivo de configuracion control.ini";
        return;
    }

    xml.setContent(&f);
    f.close();

    QDomElement root=xml.documentElement();

    qDebug() << "XML: root object" << root.nodeName();

    m_serverIp = root.namedItem("serverIp").toElement().text().toStdString();
    m_serverPort = root.namedItem("serverPort").toElement().text().toInt();
    m_controlsHostName = root.namedItem("m_controlsHostName").toElement().text().toStdString();
    m_visualHostName = root.namedItem("m_visualHostName").toElement().text().toStdString();
    m_instructionsHostName = root.namedItem("m_instructionsHostName").toElement().text().toStdString();

    qDebug() << "XML: server Ip: " << m_serverIp.c_str();
    qDebug() << "XML: server Port: " << m_serverPort;
    qDebug() << "XML: controls Host Name: " << m_controlsHostName.c_str();
    qDebug() << "XML: visual Host Name: " << m_visualHostName.c_str();
    qDebug() << "XML: instructions Host Name: " << m_instructionsHostName.c_str();
}


void SubteStatus::processValueChanged(std::string host, std::string key, std::string value){
    qDebug() << " processValueChanged:: host: " << host.c_str() << " key: "<< key.c_str() << " value: " << value.c_str() ;

    if(key.compare("i_estado_simulador") == 0){
        if (value.compare("0") == 0){

            qDebug() << "i_estado_simulador 0 recibido" ;
            m_eNetClient->CambiarValorClave("c_listo","0");

            if(!splashPassed){
                qDebug() << "!splashPassed" ;
                splashPassed = true;

                m_eNetClient->Suscribirse(m_instructionsHostName,"i_iniciar_simulador");
                m_eNetClient->Suscribirse(m_visualHostName,"v_velocidad");
                m_eNetClient->Suscribirse(m_visualHostName,"v_tramo_vel");
                m_eNetClient->Suscribirse(m_visualHostName,"v_esfuerzo");
                m_eNetClient->Suscribirse(m_visualHostName,"v_intensidad");
                m_eNetClient->Suscribirse(m_visualHostName,"v_voltaje");
                m_eNetClient->Suscribirse(m_visualHostName,"v_llego_senial");

                emit controlReady();

            }

            emit controlReset();

            m_rana = "0";
            m_eNetClient->CambiarValorClave("c_rana",m_rana);
            m_tractionLeverPosition = 0;
            m_eNetClient->CambiarValorClave("c_regulador_mando",std::to_string((int)m_tractionLeverPosition));
            m_traction = 0;
            m_eNetClient->CambiarValorClave("c_movimiento",std::to_string((int)m_traction));
            m_seta = false;
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
            m_seta = true;
            qDebug() << "c_freno_emergencia: con";
            m_eNetClient->CambiarValorClave("c_freno_emergencia","con");
            m_traction = 0;
            qDebug() << "c_movimiento: " << m_traction;
            m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
        }
    }

    else if(key.compare("v_velocidad") == 0){
        qDebug() << "cambio de velocidad recibido." ;
        updateSpeed(std::stod(value));
        if (this->m_speed > this->m_allowedSpeed){
                //if supero timer:
                //Ver control de velocidad, para el caso tirar freno emergencia!!!
                //Estaria hehco en el ATP controller, falta ver que implica corte traccion sin digamos seta
                //Ademas si tiro m_traction a 0 que pasa al retorno de la traccion ?? como retorno, alcanza con recalcular (la funcion)
        }
    }

    else if(key.compare("v_tramo_vel") == 0){
        qDebug() << "cambio de velocidad objetivo recibido." ;
        updateTargetSpeed(std::stod(value));
        updateAllowedSpeed((std::stod(value))*0.9);
    }

}


void SubteStatus::recalcularTraccion(){
    if(((m_rana.compare("ad")==0)||(m_rana.compare("at")==0))&&(!m_seta)){
        if(m_tractionLeverPosition > 15){
            m_traction = static_cast<int>((((double)m_tractionLeverPosition-15.0)/85.0)*100.0);
        }else if((m_tractionLeverPosition <= 15)&&(m_tractionLeverPosition >= -15)){
            m_traction = 0;
        }else if ((m_tractionLeverPosition < -15) && (m_tractionLeverPosition >= -95)){
            m_traction = static_cast<int>((((double)m_tractionLeverPosition+15.0)/80.0)*100.0);
        }else if (m_tractionLeverPosition < -95){
            m_traction = 0;
        }
    }else{
        m_traction = 0;
    }
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
    qDebug() << "c_movimiento: " << m_traction;
}


void SubteStatus::loadFinish(){
    this->m_splash->setHidden(true);
}

void SubteStatus::loadStart(){
    this->m_splash->showMaximized();
}

void SubteStatus::hornOn(){
    qDebug() << "c_bocina: on";
    m_eNetClient->CambiarValorClave("c_bocina","on");
    m_horn = true;
}


void SubteStatus::hornOff(){
    qDebug() << "c_bocina: off";
    m_eNetClient->CambiarValorClave("c_bocina","Off");
    m_horn = false;
}


void SubteStatus::wiperOn(){
    qDebug() << "c_limpiaParabrisas: on";
    m_eNetClient->CambiarValorClave("c_limpiaParabrisas","on");
}


void SubteStatus::wiperOff(){
    qDebug() << "c_limpiaParabrisas: off";
    m_eNetClient->CambiarValorClave("c_limpiaParabrisas","off");
}


void SubteStatus::washer(){
    qDebug() << "c_lavaParabrisas: on";
    m_eNetClient->CambiarValorClave("c_lavaParabrisas","on");
}

void SubteStatus::tractionLeverInZero(){
    m_traction = 0;
    if(((m_rana.compare("ad")==0)||(m_rana.compare("at")==0))&&(!m_seta)){
        qDebug() << "c_movimiento: 0";
        m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
    }
}

void SubteStatus::tractionReceived(int value){
    if(((m_rana.compare("ad")==0)||(m_rana.compare("at")==0))&&(!m_seta)){
        m_traction = value;
        qDebug() << "c_movimiento: "<< m_traction;
        if(abs(m_traction-m_lastTraction)>=5){
            m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
            m_lastTraction = m_traction;
        }
    }
}

void SubteStatus::brakeReceived(int value){

}

void SubteStatus::emergencyBrakeActived(){
    qDebug() << "c_movimiento: "<< 0;
    m_traction = 0;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
    m_eNetClient->CambiarValorClave("c_freno_emergencia","con");
}


void SubteStatus::ranaAD(){
    m_rana = "ad";
    qDebug() << "c_rana: AD";
    m_eNetClient->CambiarValorClave("c_rana","ad");
    recalcularTraccion();
}


void SubteStatus::ranaCERO(){
    m_rana = "0";
    qDebug() << "c_rana: 0";
    m_eNetClient->CambiarValorClave("c_rana","0");

    m_traction = 0;
    qDebug() << "c_movimiento: " << m_traction;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}


void SubteStatus::ranaAT(){
    m_rana = "at";
    qDebug() << "c_rana: AT";
    m_eNetClient->CambiarValorClave("c_rana","at");
    recalcularTraccion();
}


void SubteStatus::hombreVivoPressed(){
    qDebug() << "c_hombreVivo: pressed";
    m_eNetClient->CambiarValorClave("c_hombreVivo","pressed");
}


void SubteStatus::hombreVivoReleased(){
    qDebug() << "c_hombreVivo: released";
    m_eNetClient->CambiarValorClave("c_hombreVivo","released");
}


void SubteStatus::tractionLeverChanged(int value){
    m_tractionLeverPosition = value;
    if(abs(m_tractionLeverPosition-m_lastPosition)>=5){
        m_eNetClient->CambiarValorClave("c_regulador_de_mando",std::to_string(value));
        m_lastPosition = m_tractionLeverPosition;
    }
}


void SubteStatus::emergencyOverrideClicked(){
    m_emergencyOverride = !m_emergencyOverride;
    if(m_emergencyOverride){
        qDebug() << "c_emergencyOverride: con";
        m_eNetClient->CambiarValorClave("c_emergencyOverride","con");

    }else{
        qDebug() << "c_emergencyOverride: des";
        m_eNetClient->CambiarValorClave("c_emergencyOverride","des");
    }
}


void SubteStatus::CSCPBypassed(){
    m_CSCP=true;
    qDebug() << "CSCP bypassed";
}


void SubteStatus::CSCPActivated(){
    m_CSCP = !m_leftDoors && !m_rightDoors;
    qDebug() << "CSCP actived";
}


void SubteStatus::openLeftDoors(){
    m_leftDoors = OPEN;
    m_CSCP= false;
    emit CSCPChanged(m_CSCP);
}


void SubteStatus::openRightDoors(){
    m_rightDoors = OPEN;
    m_CSCP= false;
    emit CSCPChanged(m_CSCP);
}


void SubteStatus::closeLeftDoors(){
    m_leftDoors = CLOSE;
    m_CSCP= !m_rightDoors;
    emit CSCPChanged(m_CSCP);
}


void SubteStatus::closeRightDoors(){
    m_rightDoors = CLOSE;
    m_CSCP= !m_leftDoors;
    emit CSCPChanged(m_CSCP);
}


bool SubteStatus::CSCPStatus(){
    return m_CSCP;
}


void SubteStatus::setaActivated(){
    this->m_seta = true;
    qDebug() << "c_freno_emergencia: con";
    m_eNetClient->CambiarValorClave("c_freno_emergencia","con");
    m_eNetClient->CambiarValorClave("c_seta_emergencia","con");

    m_traction = 0;
    qDebug() << "c_movimiento: " << m_traction;
    m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}


void SubteStatus::setaDeactivated(){
    this->m_seta = false;
    qDebug() << "c_freno_emergencia: des";
    m_eNetClient->CambiarValorClave("c_freno_emergencia","des");
    m_eNetClient->CambiarValorClave("c_seta_emergencia","des");
    recalcularTraccion();
}


bool SubteStatus::isSetaActivated(){
    qDebug() << "---> Model, Seta value: " << this->m_seta;
    return this->m_seta;
}


void SubteStatus::pressedCON(){
    qDebug() << "---> Pressed, CON Disyuntor";
    /*
    Para poder conectar los disyuntores, es necesario:
    Tensión normal de Batería
    Tensión suficiente en el Hilo de Trabajo
    Rana en AD o AT, con mando en su cabina
    Regulador de Mando en posición “0”
    Pulsar “CON”
    */
}

void SubteStatus::pressedDES(){
    qDebug() << "---> Pressed, DES Disyuntor";
    /* Para desconectar los disyuntores, solo se pulsa “DES”, en cualquiera de las cabinas de conducción. */
}


void SubteStatus::updateSpeed(double value){
    m_speed = value;
    emit speedChanged(m_speed);
}



void SubteStatus::updateTargetSpeed(double value){
    m_targetSpeed = value;
    emit targetSpeedChanged(m_targetSpeed);
}

void SubteStatus::updateAllowedSpeed(double value){
    m_allowedSpeed = value;
    emit allowedSpeedChanged(m_allowedSpeed);
}

void SubteStatus::enableTraction(){
    //ATP lo usa
    this->recalcularTraccion();
    qDebug() << "ATP velocidad corregida antes de time out, recalculando traccion ---> ";
}

void SubteStatus::disableTraction(){
    //ATP lo usa
    this->m_traction = 0;
    qDebug() << "c_movimiento (Changed for traction disable control ATP): " << m_traction;
    this->m_eNetClient->CambiarValorClave("c_movimiento",std::to_string(m_traction));
}

double SubteStatus::getSpeed(){
    //ATP lo usa
    return (this->m_speed);
}

double SubteStatus::getAllowSpeed(){
    //ATP lo usa
    return (this->m_allowedSpeed);
}

SubteStatus::~SubteStatus(){

}
