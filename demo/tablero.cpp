#include "tablero.h"
#include "ui_tablero.h"

Tablero::Tablero(QWidget *parent, SubteStatus *subte) :
    QMainWindow(parent),
    ui(new Ui::Tablero)
{
    if (subte==NULL){
        subte = new SubteStatus(0,false,false);
    }

    m_subte = subte;

    ui->setupUi(this);

    setStyleSheet("\
        QWidget {background-image: url(:/resources/BKG_tablero.png);}\
        QSlider::handle {width: 80px; height: 80px; image: url(:/resources/palanca.png); }\
        QSlider::groove {border: 0px solid black; border-radius: 3px; width: 100px; };\
        QDial::handle { image: url(:/resources/BKG_tablero.png); };");

    Doors_Controller * doors = new Doors_Controller(m_subte,ui->panel_buttons3_left,ui->panel_buttons3_right, ui->dial);

    SpeedGauge_Controller * speedGauge = new SpeedGauge_Controller(m_subte,ui->speedGauge);

    TractionLever_Controller * tractionLever = new TractionLever_Controller(m_subte,ui->traction);
}

Tablero::~Tablero()
{
    delete ui;
}
