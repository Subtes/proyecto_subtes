#ifndef BASE_CONTROLLER_H
#define BASE_CONTROLLER_H

#include <QObject>
#include "src/models/subtestate.h"

class Base_Controller : public QObject
{
    Q_OBJECT

public:
    Base_Controller(SubteState *subte);
    ~Base_Controller();

protected:
    SubteState *m_subte;
};

#endif // BASE_CONTROLLER_H
