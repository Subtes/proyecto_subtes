#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    BoardCenter c;
    c.show();

    BoardHardware h;
    h.show();

    BoardLeft l;
    l.show();

    BoardRight r;
    r.show();

    return a.exec();
}
