#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{
    ui->setupUi(this);

    setStyleSheet("\
        QWidget {background-image: url(:/resources/BKG_tablero.png);}\
        QSlider::handle {width: 80px; height: 80px; image: url(:/resources/palanca.png); }\
        QSlider::groove {border: 0px solid black; border-radius: 3px; width: 100px; };\
        QDial::handle { image: url(:/resources/BKG_tablero.png); };");

}

Tablero::~Tablero()
{
    delete ui;
}
