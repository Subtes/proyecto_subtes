#include "atp_controller.h"

Atp_Controller::Atp_Controller(SubteStatus *subte, Atp *view, EventHandler *eventHandler)
{
    this->m_subte = subte;
    this->m_view = view;
    this->m_eventHandler = eventHandler;

    this->speedTarget = 0.0;
    this->speed = 0.0;
    this->allowedSpeed = 0.0;

        //Maquina de Estado ATP, solo version CMC
    this->m_machineATP = new QStateMachine();

        //Estados
    this->e_turnOn0 = new QState();
//    this->e_turnOn1 = new QState();
//    this->e_turnOn2 = new QState();
    this->e_rolling = new QState();
    this->e_controlLess2 = new QState();
    this->e_controlLess1_5 = new QState();
    this->e_controlLess1_0 = new QState();
    this->e_controlLess0_5 = new QState();
    this->e_breakingTo0 = new QState();
//    this->e_breaking0 = new QState();
//    this->e_nearToStation = new QState();
//    this->e_curveBraking = new QState();
//    this->e_nearToPlatform = new QState();
    this->e_setaFired = new QState();

        //Agrego los estados
    this->m_machineATP->addState(this->e_turnOn0);
//    this->m_machineATP->addState(this->e_turnOn1);
//    this->m_machineATP->addState(this->e_turnOn2);
    this->m_machineATP->addState(this->e_rolling);
    this->m_machineATP->addState(this->e_controlLess2);
    this->m_machineATP->addState(this->e_controlLess1_5);
    this->m_machineATP->addState(this->e_controlLess1_0);
    this->m_machineATP->addState(this->e_controlLess0_5);
    this->m_machineATP->addState(this->e_breakingTo0);
//    this->m_machineATP->addState(this->e_breaking0);
//    this->m_machineATP->addState(this->e_nearToStation);
//    this->m_machineATP->addState(this->e_curveBraking);
//    this->m_machineATP->addState(this->e_nearToPlatform);
    this->m_machineATP->addState(this->e_setaFired);

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
    //e_turnOn0->addTransition(t_timerToTurnOn,SIGNAL(timeout()),e_rolling);
    e_turnOn0->addTransition(e_rolling);
    //1.1 --> 1.2
    //e_turnOn1->addTransition(this,SIGNAL(signalAnden()),e_turnOn2);
    //1.2 --> r1.0
    //e_turnOn2->addTransition(this,SIGNAL(enableTraction()),e_rolling);
    //r1.0 --> r1.1
    e_rolling->addTransition(this, SIGNAL(exceededSpeed20()),e_controlLess2);
    e_rolling->addTransition(this, SIGNAL(exceededSpeed15()),e_controlLess1_5);
    e_rolling->addTransition(this, SIGNAL(exceededSpeed10()),e_controlLess1_0);
    e_rolling->addTransition(this, SIGNAL(exceededSpeed05()),e_controlLess0_5);
    e_rolling->addTransition(this, SIGNAL(subteStoped()),e_breakingTo0);

    //e_rolling->addTransition(this, SIGNAL(exceededSpeed05()),e_breakingTo0);
    e_rolling->addTransition(this, SIGNAL(setaFired()),e_setaFired);
    //r1.1 --> r1.2
    e_controlLess2->addTransition(this,SIGNAL(exceededSpeed15()),e_controlLess1_5);
    e_controlLess2->addTransition(this,SIGNAL(exceededSpeed10()),e_controlLess1_0);
    e_controlLess2->addTransition(this,SIGNAL(exceededSpeed05()),e_controlLess0_5);
    e_controlLess2->addTransition(this, SIGNAL(setaFired()),e_setaFired);
    //r1.2 --> r1.3
    e_controlLess1_5->addTransition(this, SIGNAL(exceededSpeed10()),e_controlLess1_0);
    e_controlLess1_5->addTransition(this, SIGNAL(setaFired()),e_setaFired);
    e_controlLess1_5->addTransition(this, SIGNAL(exceededSpeed05()),e_controlLess0_5);
    //r1.3 --> r1.4
    e_controlLess1_0->addTransition(this,SIGNAL(exceededSpeed05()),e_controlLess0_5);
    e_controlLess1_0->addTransition(this, SIGNAL(setaFired()),e_setaFired);
    //r1.4 --> r1.5
    e_controlLess0_5->addTransition(this,SIGNAL(subteStoped()),e_breakingTo0);
    e_controlLess0_5->addTransition(this, SIGNAL(setaFired()),e_setaFired);
    //r1.5 --> B0
    e_breakingTo0->addTransition(e_rolling);
    e_setaFired->addTransition(this,SIGNAL(subteStoped()),e_breakingTo0);

        //Arcos Back:
    e_controlLess2->addTransition(this,SIGNAL(speedRecovered()),e_rolling);
    e_controlLess1_5->addTransition(this,SIGNAL(speedRecovered()),e_rolling);
    e_controlLess1_0->addTransition(this,SIGNAL(speedRecovered()),e_rolling);

//    e_controlLess2->addTransition(this,SIGNAL(speedRecovered()),e_rolling);
//    e_controlLess1_5->addTransition(this,SIGNAL(speedRecovered()),e_rolling);
//    e_controlLess1_0->addTransition(this,SIGNAL(speedRecovered()),e_rolling);


    //r2.0 --> r2.1
    //r2.1 --> r2.2
    //r2.2 --> r2.3
    //r2.3 --> Finalk

        //Transicion Final
    e_rolling->addTransition(this,SIGNAL(reset()),e_Final_State);

        //Acciones:
    connect(e_turnOn0,SIGNAL(entered()),this, SLOT(turnOn0()));
    connect(e_rolling, SIGNAL(entered()),this,SLOT(rolling()));
//    connect(e_turnOn1,SIGNAL(entered()),this, SLOT(turnOn1()));
//    connect(e_turnOn2,SIGNAL(entered()),this, SLOT(turnOn2()));
    connect(e_controlLess2,SIGNAL(entered()),this,SLOT(speedExceededLessThan2()));
    connect(e_controlLess1_5,SIGNAL(entered()),this,SLOT(speedExceededLessThan1_5()));
    connect(e_controlLess1_0,SIGNAL(entered()),this,SLOT(speedExceededLessThan1_0()));
    connect(e_controlLess0_5,SIGNAL(entered()),this,SLOT(speedExceededLessThan0_5()));
    connect(e_breakingTo0,SIGNAL(entered()),this,SLOT(breakTo0()));
    connect(e_setaFired,SIGNAL(entered()),this,SLOT(setaFiredRoutine()));

        //Conexiones del ATP al resto del mundo.
        //Conecciones externas:
    connect(subte,SIGNAL(speedChanged(double)),this,SLOT(updateSpeed(double)));
    connect(subte,SIGNAL(targetSpeedChanged(double)),this,SLOT(updateTargetSpeed(double)));
    //connect(subte,SIGNAL(setaFired()),this,SIGNAL(setaFiredRoutine()));
    connect(this, SIGNAL(cutTraction()),subte,SLOT(cutTraction()));
    connect(this, SIGNAL(enableTraction()),subte,SLOT(enableTraction()));
    connect(this, SIGNAL(enableBreakEmergency()),subte,SLOT(emergencyBrakeActived()));
    connect(this, SIGNAL(desableBreakEmergency()),subte,SLOT(emergencyBrakeReleased()));
    connect(eventHandler,SIGNAL(kPressed()),this,SLOT(initATP()));
    connect(eventHandler,SIGNAL(lPressed()),this,SLOT(resetATP()));
    connect(eventHandler,SIGNAL(iCambioSenial1()),SIGNAL(signalAnden()));
    connect(eventHandler,SIGNAL(frenoEstDes()),SIGNAL(enableTraction()));


}

/**********************************************************************************/
    //Acciones, rutinas a realizar en los estados:
//Inicia la maquina de estados, o sea el ATP, deberia estar conectado a la senal salida de Plataforma.
void Atp_Controller::initATP(){
//    if (this->m_machineATP->isRunning()){
//        this->resetATP();
//    }
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
//    this->m_view->setCMC(false);
//    this->m_view->setCorte(false);
//    this->m_view->setCorteBlink(false);
//    this->m_view->setFrenoUrg(false);
//    this->m_view->setFrenoUrgBlink(false);
    qDebug() << "Atp_Controller::resetATP() ---> ATP machine stop";
}

void Atp_Controller::turnOn0(){
    qDebug() << "Atp_Controller::turnOn0()";
    this->m_view->setCMC(true);
    this->enableTraction();
    if (this->speedTarget >= 1.0){
        //this->m_view->updateTargetSpeed(this->speedTarget);
        qDebug() << "velocidad updateSpeedTarget paso 0 inicio ATP recibida" << this->speedTarget;
        this->updateTargetSpeed(this->speedTarget);
    } else{
        this->updateTargetSpeed(0.0);
    }

    //this->m_view->updateAllowedSpeed(15.0);
    this->t_timerToTurnOn->start();
    qDebug() << "Velocidad Objetivo: 0, Blinking";
    qDebug() << "Velocidad Permitida: 15";
    qDebug() << "Timer of 10 second activated";
}

void Atp_Controller::turnOn1(){
    qDebug() << "Atp_Controller::turnOn1()";
    qDebug() << "Atp_Controller::turnOn1 --> C.Traccion ON";
    this->m_view->setCorte(true);
    //Cortar Traccion
    qDebug() << "Corte traccion... ";
    emit this->cutTraction();
    qDebug() << "Velocidad Objetivo: 0";
    this->m_view->updateTargetSpeed(0.0);
}

void Atp_Controller::turnOn2(){
    qDebug() << "Atp_Controller::turnOn2()";
    qDebug() << "Atp_Controller::turnOn2 --> C.Traccion OFF";
    this->m_view->setCorte(false);
    qDebug() << "Liberar Corte Traccion";
    emit this->enableTraction();
    qDebug() << "Velocidad Objetivo: 0";
    this->m_view->updateTargetSpeed(0.0);

}

void Atp_Controller::rolling(){
    //Actualiza speedReal en ATP widget
    qDebug() << "Atp_Controller::rolling() --> updatedSpeed() ATP";
    this->m_view->setCorte(false);
    this->m_view->setCorteBlink(false);
    this->m_view->setFrenoUrg(false);
    this->m_view->setFrenoUrgBlink(false);
}

void Atp_Controller::resetViewState(){
    //Actualiza speedReal en ATP widget
    this->m_view->setCorte(false);
    this->m_view->setCorteBlink(false);
    this->m_view->setFrenoUrg(false);
    this->m_view->setFrenoUrgBlink(false);
}

void Atp_Controller::speedExceededLessThan2(){
    //C.T.: ON (blinking)
    this->m_view->setCorte(false);
    this->m_view->setCorteBlink(true);
    this->m_view->setFrenoUrg(false);
    this->m_view->setFrenoUrgBlink(false);
    qDebug() << "Atp_Controller::speedExceededLessThan2()";
}

void Atp_Controller::speedExceededLessThan1_5(){
    //C.T.: ON
    this->m_view->setFrenoUrg(false);
    this->m_view->setFrenoUrgBlink(false);
    this->m_view->setCorteBlink(false);
    this->m_view->setCorte(true);

    emit cutTraction();
    qDebug() << "Atp_Controller::speedExceededLessThan1_5()";
}

void Atp_Controller::speedExceededLessThan1_0(){
    //Freno: ON (blink)
    this->m_view->setCorteBlink(false);
    this->m_view->setCorte(true);
    this->m_view->setFrenoUrgBlink(true);
    this->m_view->setFrenoUrg(false);
    qDebug() << "Atp_Controller::speedExceededLessThan1_0()";
}

void Atp_Controller::speedExceededLessThan0_5(){
    //Frneo: ON
    this->m_view->setCorte(true);
    this->m_view->setCorteBlink(false);
    this->m_view->setFrenoUrg(true);
    this->m_view->setFrenoUrgBlink(false);
    emit enableBreakEmergency();
    qDebug() << "Atp_Controller::speedExceededLessThan0_5()";
}

void Atp_Controller::breakTo0(){
    //Anulacion corte traccion
    emit enableTraction();

    //Anulacion freno emergencia
//    emit desableBreakEmergency();

    //Apagado luces CTraccion Freno
    qDebug() << "Atp_Controller::breakTo0()";
//    this->m_view->setFrenoUrg(false);
//    this->m_view->setCorte(false);
    this->m_view->updateTargetSpeed(this->speedTarget);
}

void Atp_Controller::setaFiredRoutine(){
        this->m_view->setCorte(false);
        this->m_view->setFrenoUrgBlink(false);
        this->m_view->setFrenoUrg(true);
        qDebug()<<"Atp_Controller::setaFired()"<<"--> setFalse to Corte, FreUrgBlink";
}

/**********************************************************************************/

void Atp_Controller::updateTargetSpeed(double speed){
//    m_view->setCorteBlink(true);
//    m_view->setFrenoUrgBlink(true);
//    m_view->setFservBlink(true);
//    m_view->updateTargetSpeed(57);
//    m_view->setBlinkSpeedTarget(true);
    this->m_view->updateTargetSpeed(speed);

    this->speedTarget = speed;
    this->updateAllowedSpeed(speed*0.9);
}

void Atp_Controller::updateAllowedSpeed(double speed){
    this->m_view->updateAllowedSpeed(speed);

    this->allowedSpeed = speed;
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

    if (this->allowedSpeed <= this->speed){
        emit this->exceededSpeed05();
        qDebug() << "Violacion de velocidad permitida, ATP";
    }

    if (2.0<dif){
        emit this->speedRecovered();
        qDebug() << "emit this->speedRecovered();";
    };
    if (1.5<dif && dif<=2.0){
        emit this->exceededSpeed20();
        qDebug()<< "emit this->exceededSpeed20();";
    };
    if (1.0<dif && dif<=1.5){
        emit this->exceededSpeed15();
        qDebug()<<"emit this->exceededSpeed15();";
    };
    if (0.5<dif && dif<=1.0){
        emit this->exceededSpeed10();
        qDebug()<<"emit this->exceededSpeed10();";
    };
    if (dif<=0.5){
        //break
        emit this->exceededSpeed05();
        qDebug()<<"emit this->exceededSpeed05();";
    };

    if ((-0.1<speed && speed<=0.01)){
        emit this->subteStoped();
        qDebug()<<"emit this->subteStoped();";
    };

 //    if (5.0<dif){
//        emit this->speedRecovered();
//        qDebug() << "emit this->speedRecovered();";
//    };
//    if (3.5<dif && dif<=5.0){
//        emit this->exceededSpeed20();
//        qDebug()<< "emit this->exceededSpeed20();";
//    };
//    if (2.5<dif && dif<=3.5){
//        emit this->exceededSpeed15();
//        qDebug()<<"emit this->exceededSpeed15();";
//    };
//    if (1.5<dif && dif<=2.5){
//        emit this->exceededSpeed10();
//        qDebug()<<"emit this->exceededSpeed10();";
//    };
//    if (0.0<dif && dif<=1.5){
//        //break
//        emit this->exceededSpeed05();
//        qDebug()<<"emit this->exceededSpeed05();";
//    };

//    if ((-0.1<speed && speed<=0.0)){
//        emit this->subteStoped();
//        qDebug()<<"emit this->subteStoped();";
//    };

}

Atp_Controller::~Atp_Controller(){

}

