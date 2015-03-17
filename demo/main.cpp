#include <QApplication>
#include "tablero.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Tablero tablero;
    tablero.show();

    return a.exec();
}

