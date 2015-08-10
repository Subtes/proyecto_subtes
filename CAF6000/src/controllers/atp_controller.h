#ifndef ATP_CONTROLLER_H
#define ATP_CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QState>
#include <QFinalState>
#include <QStateMachine>

#include <atp.h>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"


/**
 * @brief The Atp_Controller class
 */

class Atp_Controller : public QObject
{
    Q_OBJECT

public:

    Atp_Controller (SubteStatus *model, Atp *view, EventHandler *eventHandler);
    ~Atp_Controller();

signals:
    void enableBreakEmergency();
    void desableBreakEmergency();
    void cutTraction();
    void enableTraction();
    void speedRecovered();
    void subteStoped();
    void signalAnden();
    void exceededSpeed20();
    void exceededSpeed15();
    void exceededSpeed10();
    void exceededSpeed05();
    void setaFired();
    void reset();

    void _1AtoB();
    void _2BtoA();
    void _3BtoC();
    void _4CtoB();
    void _5CtoD();
    void _6DtoC();


public slots:
    void updateTargetSpeed(double speed);
    void updateAllowedSpeed(double speed);
    void updateSpeed(double speed);
    void setaFiredRoutine();
    //Inicia la maquina de estados, por ahora es siempre CMC primer Estado.
    void initATP();
    void resetATP();

    void onATP();
    void offATP();

private slots:
    void turnOn0();
    void turnOn1();
    void turnOn2();
    void rolling();
    void speedExceededLessThan2();
    void speedExceededLessThan1_5();
    void speedExceededLessThan1_0();
    void speedExceededLessThan0_5();
    void breakTo0();
    void resetViewState();

    void routingA();
    void routingB();
    void routingC();
    void routingD();

private:
    Atp *m_view = NULL;
    SubteStatus *m_subte = NULL;
    EventHandler *m_eventHandler = NULL;

    double speedTarget;
    double speed;
    double allowedSpeed;

    //Maquina de estados:
        //Estados:
    QState *e_A = NULL;
    QState *e_B = NULL;
    QState *e_C = NULL;
    QState *e_D = NULL;

        //Estado Final:
    QFinalState *e_Final_State = NULL;

        //Maquina de Estados:
    QStateMachine *m_machineATP = NULL;

        //Timer's:
//    //Timer arranque para dar lugar al arranque en plataforma
//    QTimer *t_timerToTurnOn = NULL;
//    //Timer configurado en tiempo de raccion del motor man y los sistemas
//    QTimer *t_reactionMotorMan = NULL;


};

#endif // ATP_CONTROLLER_H
