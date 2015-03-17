#ifndef BOTONERA2_H
#define BOTONERA2_H

#include <QWidget>

namespace Ui {
class Botonera2;
}

class Botonera2 : public QWidget
{
    Q_OBJECT

public:
    explicit Botonera2(QWidget *parent = 0);
    ~Botonera2();

private:
    Ui::Botonera2 *ui;
};

#endif // BOTONERA2_H
