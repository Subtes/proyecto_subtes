#ifndef SICASMAC_CONTROLLER_H
#define SICASMAC_CONTROLLER_H
#include "sicasmac.h"
#include "base_controller.h"
#include "QString"
#include "QStringList"

class SicasMac_Controller : public Base_Controller
{
    Q_OBJECT

 private:
    //NOSE SI TENGO QUE GENERAR ACÁ LA MATRIZ!
    SicasMac * m_sicasmac;
    int renglon;
    QString pantallasicas [];
    void moverArriba(int var,int fin);
    void bajaMensajes(QString mensaje);

public:
    SicasMac_Controller(SubteStatus * subte, SicasMac * sicas);
    ~SicasMac_Controller();

public slots:
    void separoMensajes(QString mensaje);
};

#endif // SICASMAC_CONTROLLER_H
