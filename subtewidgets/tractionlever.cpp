#include "tractionlever.h"
#include "ui_tractionlever.h"
#include <QDebug>

TractionLever::TractionLever(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TractionLever)
{
    ui->setupUi(this);

    connect (ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(processValueChanged(int)));
    connect (ui->verticalSlider,SIGNAL(valueChanged(int)),this,SIGNAL(positionChanged(int)));
    connect (ui->verticalSlider,SIGNAL(sliderPressed()),this,SIGNAL(hvPressed()));
    connect (ui->verticalSlider,SIGNAL(sliderReleased()),this,SIGNAL(hvReleased()));
}

void TractionLever::setValue(int v)
{
    ui->verticalSlider->setValue(v);
}

TractionLever::~TractionLever()
{
    delete ui;
}

void TractionLever::processValueChanged(int value){
    if(value > 15){
        double a = static_cast<int>((((double)value-15.0)/85.0)*100.0);
        emit traction(a);
    }else if((value <= 15)&&(value >= -15)){
        emit zero();
    }else if ((value < -15) && (value >= -95)){
        traction(static_cast<int>((((double)value+15.0)/80.0)*100.0));
        emit traction(value);
    }else if (value < -95){
        emit emergencyBrake();
    }
}
