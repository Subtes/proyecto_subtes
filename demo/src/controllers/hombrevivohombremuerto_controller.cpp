#include "hombrevivohombremuerto_controller.h"
#include "panel_buttons2.h"


HombreVivoHombreMuerto_Controller::HombreVivoHombreMuerto_Controller(Panel_Buttons2 *viewButtons2)
{
    this->m_panel_HombreVivoHombreMuerto = viewButtons2;

    //Creo la Maquina de Estado
    this->m_machine_HombreMuerto = new QStateMachine();
    this->m_state_warn = new QState();
    this->m_state_safe = new QState();
    this->m_state_final = new QFinalState();

    //Agregro los estados
    this->m_machine_HombreMuerto->addState(m_state_warn);
    this->m_machine_HombreMuerto->addState(m_state_safe);
    this->m_machine_HombreMuerto->addState(m_state_final);

    //Creo los timer
    this->m_timer_died = new QTimer(m_state_warn);
    this->m_timer_safe = new QTimer(m_state_safe);

    //Configuro los timer
    //HH Va con un random
    this->m_timer_died->setInterval(5000);
    this->m_timer_safe->setInterval(3000);

    //Conexiones SIGNAL-SLOTS
    QObject::connect(m_state_safe,SIGNAL(entered()),this,SLOT(on_routineSafe()));
    QObject::connect(m_state_warn,SIGNAL(entered()),m_timer_died,SLOT(start()));
    QObject::connect(m_state_final,SIGNAL(entered()),this,SLOT(do_routineDied()));

    //Prender Rojo
    QObject::connect(m_timer_safe,SIGNAL(timeout()),this, SLOT(on_routineWarn()));//Prender Rojo

    //Transiciones
    m_state_safe->addTransition(m_timer_safe,SIGNAL(timeout()),m_state_warn);
    m_state_warn->addTransition(m_timer_died,SIGNAL(timeout()),m_state_final);
    m_state_warn->addTransition(this->m_panel_HombreVivoHombreMuerto,SIGNAL(on_ClickButton1()),m_state_safe);

    //Set Inicial state
    this->m_machine_HombreMuerto->setInitialState(this->m_state_safe);

}

void HombreVivoHombreMuerto_Controller::on_HombreMuertoSystem(){

    this->m_machine_HombreMuerto->start();
    this->m_panel_HombreVivoHombreMuerto->enable_Button1(false);
    this->m_panel_HombreVivoHombreMuerto->enable_Button2(false);
}

void HombreVivoHombreMuerto_Controller::off_HombreMuertoSystem(){

    this->m_machine_HombreMuerto->stop();
    this->m_timer_died->stop();
    this->m_timer_safe->stop();
    this->m_panel_HombreVivoHombreMuerto->trigger_Alarm(false);
    this->m_panel_HombreVivoHombreMuerto->enable_Button1(false);
    this->m_panel_HombreVivoHombreMuerto->enable_Button2(false);
    this->m_panel_HombreVivoHombreMuerto->off_Button1();
    this->m_panel_HombreVivoHombreMuerto->off_Button2();
}

void HombreVivoHombreMuerto_Controller::on_routineSafe(){

    this->m_panel_HombreVivoHombreMuerto->enable_Button1(false);
    this->m_panel_HombreVivoHombreMuerto->on_Button1();
    this->m_panel_HombreVivoHombreMuerto->off_Button2();
    this->m_timer_safe->start();
}

void HombreVivoHombreMuerto_Controller::on_routineWarn(){

    this->m_panel_HombreVivoHombreMuerto->enable_Button1(true);
    this->m_panel_HombreVivoHombreMuerto->on_Button2();
}


void HombreVivoHombreMuerto_Controller::do_routineDied(){

    this->m_machine_HombreMuerto->stop();
    this->m_panel_HombreVivoHombreMuerto->trigger_Alarm(true);
    this->m_panel_HombreVivoHombreMuerto->enable_Button1(false);
}


HombreVivoHombreMuerto_Controller::~HombreVivoHombreMuerto_Controller()
{
    delete this->m_timer_died;
    delete this->m_timer_safe;
    delete this->m_state_final;
    delete this->m_state_safe;
    delete this->m_state_warn;
    delete this->m_machine_HombreMuerto;
}

