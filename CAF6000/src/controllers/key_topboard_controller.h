#ifndef KEY_TOPBOARD_CONTROLLER_H
#define KEY_TOPBOARD_CONTROLLER_H

#include <QObject>
#include <QVariant>

#include "llavetecho.h"
#include "src/models/subtestatus.h"

class Key_TopBoard_Controller : public QObject
{
    Q_OBJECT

public:
    Key_TopBoard_Controller(SubteStatus *modelo, LlaveTecho *view);
    ~Key_TopBoard_Controller();
    void resetToOff();
    QVariant isON();

    void keyTurnON();
    void keyTurnOFF();

signals:
    void keyActivated();
    void keyDeactivated();

public slots:
    //Acction launched from item ui
    void keyON();
    void keyOFF();

private:
    //State of KeyTopBoard
    LlaveTecho *m_keyButton = NULL;
    SubteStatus *m_modelo = NULL;
};

#endif // KEY_TOPBOARD_CONTROLLER_H
