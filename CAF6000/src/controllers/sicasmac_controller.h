#ifndef SICASMAC_CONTROLLER_H
#define SICASMAC_CONTROLLER_H
#include "sicasmac.h"
#include "base_controller.h"
#include "QString"
#include "QStringList"
#include "vector"
#include "math.h"
class SicasMac_Controller : public Base_Controller
{
    Q_OBJECT

 private:
    //NOSE SI TENGO QUE GENERAR ACÁ LA MATRIZ!
    SicasMac * m_sicasmac;
    int cantPantallasSicas;
    int renglon;
    int cantCochesTotal;
    int indiceArre;
    int DatosPorCoche;
    int maxRenglonesSicas;
    QStringList pantallasicas ;
    QStringList saveId ;
    int buscoPosicion(QString mensaje);
    void borrarSicas();
    void verificoEstFalla(QString falla, int coche);
    void verificoEstPuertas(QString falla, int coche);
    QStringList separoCaracteres(QString mensaje);
    void bajaMensaje(QString texto);
    void refrescoVista();
    void borrarPantallaSicas();





public:
    SicasMac_Controller(SubteStatus * subte, SicasMac * sicas);
    ~SicasMac_Controller();

public slots:
    void onPressSigRow();
    void onPressAntRow();
    void separoMensajes(QString mensaje);
    void cargoCoches(QString mensajeCoches);
    void frenoRetencionActivado();
};

#endif // SICASMAC_CONTROLLER_H
