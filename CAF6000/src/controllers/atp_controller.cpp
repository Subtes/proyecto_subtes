#include "atp_controller.h"
#include <QtMath>

#include <math.h>
#include <stdio.h>

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp *view, EventHandler *eventHandler)
{
    this->m_subte = subte;
    this->m_view = view;
    this->m_eventHandler = eventHandler;

    this->m_onATP = false;

    //Conexiones del ATP.

        //Conexiones In-Externas:
    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    connect(subte,SIGNAL(targetSpeedChanged(double)),this,SLOT(updateTargetSpeed(double)));

    connect(eventHandler,SIGNAL(kPressed()),this,SLOT(initATP()));
    connect(eventHandler,SIGNAL(lPressed()),this,SLOT(resetATP()));
    //connect(eventHandler,SIGNAL(iCambioSenial1()),SIGNAL(signalAnden()));
    connect(eventHandler,SIGNAL(accelerationInstant(double)),this,SLOT(setACE(double)));
    connect(eventHandler,SIGNAL(nextToEstation()),this,SLOT(nextToEstation()));

        //Conexiones de control Internas
    connect(this,SIGNAL(allowedSpeedChange(double)),this,SLOT(superviseSpeed()));
    //connect(eventHandler,SIGNAL(),SLOT(setACE(double));
    //connect(eventHandler,SIGNAL(frenoEstDes()),SIGNAL(enableTraction()));

        //Salidas Externas:
    connect(this, SIGNAL(cutTraction()),subte,SLOT(cutTraction()));
    connect(this, SIGNAL(enableTraction()),subte,SLOT(enableTraction()));
    connect(this, SIGNAL(enableBreakEmergency()),subte,SLOT(emergencyBrakeActived()));
    connect(this, SIGNAL(desableBreakEmergency()),subte,SLOT(emergencyBrakeReleased()));

}

/**************************************** Nuevo ATP ******************************************/
    //Acciones, rutinas a realizar en los estados:

void Atp_Controller::set_uTVC(){
/**
  * Va a ser 0 si no es CMC, caso contrario va a ser CTE porque si es CMC
  * y esta iniciando arranca con velocidad 0. O sea arrancaría con una transición peldaño.
  */
    if (!m_drivingModeCMC){
        m_uTVC = 0;
    }
    else{
        m_uTVC = 2;
    }
}

//Inicia la maquina de estados, o sea el ATP, deberia estar conectado a la senal salida de Plataforma.
void Atp_Controller::initATP(){
//VV
    this->onATP();
    this->m_machineATP->start();

    //HH Deberian ir en setter´s y getter´s luego.
    //Tiempo T1 de la Transicion G Tiempo
    this->m_t_TGT = 3000;
    //aceleración instantánea
    this->m_ACE = 0.5;
    //JF – Jerk de frenado: 0.89m/s3 (peor caso para 1 coche sin freno – vea [REF-9]).
    this->m_Jerk = 0.89;
    //Grade máximo de la vía (en módulo):
    this->m_Gm = 3.75;
    //TC – Tasa de la curva de reducción de código: 0,7m/s2.
    this->m_Tc = 0.7;
    //AF – Atraso de freno: 1.75s (incluye peor caso de reacción de freno del tren, en 1 coche
    //[REF-9]: 1.25s y tiempo de reacción del ATP: 0.50s).
    this->m_A_freno = 1.75;

    if(this->m_subte->getDrivingModeATP()){
        setDrivingMode(0);
    }else{
        setDrivingMode(1);
    }

    set_uTVC();

    m_speed = 0.0;
    m_speedAllowed = 0.0;

    m_onATP = true;

    //Intervalo de trabajo del ATP, salva en caso de quedar la velocidad planchada CTE y no recibir muestreo.
    //m_t_evalChangeSpeed->setInterval(500);
    //m_t_evalChangeSpeed->start();
}

void Atp_Controller::resetATP(){

    this->offATP();

    this->m_e_A->deleteLater();
    this->m_e_B->deleteLater();
    this->m_e_C->deleteLater();
    this->m_e_D->deleteLater();

    this->m_e_Final_State->deleteLater();
    this->m_machineATP->deleteLater();

    this->m_onATP = false;

    qDebug() << "Atp_Controller::resetATP() ---> ATP machine stop";
}

void Atp_Controller::setDrivingMode(int d){
 //VV Falta chequear off sets, y ver modo AL AT si van en true y se prende falla en ATP.
    switch(d){
    case 0:
        m_drivingModeCMC = true;
        this->m_view->setCMC(true);
        m_OS_ACT = 4.0;
        m_OS_LCT = 5.0;
        m_OS_AFS = 2.0;
        m_OS_LFS = 3.0;
        m_OS_AFE = 0.0;
        break;
    case 1:
        m_drivingModeCL = true;
        this->m_view->setCL(true);
        break;
    case 2:
        m_drivingModeAL = true;
        this->m_view->setFalla(true);
        m_OS_ACT = 4.0;
        m_OS_LCT = 5.0;
        m_OS_AFS = 2.0;
        m_OS_LFS = 3.0;
        m_OS_AFE = 1.0;
        break;
     case 3:
        m_drivingModeAT = true;
        this->m_view->setFalla(true);
        break;
    }
}

void Atp_Controller::updateTargetSpeed(double speed){

    if (m_onATP){

        this->m_view->updateTargetSpeed(speed);
        this->setSpeedTarget(speed);
        this->updateAllowedSpeed(speed);

    }
}

void Atp_Controller::nextToEstation(){

    m_AF_previous = m_AF;
    m_AF = "1";
    //Esto es un Parche debido al modelo!! ojo ver. Es porque no manda señales manda velocidades que no son unicas.
    m_speedTargetPrevious = m_speedTarget;
    m_speedTarget = 15.0;

}

void Atp_Controller::updateSpeed(double speed){
    //Tiene dos conecciones por lo menos
    //Controla velocidad con permitida y acciona
        //Si todo bien update en vista real speed
        //en else voy a emitir una senal privada cuando no verifique ahi engancho
   if (m_onATP){
       this->m_view->updateSpeed(speed);
       this->m_speed = speed;
       superviseSpeed();
   }
}

void Atp_Controller::setAllowedSpeed(double s){

    m_speedAllowedPrevious = m_speedAllowed;
    m_speedAllowed = s;
    qDebug()<<"velocidad permitida Previa: --->"<<m_speedAllowedPrevious;
    qDebug()<<"velocidad permitida Actual: --->"<<m_speedAllowed;
    emit allowedSpeedChange(s);

}

void Atp_Controller::setSpeedTarget(double speed){

    int s = static_cast<int>(speed);
    switch(s){
        case 0:
            m_AF_previous = m_AF;
            m_AF = "0";
        break;
        case 15:
            m_AF_previous = m_AF;
            m_AF = "2";
        break;
        case 25:
            m_AF_previous = m_AF;
            m_AF = "3";
        break;
        case 30:
            m_AF_previous = m_AF;
            m_AF = "4";
        break;
        case 40:
            m_AF_previous = m_AF;
            m_AF = "5";
        break;
        case 50:
            m_AF_previous = m_AF;
            m_AF = "6";
        break;
        case 60:
            m_AF_previous = m_AF;
            m_AF = "7";
        break;
    }

    m_speedTargetPrevious = m_speedTarget;
    m_speedTarget = speed;
//    m_AF = QString::number(m_speedTarget);
//    m_AF_previous = QString::number(m_speedTargetPrevious);
    //emit targetSpeedChange(speed);
}

void Atp_Controller::critiqueSpeed(int op){

    m_uTVC = op;

    if ( !m_uTVC ){
        m_speedCritique = 0;
    }else if ( m_uTVC == 1 ){
        //Curva
        m_speedCritique = 3.6*((m_ACE + m_Tc)*m_A_freno + pow( (fmin(m_ACE,-0.098*m_Gm)+m_Tc),2 )/(2*m_Jerk) );
    }else{
        //CTE
        m_speedCritique = 3.6*(m_ACE*m_A_freno + pow( (fmin(m_ACE,-0.098*m_Gm)),2 )/(2*m_Jerk));
    }
}

/**
 * @brief Atp_Controller::updateAllowedSpeed
 * Siempre que exista una variación en la Velocidad Objetivo, la Velocidad Permitida
 * podrá sufrir variación.
 * A continuación se describen las diversas transiciones posibles, siendo que el orden sigue la
 * prioridad decreciente. De esta manera, solamente si la primera transición no es identificada es
 * que las transiciones subsiguientes podrán ocurrir.
 * @param speedTargetNew
 */
void Atp_Controller::updateAllowedSpeed(double speedTargetNew){

    critiqueSpeed(2);

    if ( (m_speed <= 0.00)||(m_speedTargetPrevious < m_speedTarget)||((m_speedTargetPrevious >= m_speedTarget)&&(m_speed <= (m_speedTarget - 5.00)))||
             (m_AF == "0" && m_AF_previous == "1")||(m_AF == "0" && m_AF_previous == "2")){
            //Transicion Peldano
            setAllowedSpeed(speedTargetNew);
        }else if ((m_speedTarget < m_speedTargetPrevious)&&(m_speedTarget != m_AF_1)){
            //Transicion Gradual por Tiempo (3 seg; 0,7 m/s2)
            //m_t_TGT->start();
            //Conectar con transitionGT() agregar setter para variable con los 3000
            QTimer::singleShot(m_t_TGT,this,SLOT(transitionGT()));
        }else if ((m_speedTarget < m_speedTargetPrevious)&&(m_speedTarget == m_AF_1)){
            //Transicion Gradual por distancia
            transitionGD();
        }
}

void Atp_Controller::transitionGT(){
    // V = Vo + At
    int t = static_cast<int>(((m_speedTarget - m_speedTargetPrevious)*0.277777777777778)/(-0.7));

    QTime *timeLap = new QTime(0,0,0);
    QTime ts(0,0,t,0);

    double vAllowed;
    vAllowed = m_speedTargetPrevious /*+ (-0.7)*(timeLap->second())*/;
    setAllowedSpeed(vAllowed);

    if (m_drivingModeCMC) critiqueSpeed(1);

    timeLap->start();
    //WHILE timeLAP ...
    int lap = 0;
    while ((timeLap->operator <(ts)) || m_speedAllowed > m_speedTarget /* alcanzo AllowedSpeed */){
        //wait && update speedAllowed
        lap = timeLap->elapsed();
        if (lap % 2 == 0){
            //update allowedSpeed hacer calculo en funcion del tiempo transcurrido
            vAllowed = m_speedTargetPrevious + ((-0.7)*(timeLap->second()))*3.6;
            setAllowedSpeed(vAllowed);
        }
        //QTimer::singleShot(1500,this,SLOT(transitionGT()));

    }

    critiqueSpeed(2);
    setAllowedSpeed(m_speedTarget);
}

/**
 * @brief Atp_Controller::transitionGD
 * a: 0.6 Aref, aceleracion de referencia de la curva de plataforma.
 * dp: distancia estandar de plataforma: 403.
 * tbp: tiempo de atraso de B-point de reduccion de codigo: 1.6.
 * d_ini: valor inicial.
 */
void Atp_Controller::transitionGD(){
    // V = 3.6*RAIZ(2*Aref*D)
    //Falta agregar el tema distancia.
    //Aref – Aceleración de referencia
    double a = 0.6;
    double dp = 403.0;
    //Es el tiempo de atraso de B-point
    double tbp = 1.6;
    double d_ini = 0;
    //double d = 0;
    int v_aux;

    qDebug()<<"Inicio Transicion GD: ---------------->";
    d_ini = dp - m_speed*0.277777777777778*tbp;
    //d = d_ini + m_speed*0.277777777777778*t + 0.5*a*(t*t);
    qDebug() << "d_ini: "<< d_ini;

    v_aux = static_cast<int>(3.6*qSqrt(2*a*d_ini));
    setAllowedSpeed(v_aux);

    if (m_drivingModeCMC) critiqueSpeed(0);

    //m_distanceGD = 0;
    m_changeDistance = false;

    //HH Hacerlo global despues
    QTime *timeLap = new QTime(0,0,0);
    qDebug()<<"Comiendo de reloj GD: "<<timeLap;
    timeLap->start();

    while (d_ini >= 1 || m_speedAllowed >= m_speedTarget){
        QTimer::singleShot(500,this,SLOT(evalCalculateDistance()));
        //--d_ini;
        if (m_changeDistance){
            d_ini -= (m_speed*0.277777777777778)*((timeLap->elapsed())/1000);
            qDebug() << "tiempo Transucrrido GD: *****  "<< timeLap->elapsed();
            qDebug() << "d_ini: "<< d_ini;
        }
        v_aux = static_cast<int>(3.6*qSqrt(2*a*d_ini));
        qDebug()<<"Velocidad Permitida de curva GD:  ---->  "<< v_aux;
        //if (v_aux <= m_speedAllowed){
        setAllowedSpeed(v_aux);
        //}
    }

    critiqueSpeed(2);
    setAllowedSpeed(m_speedTarget);
    qDebug()<<"+++++++++++++++ FIN Transicion GD: +++++++++++++++++";
}

void Atp_Controller::evalCalculateDistance(){
    m_changeDistance = !m_changeDistance;
}

/**
  * Supervision de la velocidad
  * Senales activadoras
  *  void _1AtoB();
  *  void _2BtoA();
  *  void _3BtoC();
  *  void _4CtoB();
  *  void _5CtoD();
  *  void _6DtoC();
  *   Rutinas
  *  void routingA();
  *  void routingB();
  *  void routingC();
  *  void routingD();
  */
void Atp_Controller::superviseSpeed(){
//Deberia entrar cada vez que cambia speed o allowed speed
    qDebug()<<"-------------------Supervise Speed: ----------------------";
    qDebug()<<"m_speed: "<<m_speed;
    qDebug()<<"m_speedAllowed: "<<m_speedAllowed;
    qDebug()<<"m_speedCritique: "<<m_speedCritique;
    qDebug()<<"m_uTVC: "<<m_uTVC;
    qDebug()<<"m_OS_AFE: "<<m_OS_AFE;
    qDebug()<<"m_OS_LFS: "<<m_OS_LFS;
    qDebug()<<"m_OS_AFS: "<<m_OS_AFS;
    qDebug()<<"m_OS_ACT: "<<m_OS_ACT;
    qDebug()<<"m_OS_LCT: "<<m_OS_LCT;

    if (m_speed == 0.0){
        qDebug()<< "_1AtoB: ----> FrenoEmergencia: OFF, FrenoServicio: ON, CorteTraccion: ON ";
        emit _1AtoB();
    }
    if ((m_speed + m_OS_AFE > m_speedAllowed) || ((m_speed + m_OS_AFE + m_speedCritique > m_speedAllowed) && (m_uTVC!=0)) ){
        qDebug()<< " _2BtoA: ----> FrenoEmergencia: ON, FrenoServicio: ON, CorteTraccion: ON  ";
        emit _2BtoA();
    }
    if ( ((m_speed + m_OS_LFS <= m_speedAllowed)&& (m_uTVC==0)) || (m_speed + m_OS_LFS + m_speedCritique <= m_speedAllowed) ){
        qDebug()<<" _3BtoC: ----> FrenoEmergencia: OFF, FrenoServicio: OFF, CorteTraccion: ON ";
        emit _3BtoC();
    }
    if ( ( m_speed + m_OS_AFS > m_speedAllowed ) || ((m_uTVC!=0) && ((m_speed + m_OS_AFS + m_speedCritique) > m_speedAllowed)) ){
        qDebug()<<" _4CtoB: ----> FrenoEmergencia: OFF, FrenoServicio: ON, CorteTraccion: ON ";
        emit _4CtoB();
    }
    if ( (m_speed + m_OS_LCT <= m_speedAllowed && (m_uTVC==0)) || (m_speed + m_OS_LCT + m_speedCritique <= m_speedAllowed) ){
        qDebug()<<" _5CtoD: ----> FrenoEmergencia: OFF, FrenoServicio: OFF, CorteTraccion: OFF ";
        emit _5CtoD();
    }
    if ( (m_speed + m_OS_ACT > m_speedAllowed) || ((m_uTVC!=0) && (m_speed + m_OS_ACT + m_speedCritique > m_speedAllowed)) ){
        qDebug()<< " _6DtoC: ----> FrenoEmergencia: OFF, FrenoServicio: OFF, CorteTraccion: ON ";
        emit _6DtoC();
    }

    qDebug()<<"----------------------FIN supervise speed-------------------";
}

void Atp_Controller::onATP(){

    //Maquina de Estado ATP, solo version CMC
    this->m_machineATP = new QStateMachine();

    //Estados
    this->m_e_A = new QState();
    this->m_e_B = new QState();
    this->m_e_C = new QState();
    this->m_e_D = new QState();

    //Agrego los estados
    this->m_machineATP->addState(this->m_e_A);
    this->m_machineATP->addState(this->m_e_B);
    this->m_machineATP->addState(this->m_e_C);
    this->m_machineATP->addState(this->m_e_D);

    //Estado Final
    this->m_e_Final_State = new QFinalState();

    //Seteamos estado inicial
    this->m_machineATP->setInitialState(this->m_e_A);

    //Transiciones
    //A --to--> B
    m_e_A->addTransition(this,SIGNAL(_1AtoB()),m_e_B);
    //B --to--> A Back
    m_e_B->addTransition(this,SIGNAL(_2BtoA()),m_e_A);
    //B --to--> C
    m_e_B->addTransition(this,SIGNAL(_3BtoC()),m_e_C);
    //C <--to--B Back
    m_e_C->addTransition(this,SIGNAL(_4CtoB()),m_e_B);
    //C --to--> D
    m_e_C->addTransition(this,SIGNAL(_5CtoD()),m_e_D);
    //D --to--> C Back
    m_e_D->addTransition(this,SIGNAL(_6DtoC()),m_e_C);

    //Transicion Final
    m_e_A->addTransition(this,SIGNAL(offATP()),m_e_Final_State);
    m_e_B->addTransition(this,SIGNAL(offATP()),m_e_Final_State);
    m_e_C->addTransition(this,SIGNAL(offATP()),m_e_Final_State);
    m_e_D->addTransition(this,SIGNAL(offATP()),m_e_Final_State);

    //Acciones:
    connect(m_e_A,SIGNAL(entered()),this,SLOT(routingA()));
    connect(m_e_B,SIGNAL(entered()),this,SLOT(routingB()));
    connect(m_e_C,SIGNAL(entered()),this,SLOT(routingC()));
    connect(m_e_D,SIGNAL(entered()),this,SLOT(routingD()));

    //Timer
    m_t_evalChangeSpeed = new QTimer();
    connect(m_t_evalChangeSpeed, SIGNAL(timeout()),this,SLOT(superviseSpeed()));
}

void Atp_Controller::offATP(){

    this->m_machineATP->stop();

    this->m_view->setCMC(false);
    this->m_view->setCL(false);
    this->m_view->setFalla(false);
    this->m_view->setCorte(false);
    this->m_view->setCorteBlink(false);
    this->m_view->setFrenoUrg(false);
    this->m_view->setFrenoUrgBlink(false);
}

void Atp_Controller::setACE(double a){
    this->m_ACE = a;
}

void Atp_Controller::routingA(){

    this->m_view->setFrenoUrg(true);
    this->m_view->setFserv(true);
    this->m_view->setCorte(true);
    qDebug() << "Atp_Controller::routingA() ---> Corte, Fserv, FrenoUrg: ON ";
    emit cutTraction();
    emit enableBreakEmergency();
}

void Atp_Controller::routingB(){

    this->m_view->setFrenoUrg(false);
    this->m_view->setFserv(true);
    this->m_view->setCorte(true);
    qDebug() << "Atp_Controller::routingB() ---> FrenoUrg: OFF; Corte, Fserv: ON ";
    emit cutTraction();
    emit desableBreakEmergency();
    //HH Falta emitir conexion a modelo con freno servicio
}

void Atp_Controller::routingC(){

    this->m_view->setFrenoUrg(false);
    this->m_view->setFserv(false);
    this->m_view->setCorte(true);
    qDebug() << "Atp_Controller::routingC() ---> FrenoUrg, Fserv: OFF; Corte: ON ";
    emit cutTraction();
    //HH Falta emitir conexion a modelo con freno servicio
}

void Atp_Controller::routingD(){

    this->m_view->setFrenoUrg(false);
    this->m_view->setFserv(false);
    this->m_view->setCorte(false);
    qDebug() << "Atp_Controller::routingD() ---> FrenoUrg, Fserv, Corte: OFF; ";
    emit enableTraction();
}

Atp_Controller::~Atp_Controller(){

}
