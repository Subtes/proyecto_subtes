#ifndef ALSTOMTCMS_CONTROLLER_H
#define ALSTOMTCMS_CONTROLLER_H
#include "base_controller.h"
#include "alstomtcms.h"


class AlstomTcms_Controller : public Base_Controller
{
    Q_OBJECT

private:
    AlstomTcms * m_alstomtcms;
    int cantwagons;
    int doorsXwagon;
    int abrir_puertas;
    int cerrar_puertas;

    void recorridoDePuertas_1Der_2Izq(QString state);
    void recorridoDePuertas_1Izq_2Der(QString state);

public:
    AlstomTcms_Controller(SubteState * subte, AlstomTcms * tcms);
    ~AlstomTcms_Controller();
    void verificoEstPuertas(QString estado, int cantPuertas);
    void recorridoPuertasVagon(QString stateDoors);



public slots:
    void updateNeedle(double velocity);
    void updateDigitalVelocity(double velocity);
    void updateDigitalVoltimetroLeft(double voltL);
    void updateDigitalVoltimetroRight(double voltR);
    void updateDigitalAmperimetro(double amper);
    void logicaPuertas(bool b);

};

#endif // ALSTOMTCMS_CONTROLLER_H
