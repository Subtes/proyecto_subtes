#ifndef ATP_CONTROLLER_H
#define ATP_CONTROLLER_H

#include <QObject>
#include "atp.h"
#include "src/models/subtestatus.h"

class Atp_Controller : public QObject
{
    Q_OBJECT

public:
    Atp_Controller(SubteStatus *subte, Atp * view);
    ~Atp_Controller();

private:
    Atp * m_view;
    SubteStatus *m_subte;
};

#endif // ATP_CONTROLLER_H
