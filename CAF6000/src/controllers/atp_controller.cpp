#include "atp_controller.h"

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp * view, EventHandler *eventHandler)
{
    this->m_subte = subte;
    this->m_view = view;
    this->m_eventHandler = eventHandler;

    //Maquina de Estado ATP, solo version CMC
    this->m_machineATP = new QStateMachine();

    //Estados
    this->e_turnOn0 = new QState();
    this->e_turnOn1 = new QState();
    this->e_turnOn2 = new QState();
    this->e_rolling = new QState();
    this->e_controlLess2 = new QState();
    this->e_controlLess1_5 = new QState();
    this->e_controlLess1_0 = new QState();
    this->e_controlLess0_5 = new QState();
    this->e_breakingTo0 = new QState();
    this->e_breaking0 = new QState();
    this->e_nearToStation = new QState();
    this->e_curveBraking = new QState();
    this->e_nearToPlatform = new QState();

    //Agrego los estados
    this->m_machineATP->addState(this->e_turnOn0);
    this->m_machineATP->addState(this->e_turnOn1);
    this->m_machineATP->addState(this->e_turnOn2);
    this->m_machineATP->addState(this->e_rolling);
    this->m_machineATP->addState(this->e_controlLess2);
    this->m_machineATP->addState(this->e_controlLess1_5);
    this->m_machineATP->addState(this->e_controlLess1_0);
    this->m_machineATP->addState(this->e_controlLess0_5);
    this->m_machineATP->addState(this->e_breakingTo0);
    this->m_machineATP->addState(this->e_breaking0);
    this->m_machineATP->addState(this->e_nearToStation);
    this->m_machineATP->addState(this->e_curveBraking);
    this->m_machineATP->addState(this->e_nearToPlatform);

    //Estado Final
    this->e_Final_State = new QFinalState();

    //Creo los Timer
    this->t_reactionMotorMan = new QTimer(this->e_nearToStation);
    this->t_timerToTurnOn = new QTimer(this->e_turnOn0);

    //Seteo los timer
    this->t_reactionMotorMan->setInterval(5000);
    this->t_timerToTurnOn->setInterval(10000);

    //Seteamos estado inicial
    this->m_machineATP->setInitialState(this->e_turnOn0);

        //Transiciones
    //1.0 --> 1.1
    e_turnOn0->addTransition(t_timerToTurnOn,SIGNAL(timeout()),e_turnOn1);
    //1.1 --> 1.2
    e_turnOn1->addTransition(m_subte,SIGNAL(targetSpeedChanged(double)),e_turnOn2);
    //1.2 --> r1.0
    e_turnOn2->addTransition(e_rolling); //Seria incondicional, ver.
    //r1.0 --> r1.1
    //SEGUIR con e_rolling
    //r1.1 --> r1.2
    //r1.2 --> r1.3
    //r1.4 --> r1.5
    //r1.0 --> r2.0
    //r2.1 --> r2.2
    //r2.2 --> r2.3
    //r2.3 --> Final

    //Transicion Final

    //Acciones:
//    connect(e_turnOn0,SIGNAL(entered()),this, turnOn0());
//    connect(e_turnOn1,SIGNAL(entered()),this, turnOn1());
//    connect(e_turnOn2,SIGNAL(entered()),this, turnOn2());

    //Conecciones externas:
    //connect(alguien,SIGNAL(senal salida paltaforma), this, SLOT(initATP()));
    //Las conecciones a continuacion ya no irian. Sirven si no quiero el ATP.
    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    connect(subte,SIGNAL(targetSpeedChanged(double)),this,SLOT(updateTargetSpeed(double)));

}

    //Acciones, rutinas a realizar en los estados:
void Atp_Controller::turnOn0(){

    qDebug() << "Velocidad Objetivo: 0, Blinking";
    qDebug() << "Velocidad Permitida: 15";
    qDebug() << "Timer of 10 second activated";
}

void Atp_Controller::turnOn1(){

    qDebug() << "Atp_Controller::turnOn1 --> C.Traccion ON";
    //Cortar Traccion
    qDebug() << "Velocidad Objetivo: 0";
}

void Atp_Controller::turnOn2(){

    qDebug() << "Atp_Controller::turnOn2 --> C.Traccion OFF";
    qDebug() << "Liberar Corte Traccion";
    qDebug() << "Velocidad Objetivo: 0";
}

void Atp_Controller::rolling(){
//Tiene dos conecciones por lo menos
//Contrla velocidad con permitida y acciona seguir....
    //en else voy a emitir una senal privada cuando no verifique ahi engancho
}

//Inicia la maquina de estados, o sea el ATP, deberia estar conectado a la senal salida de Plataforma.
void Atp_Controller::initATP(){
    this->m_machineATP->start();
    qDebug() << "Atp_Controller::initATP ---> ATP iniciado en e_turnOn0";
}

void Atp_Controller::speedExceededLessThan2(){

}

void Atp_Controller::updateTargetSpeed(double speed){
    m_view->updateTargetSpeed(speed);
}

void Atp_Controller::updateAllowedSpeed(double speed){
    m_view->updateAllowedSpeed(speed);
}

void Atp_Controller::updateSpeed(double speed){
    m_view->updateSpeed(speed);
}

Atp_Controller::~Atp_Controller(){

}

