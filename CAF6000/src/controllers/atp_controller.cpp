#include "atp_controller.h"
#include <QtMath>

#include <math.h>
#include <stdio.h>

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp *view, EventHandler *eventHandler)
{
    this->m_subte = subte;
    this->m_view = view;
    this->m_eventHandler = eventHandler;

    this->speedTarget = 0.0;
    this->speed = 0.0;
    this->allowedSpeed = 0.0;

    this->m_drivingModeCMC = true;

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


    //Conexiones del ATP al resto del mundo.

        //Conecciones Externas:
    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    connect(subte,SIGNAL(targetSpeedChanged(double)),this,SLOT(updateTargetSpeed(double)));
    //connect(subte,SIGNAL(setaFired()),this,SIGNAL(setaFiredRoutine()));
    connect(eventHandler,SIGNAL(kPressed()),this,SLOT(initATP()));
    connect(eventHandler,SIGNAL(lPressed()),this,SLOT(resetATP()));
    connect(eventHandler,SIGNAL(iCambioSenial1()),SIGNAL(signalAnden()));
    //connect(eventHandler,SIGNAL(frenoEstDes()),SIGNAL(enableTraction()));

        //Salidas Externas:
    connect(this, SIGNAL(cutTraction()),subte,SLOT(cutTraction()));
    connect(this, SIGNAL(enableTraction()),subte,SLOT(enableTraction()));
    connect(this, SIGNAL(enableBreakEmergency()),subte,SLOT(emergencyBrakeActived()));
    connect(this, SIGNAL(desableBreakEmergency()),subte,SLOT(emergencyBrakeReleased()));

}

/**************************************** Nuevo ATP ******************************************/
    //Acciones, rutinas a realizar en los estados:
void Atp_Controller::onATP(){

}

void Atp_Controller::offATP(){
//HH
}

void Atp_Controller::set_uTVC(){

    if (!m_drivingModeCMC){
        m_uTVC = 0;
    }else{
        m_uTVC = 2;
    }
}

//Inicia la maquina de estados, o sea el ATP, deberia estar conectado a la senal salida de Plataforma.
void Atp_Controller::initATP(){

    this->m_machineATP->start();
    this->speed = 0.0;
    if ((this->m_subte->targetSpeed())>= 1.0){
            this->speedTarget = 0.0;
    }
    this->allowedSpeed = 15.0;
    qDebug() << "Atp_Controller::initATP ---> ATP iniciado en e_turnOn0";
    this->t_timerToTurnOn->setInterval(10000);
}

void Atp_Controller::resetATP(){

    this->m_machineATP->stop();

    this->m_view->setCMC(false);
    this->m_view->setCorte(false);
    this->m_view->setCorteBlink(false);
    this->m_view->setFrenoUrg(false);
    this->m_view->setFrenoUrgBlink(false);

    this->speedTarget = 0.0;
    this->speed = 0.0;
    this->allowedSpeed = 0.0;

    if (m_subte->getDrivingModeATP()){
        this->setDrivingMode(0);
    }else{
        this->setDrivingMode(1);
    }
    qDebug() << "Atp_Controller::resetATP() ---> ATP machine stop";
}

void Atp_Controller::setDrivingMode(int d){
 //HH Falta chequear off sets
    switch(d){
    case 0:
        m_drivingModeCMC = true;
        this->m_view->setCMC(true);
        m_OS_ACT = 4.0;
        m_OS_LCT = 5.0;
        m_OS_AFS = 2.0;
        m_OS_LFS = 3.0;
        m_OS_AFE = 0.0;
    case 1:
        m_drivingModeCL = true;
    case 2:
        m_drivingModeAL = true;
        m_OS_ACT = 4.0;
        m_OS_LCT = 5.0;
        m_OS_AFS = 2.0;
        m_OS_LFS = 3.0;
        m_OS_AFE = 1.0;
     case 3:
        m_drivingModeAT = true;
    }

}

void Atp_Controller::routingA(){

    this->m_view->setFrenoUrg(true);
    this->m_view->setFserv(true);
    this->m_view->setCorte(true);

    qDebug() << "Atp_Controller::routingA() ---> Corte, Fserv, FrenoUrg: ON ";
}

void Atp_Controller::routingB(){

    this->m_view->setFrenoUrg(false);
    this->m_view->setFserv(true);
    this->m_view->setCorte(true);

    qDebug() << "Atp_Controller::routingB() ---> FrenoUrg: OFF; Corte, Fserv: ON ";
}

void Atp_Controller::routingC(){

    this->m_view->setFrenoUrg(false);
    this->m_view->setFserv(false);
    this->m_view->setCorte(true);

    qDebug() << "Atp_Controller::routingC() ---> FrenoUrg, Fserv: OFF; Corte: ON ";
}

void Atp_Controller::routingD(){

    this->m_view->setFrenoUrg(false);
    this->m_view->setFserv(false);
    this->m_view->setCorte(false);

    qDebug() << "Atp_Controller::routingD() ---> FrenoUrg, Fserv, Corte: OFF; ";
}

void Atp_Controller::updateTargetSpeed(double speed){

    this->m_view->updateTargetSpeed(speed);

    this->setSpeedTarget(speed);
    this->updateAllowedSpeed(speed);
}

void Atp_Controller::updateSpeed(double speed){
    //Tiene dos conecciones por lo menos
    //Controla velocidad con permitida y acciona
        //Si todo bien update en vista real speed
        //en else voy a emitir una senal privada cuando no verifique ahi engancho
    this->m_view->updateSpeed(speed);

    this->speed = speed;
    double dif = (double)(this->allowedSpeed - this->speed);
    qDebug() << "Atp_Controller::updateSpeed Diferencia speed - allowedSpeed: "<< dif;
    qDebug() << "allowed: " << this->allowedSpeed << "speed: " << this->speed;

}

Atp_Controller::~Atp_Controller(){
}

/**
 * Siempre que exista una variación en la Velocidad Objetivo, la Velocidad Permitida
 * podrá sufrir variación.
 * A continuación se describen las diversas transiciones posibles, siendo que el orden sigue la
 * prioridad decreciente. De esta manera, solamente si la primera transición no es identificada es
 * que las transiciones subsiguientes podrán ocurrir.
 */

void Atp_Controller::updateAllowedSpeed(double speedTargetNew){
//    this->m_view->updateAllowedSpeed(speed);
//    this->allowedSpeed = speed;

if ( (m_speed <= 0.00)||(m_speedTargetPrevious < m_speedTarget)||((m_speedTargetPrevious >= m_speedTarget)&&(m_speed <= (m_speedTarget - 5.00)))||
         (m_AF == "0" && m_AF_previous == "1")||(m_AF == "0" && m_AF_previous == "2")){
        //Transicion Peldano
        setAllowedSpeed(speedTargetNew);
    }else if ((m_speedTarget < m_speedTargetPrevious)&&(m_speedTarget != m_AF_1)){
        //Transicion Gradual por Tiempo (3 seg; 0,7 m/s2)
        //m_t_TGT->start();
        //Conectar con transitionGT() agregar variable con los 3000
        if (m_drivingModeCMC) m_uTVC = 1;
        QTimer::singleShot(3000,this,SLOT(transitionGT()));
    }else if ((m_speedTarget < m_speedTargetPrevious)&&(m_speedTarget == m_AF_1)){
        //Transicion Gradual por distancia
        if (m_drivingModeCMC) m_uTVC = 0;
        transitionGD();
    }
}

void Atp_Controller::setAllowedSpeed(double s){
    m_speedAllowedPrevious = m_speedAllowed;
    m_speedAllowed = s;
    emit allowedSpeedChange(s);
}

void Atp_Controller::setSpeedTarget(double speed){
    m_speedTargetPrevious = m_speedTarget;
    m_speedTarget = speed;
    m_AF = QString::number(m_speedTarget);
    m_AF_previous = QString::number(m_speedTargetPrevious);
    emit targetSpeedChange(speed);
}

void Atp_Controller::transitionGT(){
    // V = Vo + At
    int t = static_cast<int>(((m_speedTarget - m_speedTargetPrevious)*0.277777777777778)/(-0.7));

    QTime *timeLap = new QTime(0,0,0);
    QTime ts(0,0,t,0);

    double vAllowed;
    vAllowed = m_speedTargetPrevious + (-0.7)*(timeLap->second());
    setAllowedSpeed(vAllowed);

    int lap = 0;

    timeLap->start();
    //WHILE timeLAP ...
    while ((timeLap->operator <(ts)) || m_speedAllowed > m_speedTarget /* alcanzo AllowedSpeed */){
        //wait && update speedAllowed
        lap = timeLap->elapsed();
        if (lap % 2 == 0){
            //update allowedSpeed hacer calculo en funcion del tiempo transcurrido
            vAllowed = m_speedTargetPrevious + (-0.7)*(timeLap->second());
            setAllowedSpeed(vAllowed);
        }
        //QTimer::singleShot(1500,this,SLOT(transitionGT()));

    }

    setAllowedSpeed(m_speedTarget);
}

void Atp_Controller::transitionGD(){
    // V = 3.6*RAIZ(2*Aref*D)
    double a = 0.6;
    double dp = 403.0;
    double tbp = 1.6;
    double d_ini = 0;
    //double d = 0;
    int v_aux;

    d_ini = dp - m_speed*0.277777777777778*tbp;
    //d = d_ini + m_speed*0.277777777777778*t + 0.5*a*(t*t);
              
    while (d_ini >= 1 || m_speedAllowed <= m_speedTarget){
        v_aux = static_cast<int>(3.6*qSqrt(2*a*d_ini));
        --d_ini;
        if (m_speedAllowedPrevious != m_speedAllowed){
            setAllowedSpeed(v_aux);
        }
    }


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

    if (m_speed == 0.0){
        emit _1AtoB();
    }
    if ((m_speed + m_OS_AFE > m_speedAllowed) || ((m_speed + m_OS_AFE + m_speedCritique > m_speedAllowed)&& m_uTVC)){
        emit _2BtoA();
    }
    if ( ((m_speed + m_OS_LFS <= m_speedAllowed)&& !m_uTVC) || (m_speed + m_OS_LFS + m_speedCritique <= m_speedAllowed) ){
        emit _3BtoC();
    }
    if ( ( m_speed + m_OS_AFS > m_speedAllowed ) || (m_uTVC && ((m_speed + m_OS_AFS + m_speedCritique) > m_speedAllowed)) ){
        emit _4CtoB();
    }
    if ( (m_speed + m_OS_LCT <= m_speedAllowed && !m_uTVC) || (m_speed + m_OS_LCT + m_speedCritique <= m_speedAllowed) ){
        emit _5CtoD();
    }
    if ( (m_speed + m_OS_ACT > m_speedAllowed) || (m_uTVC && (m_speed + m_OS_ACT + m_speedCritique > m_speedAllowed)) ){
        emit _6DtoC();
    }

}

void Atp_Controller::critiqueSpeed(){

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

/************************************************************************************************/
/*
 * Siempre que exista una variación en la Velocidad Objetivo, la Velocidad Permitida
 * podrá sufrir variación.
 * A continuación se describen las diversas transiciones posibles, siendo que el orden sigue la
 * prioridad decreciente. De esta manera, solamente si la primera transición no es identificada es
 * que las transiciones subsiguientes podrán ocurrir.
 */

// Determinar Velocidad Permitida:
// Evaluo si es peldano:
        //Velocidad <= 0.00; || Vobj_ant < Vobj_nueva || [(Vobj_ant >= Vobj_nueva) && (Velocidad <= (Vobj_nueva - 5.00 Km/h))] || [AF_1 -> AF_0 || AF_2 -> AF_0]
                        // ---> Transicion Peldano: Velocidad Permitida = Vobj_nueva

    //Caso Contrario si es gradual por Tiempo:
            // (Vobj_nueva < Vobj_ant) && (Vobj_nueva != AF_1)
                           //  ---> Transicion Gradual por Tiempo (3s ; 0,7 m/s2)

        //Caso Contrario si Transicion Gradual por Distancia
            // (Vobj_nueva < Vobj_ant) && (Vobj_nueva == AF_1)
                           //  ---> Transicion Gradual por Distancia

void Atp_Controller::cmc(double v){

    this->m_view->updateSpeed(speed);

    this->speed = speed;
    double dif = (double)(this->allowedSpeed - this->speed);
    qDebug() << "Atp_Controller::updateSpeed Diferencia speed - allowedSpeed: "<< dif;
    qDebug() << "allowed: " << this->allowedSpeed << "speed: " << this->speed;

    if (this->allowedSpeed <= this->speed){
        emit this->exceededSpeed05();
        qDebug() << "Violacion de velocidad permitida, ATP";
    }

    if (2.0<dif){
        emit this->speedRecovered();
        qDebug() << "emit this->speedRecovered();";
    };
}
