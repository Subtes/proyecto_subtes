#ifndef SUBTESTATUS_H
#define SUBTESTATUS_H
#include <QObject>
#include <QDebug>

class SubteStatus : public QObject
{
    Q_OBJECT

public:
    SubteStatus();
    ~SubteStatus();

private:
    bool horn;

public slots:
    void hornOn();
    void hornOff();

};

#endif // SUBTESTATUS_H
