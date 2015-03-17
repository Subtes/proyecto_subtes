#include "palancaslider.h"
#include "ui_palancaslider.h"

PalancaSlider::PalancaSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PalancaSlider)
{
    ui->setupUi(this);
    setStyleSheet("\
        QSlider::handle {width: 80px; height: 80px; image: url(:/resources/palanca.png); }\
        QSlider::groove {border: 0px solid black; border-radius: 3px; width: 100px; };");
}

PalancaSlider::~PalancaSlider()
{
    delete ui;
}
