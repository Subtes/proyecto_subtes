#ifndef ALSTOMTCMS_H
#define ALSTOMTCMS_H

#include <QWidget>
#include <QQuickItem>

namespace Ui {
class AlstomTcms;
}

class AlstomTcms : public QWidget
{
    Q_OBJECT

public:
    explicit AlstomTcms(QWidget *parent = 0);
    ~AlstomTcms();
    void setMinMaxValue(int maxV, int minV);
    void setMaxAngle(int angle);
    void setOffsetAngle(int angle);

protected:
    Ui::AlstomTcms *ui;
    QQuickItem *m_qmlView;

public slots:
    void updateNeedle(double value);
    void updateDigitalVelocity(double speed);
    void updateDigitalVoltimetroRight(double voltR);
    void updateDigitalVoltimetroLeft(double voltL);
    void updateDigitalAmperimetro(double amper);
};

#endif // ALSTOMTCMS_H
