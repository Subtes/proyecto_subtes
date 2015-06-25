#ifndef ATP_H
#define ATP_H

#include <QWidget>
#include <QQuickItem>

namespace Ui {
class Atp;
}

class Atp : public QWidget
{
    Q_OBJECT

public:
    explicit Atp(QWidget *parent = 0);
    ~Atp();

public slots:
    void updateTargetSpeed(double speed);
    void updateAllowedSpeed(double speed);
    void updateSpeed(double speed);
    void setCMC(bool);
    void setCL(bool);
    void setFserv(bool);
    void setFrenoUrg(bool);
    void setCorte(bool);
    void setFalla(bool);

private:
    Ui::Atp *ui;
    QQuickItem * m_qmlView;
};

#endif // ATP_H
