#ifndef FAILURES_CONTROLLER_H
#define FAILURES_CONTROLLER_H

#include <QObject>
#include "src/models/subtestatus.h"

class SubteStatus;
class EventHandler;

class Failures_Controller : public QObject
{
    Q_OBJECT

private:
    SubteStatus *m_subte;
    std::string m_lastFailure;

    bool inFailure();
    void resolveFailure(std::string f);

public:
    Failures_Controller(SubteStatus *subte);
    ~Failures_Controller();

public slots:
    void setFailure(std::string f);
};

#endif // FAILURES_CONTROLLER_H
