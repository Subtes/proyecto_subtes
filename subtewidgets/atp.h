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

private:
    Ui::Atp *ui;
    QQuickItem * m_qmlView;
};

#endif // ATP_H
