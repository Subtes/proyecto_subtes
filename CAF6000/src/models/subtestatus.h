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
    void wiperOn();
    void wiperOff();
    void washer();
};

#endif // SUBTESTATUS_H
