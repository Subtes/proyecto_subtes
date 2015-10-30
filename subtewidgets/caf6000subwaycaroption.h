#ifndef CAF6000SUBWAYCAROPTION_H
#define CAF6000SUBWAYCAROPTION_H

#include <QWidget>

namespace Ui {
class caf6000subwaycaroption;
}

class caf6000subwaycaroption : public QWidget
{
    Q_OBJECT

public:
    explicit caf6000subwaycaroption(QWidget *parent = 0);
    ~caf6000subwaycaroption();

private:
    Ui::caf6000subwaycaroption *ui;
};

#endif // CAF6000SUBWAYCAROPTION_H
