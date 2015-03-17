#ifndef BOTONERA3_H
#define BOTONERA3_H

#include <QWidget>

namespace Ui {
class Botonera3;
}

class Botonera3 : public QWidget
{
    Q_OBJECT

public:
    explicit Botonera3(QWidget *parent = 0);
    ~Botonera3();

private:
    Ui::Botonera3 *ui;
};

#endif // BOTONERA3_H
