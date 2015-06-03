#ifndef RANA_CONTROLLER_H
#define RANA_CONTROLLER_H

#include <QObject>
#include <rana.h>
#include "src/models/subtestatus.h"

class Rana_Controller : public QObject
{
    Q_OBJECT

public:
    Rana_Controller(SubteStatus *modelo, Rana *vista);
    ~Rana_Controller();
    void setValue(int v);

private:
    Rana *m_ranaTraction;
    SubteStatus *m_subte;
};

#endif // RANA_CONTROLLER_H
