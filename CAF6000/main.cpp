#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"
#include "src/models/subtestatus.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SubteStatus * subte = new SubteStatus();

    //BoardCenter * c = new BoardCenter(0,subte);;
    //c->show();

    BoardHardware *h = new BoardHardware(0,subte);
    h->show();

    //BoardLeft *l = new BoardLeft(0,subte);
    //l->show();

    //BoardRight *r = new BoardRight(0,subte);
    //r->show();

    return a.exec();
}
