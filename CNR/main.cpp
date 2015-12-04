#include "boardcenter.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BoardCenter w;
    w.show();

    return a.exec();
}
