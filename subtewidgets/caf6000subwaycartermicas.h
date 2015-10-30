#ifndef CAF6000SUBWAYCARTERMICAS_H
#define CAF6000SUBWAYCARTERMICAS_H

#include <QWidget>

namespace Ui {
class caf6000subwaycartermicas;
}

class caf6000subwaycartermicas : public QWidget
{
    Q_OBJECT

public:
    explicit caf6000subwaycartermicas(QWidget *parent = 0);
    ~caf6000subwaycartermicas();

private:
    Ui::caf6000subwaycartermicas *ui;
};

#endif // CAF6000SUBWAYCARTERMICAS_H
