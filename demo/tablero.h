#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include "Panel_Button2.h"
#include "src/controllers/doors_controller.h"
#include "src/controllers/speedgauge_controller.h"
#include "src/controllers/hombrevivohombremuerto_controller.h"

namespace Ui {
class Tablero;
}

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = 0);
    ~Tablero();

private slots:
    void activateHombreVivoHombreMuerto(int pos = 0);

private:
    Ui::Tablero *ui = NULL;
    HombreVivoHombreMuerto_Controller *m_deviceHombreVivoHombreMuerto = NULL;
};

#endif // TABLERO_H
