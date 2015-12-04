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

    void setSize(QSize size);    
    void setONMouseArea(QString pos);

private:
    Ui::SwitchMultiPoint *ui;
    QQuickItem *m_qml = NULL;

signals:
    onPressPosSwitch(int);
};

#endif // SWITCHMULTIPOINT_H
