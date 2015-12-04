#ifndef SWITCHMULTIPOINT_H
#define SWITCHMULTIPOINT_H

#include <QWidget>
#include <QQuickItem>

namespace Ui {
class SwitchMultiPoint;
}

class SwitchMultiPoint : public QWidget
{
    Q_OBJECT

public:
    explicit SwitchMultiPoint(QWidget *parent = 0);
    ~SwitchMultiPoint();

private:    
    Ui::SwitchMultiPoint *ui;
    QQuickItem *m_qml = NULL;
};

#endif // SWITCHMULTIPOINT_H
