#include "atp_controller.h"

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp *view, EventHandler *eventHandler)
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
    e_turnOn1->addTransition(this,SIGNAL(signalAnden(int)),e_turnOn2);
    //1.2 --> r1.0
    e_turnOn2->addTransition(e_rolling); //Seria incondicional, ver.
    //r1.0 --> r1.1
    e_rolling->addTransition(this, SIGNAL(exceededSpeed()),e_controlLess2);
    //r1.1 --> r1.2
    e_controlLess2->addTransition(this,SIGNAL(exceededSpeed()),e_controlLess1_5);
    //r1.2 --> r1.3
    e_controlLess1_5->addTransition(this, SIGNAL(exceededSpeed()),e_controlLess1_0);
    //r1.3 --> r1.4
    e_controlLess1_0->addTransition(e_controlLess0_5);
    //r1.4 --> r1.5
    e_controlLess0_5->addTransition(e_breakingTo0);
    //r1.5 --> B0
    e_breakingTo0->addTransition(this,SIGNAL(subteStoped()),e_rolling);


        //Arcos Back:
    e_controlLess2->addTransition(this,SIGNAL(speedRecovered()),e_rolling);
    e_controlLess1_5->addTransition(this,SIGNAL(speedRecovered()),e_rolling);
    e_controlLess1_0->addTransition(this,SIGNAL(speedRecovered()),e_rolling);
    e_breaking0->addTransition(this,SIGNAL(subteStoped()),e_rolling);

    //r2.0 --> r2.1
    //r2.1 --> r2.2
    //r2.2 --> r2.3
    //r2.3 --> Final

        //Transicion Final
    e_rolling->addTransition(this,SIGNAL(reset()),e_Final_State);

        //Acciones:
    connect(e_turnOn0,SIGNAL(entered()),this, SLOT(turnOn0()));
    connect(e_turnOn1,SIGNAL(entered()),this, SLOT(turnOn1()));
    connect(e_turnOn2,SIGNAL(entered()),this, SLOT(turnOn2()));

        //Conexiones del ATP al resto del mundo.
        //Conecciones externas:
    //connect(alguien,SIGNAL(senal salida paltaforma), this, SLOT(initATP()));
    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    connect(subte,SIGNAL(targetSpeedChanged(double)),this,SLOT(updateTargetSpeed(double)));
    connect(this, SIGNAL(cutTraction()),subte,SLOT(cutTraction()));
    connect(this, SIGNAL(enableTraction()),subte,SLOT(enableTraction()));


}

/**********************************************************************************/
    //Acciones, rutinas a realizar en los estados:
//Inicia la maquina de estados, o sea el ATP, deberia estar conectado a la senal salida de Plataforma.
void Atp_Controller::initATP(){
    this->m_machineATP->start();
    qDebug() << "Atp_Controller::initATP ---> ATP iniciado en e_turnOn0";
}

void Atp_Controller::reset(){
    this->m_machineATP->stop();
    qDebug() << "Atp_Controller::reset() ---> ATP machine stop";
}

void Atp_Controller::turnOn0(){
    qDebug() << "Atp_Controller::turnOn0()";
    qDebug() << "Velocidad Objetivo: 0, Blinking";
    qDebug() << "Velocidad Permitida: 15";
    qDebug() << "Timer of 10 second activated";
}

void Atp_Controller::turnOn1(){
    qDebug() << "Atp_Controller::turnOn1()";
    qDebug() << "Atp_Controller::turnOn1 --> C.Traccion ON";
    //Cortar Traccion
    qDebug() << "Velocidad Objetivo: 0";
}

void Atp_Controller::turnOn2(){
    qDebug() << "Atp_Controller::turnOn2()";
    qDebug() << "Atp_Controller::turnOn2 --> C.Traccion OFF";
    qDebug() << "Liberar Corte Traccion";
    qDebug() << "Velocidad Objetivo: 0";
}

void Atp_Controller::rolling(){
    //Actualiza speedReal en ATP widget
    qDebug() << "Atp_Controller::rolling() --> updatedSpeed() ATP";
}

void Atp_Controller::speedExceededLessThan2(){
    //C.T.: ON (blinking)
    qDebug() << "Atp_Controller::speedExceededLessThan2()";
}

void Atp_Controller::speedExceededLessThan1_5(){
    //C.T.: ON
    //emit cutTraction();
    qDebug() << "Atp_Controller::speedExceededLessThan1_5()";
}

void Atp_Controller::speedExceededLessThan1_0(){
    //Freno: ON (blink)
    qDebug() << "Atp_Controller::speedExceededLessThan1_0()";
}

void Atp_Controller::speedExceededLessThan0_5(){
    //Frneo: ON
    //emit enableBreakEmergency();
    qDebug() << "Atp_Controller::speedExceededLessThan0_5()";
}

void Atp_Controller::breakTo0(){
    //Anulacion corte traccion
    //emit enableTraction();

    //Anulacion freno emergencia
    //emit desableBreakEmergency();

    //Apagado luces CTraccion Freno
    qDebug() << "Atp_Controller::breakTo0()";
}

/**********************************************************************************/

void Atp_Controller::updateTargetSpeed(double speed){
    m_view->updateTargetSpeed(speed);
}

void Atp_Controller::updateAllowedSpeed(double speed){
    m_view->updateAllowedSpeed(speed);
}

void Atp_Controller::updateSpeed(double speed){
    //Tiene dos conecciones por lo menos
    //Controla velocidad con permitida y acciona
        //Si todo bien update en vista real speed
        //en else voy a emitir una senal privada cuando no verifique ahi engancho
    m_view->updateSpeed(speed);
}

Atp_Controller::~Atp_Controller(){

}
