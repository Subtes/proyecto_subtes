#ifndef HOMBREVIVOHOMBREMUERTO_CONTROLLER_H
#define HOMBREVIVOHOMBREMUERTO_CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QState>
#include <QFinalState>
#include <QStateMachine>

#include "panel_buttons2.h"

/**
 * @brief The HombreVivoHombreMuerto_Controller class
 *
 * Esta clase es el controlador para manejar el dispositivo Hombre Vivo Hombre Muerto
 * Esta asociada a una vista de 2 botones. El soporte de vistas esta otorgado por
 * Panel_Buttons2.h que encapsula una vista realizada en QML design.
 *
 *  void on_Button1();
 *  void on_Button2();
 *  void off_Button1();
 *  void off_Button2();
 */

    class HombreVivoHombreMuerto_Controller : public QObject
    {
        Q_OBJECT

    public:

        HombreVivoHombreMuerto_Controller(Panel_Buttons2 *view);
        ~HombreVivoHombreMuerto_Controller();
        void on_HombreMuertoSystem();
        void off_HombreMuertoSystem();

    signals:
        void on_ClickButton1();
        void on_ClickButton2();

    private slots:
        void on_routineWarn();
        void on_routineSafe();
        void do_routineDied();

    private:

        //Vista asociada
        Panel_Buttons2 *m_panel_HombreVivoHombreMuerto = NULL;

        //Maquina de Estados
        QState *m_state_safe = NULL;
        QState *m_state_warn = NULL;
        QFinalState *m_state_final = NULL;
        QStateMachine *m_machine_HombreMuerto = NULL;

        //Timer's
        QTimer *m_timer_died = NULL;
        QTimer *m_timer_safe = NULL;

};

#endif // HOMBREVIVOHOMBREMUERTO_CONTROLLER_H
