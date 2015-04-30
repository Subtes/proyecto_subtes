#include <QApplication>
#include "tablero.h"
#include "src/models/subtestatus.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SubteStatus * subte = new SubteStatus(0,false,false);

    SimulacionSubteFisica *simulacionSubteFisica = new SimulacionSubteFisica(subte);

    Dispatcher *dispatcher = new Dispatcher(simulacionSubteFisica,subte);

    Tablero *tablero= new Tablero(0,subte);
    tablero->show();
    return a.exec();
}

