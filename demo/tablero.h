#ifndef TABLERO_H
#define TABLERO_H

#include <QMainWindow>
#include "Panel_Button2.h"
#include "src/models/subtestatus.h"
#include "src/controllers/doors_controller.h"
#include "src/controllers/speedgauge_controller.h"
#include "src/controllers/hombrevivohombremuerto_controller.h"
#include "src/controllers/tractionlever_controller.h"
#include "src/controllers/seta_controller.h"

#include "dispatcher.h"
#include "simulacionsubtefisica.h"

namespace Ui {
class Tablero;
}

class Tablero : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tablero(QWidget *parent = 0, SubteStatus *subte = 0);
    ~Tablero();

private slots:
    void activateHombreVivoHombreMuerto(int pos = 0);

private:
    Ui::Tablero *ui;
    SubteStatus *m_subte;
    HombreVivoHombreMuerto_Controller *m_deviceHombreVivoHombreMuerto = NULL;
    Seta_Controller *m_deviceSetaController = NULL;

};

#endif // TABLERO_H
