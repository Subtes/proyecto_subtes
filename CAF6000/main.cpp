#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"
#include "boardtop.h"

#include "src/models/subtestatus.h"

#include <QApplication>
#include <ENetClient.h>
#include <string>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SubteStatus * subte = new SubteStatus();

    BoardHardware *h = new BoardHardware(0,subte);
    h->showFullScreen();

    BoardCenter * c = new BoardCenter(0,subte);;
    c->showFullScreen();

    BoardLeft *l = new BoardLeft(0,subte);
    l->showFullScreen();

    BoardRight *r = new BoardRight(0,subte);
    r->showFullScreen();

    BoardTop *t = new BoardTop(0,subte);
    t->showFullScreen();

    ENetClient *ElCliente = new ENetClient();
    ElCliente->Conectar("127.0.0.1", 5000, "ClienteCPP");
    ElCliente->ColocarMiNombre("ClienteCPP");
    ElCliente->CambiarValorClave("clave", "valor");
    ElCliente->Suscribirse("ClienteCPP","clave");
    return a.exec();
}

//void ClientCambioValClave(std::string unHost, std::string unaClave, std::string unValor)
//{
//  qDebug() << "\nNuevo Valor desde el Host: " << String(unHost) << " de la Clave " << String(unaClave) << " y el Valor es: " << String(unValor);
//}
