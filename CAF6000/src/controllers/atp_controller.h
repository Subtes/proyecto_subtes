#ifndef ATP_CONTROLLER_H
#define ATP_CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QState>
#include <QFinalState>
#include <QStateMachine>
#include <QString>

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

    void allowedSpeedChange(double);
    void targetSpeedChange(double);

public slots:
    void updateTargetSpeed(double speed);
    void updateAllowedSpeed(double speed);
    void updateSpeed(double speed);
    //void setaFiredRoutine();
    void setDrivingMode(int);
    //Inicia la maquina de estados, por ahora es siempre CMC primer Estado.
    void initATP();
    void resetATP();

    void onATP();
    void offATP();

    void setSpeedTarget(double s);

private slots:
//    void turnOn0();
//    void turnOn1();
//    void turnOn2();
//    void rolling();
//    void speedExceededLessThan2();
//    void speedExceededLessThan1_5();
//    void speedExceededLessThan1_0();
//    void speedExceededLessThan0_5();
//    void breakTo0();
//    void resetViewState();

    void routingA();
    void routingB();
    void routingC();
    void routingD();
    void cmc(double v);

    void setAllowedSpeed(double s);
    void transitionGT();

private:
    Atp *m_view = NULL;
    SubteStatus *m_subte = NULL;
    EventHandler *m_eventHandler = NULL;

    double speedTarget;
    double speed;
    double allowedSpeed;

    double m_speed;
    double m_speedPrevious;

    double m_speedTarget;
    double m_speedTargetPrevious;

    double m_speedAllowed;
    double m_speedAllowedPrevious;

    //Tasa desaceleracion
    double m_A1 = 0.7;

    //Atraso de freno
    double m_A_freno;

    //Grade maximo de la via
    double m_Gm;

    //Tada de la curva de reduccion de codigo
    double m_Tc;

    //Jerk de frenado
    double m_Jerk;

    //Speed Critique
    double m_speedCritique;

    //Driving Mode
    bool m_drivingModeCMC;
    bool m_drivingModeCL;
    bool m_drivingModeAL;
    bool m_drivingModeAT;

    //Target Signal
    double m_AF_0 = 0;
    double m_AF_1 = 15;
    double m_AF_2 = 15;
    double m_AF_3 = 25;
    double m_AF_4 = 30;
    double m_AF_5 = 40;
    double m_AF_6 = 50;
    double m_AF_7 = 60;

    //Target Signal Recived
    QString m_AF;
    QString m_AF_previous;

    //Instant Acceleration
    double m_ACE;

    //Offset
    double m_OS_ACT;
    double m_OS_LCT;
    double m_OS_AFS;
    double m_OS_LFS;
    double m_OS_AFE;

    //uTVC (inhabilitado, curva, constante).
    int m_uTVC;

    //Maquina de estados:
        //Estados:
    QState *m_e_A = NULL;
    QState *m_e_B = NULL;
    QState *m_e_C = NULL;
    QState *m_e_D = NULL;

        //Estado Final:
    QFinalState *m_e_Final_State = NULL;

        //Maquina de Estados:
    QStateMachine *m_machineATP = NULL;

        //Timer's:
    //Timer arranque para dar lugar al arranque en plataforma
    QTimer *t_timerToTurnOn = NULL;
    //Timer configurado en tiempo de raccion del motor man y los sistemas
    QTimer *t_reactionMotorMan = NULL;
    //Timer T1 tiempo de la Transicion Gradual por Tiempo
    QTimer *m_t_TGT = NULL;

    void set_uTVC();
    void transitionGD();
    void superviseSpeed();
    void critiqueSpeed();

};

#endif // ATP_CONTROLLER_H
