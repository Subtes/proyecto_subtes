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

public slots:
    void updateTargetSpeed(double speed);
    void updateAllowedSpeed(double speed);
    void updateSpeed(double speed);
    void setaFiredRoutine();
    //Inicia la maquina de estados, por ahora es siempre CMC primer Estado.
    void initATP();
    void resetATP();

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

private:
    Atp *m_view = NULL;
    SubteStatus *m_subte = NULL;
    EventHandler *m_eventHandler = NULL;

    double speedTarget;
    double speed;
    double allowedSpeed;

    //Maquina de estados:
      //Estados:
    //Estado Arranque 1.0
    QState *e_turnOn0 = NULL;
    //Estado Arranque 1.1
    QState *e_turnOn1 = NULL;
    //Estado Arranque 1.2
    QState *e_turnOn2 = NULL;
    //Estado En Recorrido, Subte operando
    QState *e_rolling = NULL;
    //Estado Diferencia Speed - Allowed < 2
    QState *e_controlLess2 = NULL;
    //Estado Diferencia Speed - Allowed < 1,5
    QState *e_controlLess1_5 = NULL;
    //Estado Diferencia Speed - Allowed < 1,0
    QState *e_controlLess1_0 = NULL;
    //Estado Diferencia Speed - Allowed < 0,5
    QState *e_controlLess0_5 = NULL;
    //Estado Frenando a cero disparo por Allowed - Speed > 3
    QState *e_breakingTo0 = NULL;
    //Estado Frenado=0, libero corte traccion y freno
    QState *e_breaking0 = NULL;
    //Proximidad Anden 383 mts
    QState *e_nearToStation = NULL;
    //Curva frenado, se frena el tren a cero segun curva.
    QState *e_curveBraking = NULL;
    //Parado, proximidad al anden, circulacion 15 maximo Target=0
    QState *e_nearToPlatform = NULL;
    //Estado seta disparado
    QState *e_setaFired = NULL;

        //Estado Final:
    QFinalState *e_Final_State = NULL;

        //Maquina de Estados:
    QStateMachine *m_machineATP = NULL;

        //Timer's:
    //Timer arranque para dar lugar al arranque en plataforma
    QTimer *t_timerToTurnOn = NULL;
    //Timer configurado en tiempo de raccion del motor man y los sistemas
    QTimer *t_reactionMotorMan = NULL;


};

#endif // ATP_CONTROLLER_H
