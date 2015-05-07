#ifndef SETA_CONTROLLER_H
#define SETA_CONTROLLER_H

#include <QObject>
#include <QVariant>

#include "seta_button.h"
#include "src/models/subtestatus.h"

/**
 * @brief The Seta_Controller class
 *
 */

class Seta_Controller : public QObject
{
    Q_OBJECT

public:
    Seta_Controller(SubteStatus *modelo, Seta_Button *view);
    ~Seta_Controller();

    QVariant isPressed();

signals:
    void setaActivate();
    void setaDeactivated();

private slots:
    //Acction launched from item ui
    void pushSeta();
    void pullSeta();

private:
    //State of Seta
    //QVariant m_activated;
    Seta_Button *m_setaButton = NULL;

};

#endif // SETA_CONTROLLER_H
