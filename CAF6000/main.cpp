#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"
#include "boardtop.h"

#include "src/models/subtestatus.h"

#include <QApplication>
#include <ENetClient.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SubteStatus * subte = new SubteStatus();

    BoardHardware *h = new BoardHardware(0,subte);
    //h->showFullScreen();
    //h->show();

    BoardCenter * c = new BoardCenter(0,subte);;
    //c->showFullScreen();
    c->show();

    BoardLeft *l = new BoardLeft(0,subte);
    //l->showFullScreen();
    //l->show();

    BoardRight *r = new BoardRight(0,subte);
    //r->showFullScreen();
    //r->show();

    BoardTop *t = new BoardTop(0,subte);
    //t->showFullScreen();
    t->show();

    return a.exec();
}
