#ifndef CAF6000SUBWAYCARGRIFOS_H
#define CAF6000SUBWAYCARGRIFOS_H

#include <QWidget>

namespace Ui {
class caf6000subwaycargrifos;
}

class caf6000subwaycargrifos : public QWidget
{
    Q_OBJECT

public:
    explicit caf6000subwaycargrifos(QWidget *parent = 0);
    ~caf6000subwaycargrifos();

private:
    Ui::caf6000subwaycargrifos *ui;
};

#endif // CAF6000SUBWAYCARGRIFOS_H
