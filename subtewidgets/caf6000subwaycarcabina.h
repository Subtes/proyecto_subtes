#ifndef CAF6000SUBWAYCARCABINA_H
#define CAF6000SUBWAYCARCABINA_H

#include <QWidget>

namespace Ui {
class caf6000subwaycarcabina;
}

class caf6000subwaycarcabina : public QWidget
{
    Q_OBJECT

public:
    explicit caf6000subwaycarcabina(QWidget *parent = 0);
    ~caf6000subwaycarcabina();

private:
    Ui::caf6000subwaycarcabina *ui;
};

#endif // CAF6000SUBWAYCARCABINA_H
