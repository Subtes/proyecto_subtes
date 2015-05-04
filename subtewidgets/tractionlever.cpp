#include "tractionlever.h"
#include "ui_tractionlever.h"

TractionLever::TractionLever(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TractionLever)
{
    ui->setupUi(this);
    setStyleSheet("\
        QSlider::handle {width: 80px; height: 80px; image: url(:/resources/palanca.png); }\
        QSlider::groove {border: 0px solid black; border-radius: 3px; width: 100px; };");

    connect (ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(processValueChanged(int)));
}

TractionLever::~TractionLever()
{
    delete ui;
}

void TractionLever::processValueChanged(int value){
    if(value > 4){
        emit traction(value -4);
    }else if((value <= 4)&&(value >= -4)){
        emit zero();
    } else if ((value < -4) && (value >= -8)){
        emit brake(value*(-1)-4);
    } else if (value < -8){
        emit emergencyBrake();
    }
}
