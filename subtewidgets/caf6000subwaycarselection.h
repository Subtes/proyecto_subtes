#ifndef CAF6000SUBWAYCARSELECTION_H
#define CAF6000SUBWAYCARSELECTION_H

#include <QWidget>

namespace Ui {
class caf6000subwaycarselection;
}

class caf6000subwaycarselection : public QWidget
{
    Q_OBJECT

public:
    explicit caf6000subwaycarselection(QWidget *parent = 0);
    ~caf6000subwaycarselection();

private:
    Ui::caf6000subwaycarselection *ui;
};

#endif // CAF6000SUBWAYCARSELECTION_H
