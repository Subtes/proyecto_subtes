#ifndef VELOCIMETRO_H
#define VELOCIMETRO_H

#include <QWidget>

namespace Ui {
class Velocimetro;
}

class Velocimetro : public QWidget
{
    Q_OBJECT

public:
    explicit Velocimetro(QWidget *parent = 0);
    ~Velocimetro();

private:
    Ui::Velocimetro *ui;
};

#endif // VELOCIMETRO_H
