#ifndef CAF6000SUBWAYCARSALON_H
#define CAF6000SUBWAYCARSALON_H

#include <QWidget>

namespace Ui {
class caf6000subwaycarsalon;
}

class caf6000subwaycarsalon : public QWidget
{
    Q_OBJECT

public:
    explicit caf6000subwaycarsalon(QWidget *parent = 0);
    ~caf6000subwaycarsalon();

private:
    Ui::caf6000subwaycarsalon *ui;
};

#endif // CAF6000SUBWAYCARSALON_H
