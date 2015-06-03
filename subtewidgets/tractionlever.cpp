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
    //TODO: REVISAR POR QUE FALLA ?????
    //qDebug() << "VALUE " << value;
    //double proportional = 0;
    if(value > 15){
        //proportional = (value-15)/85;
        //qDebug() << "PROPORTIONAL " << proportional;
        //emit traction((int)(proportional*100));
        emit traction(value);
    }else if((value <= 15)&&(value >= -15)){
        emit zero();
    }else if ((value < -15) && (value >= -90)){
        //proportional = (value-15)/85;
        //qDebug() << "PROPORTIONAL " << proportional;
        //emit traction((int)(proportional*100));
        emit traction(value);
    }else if (value < -95){
        emit emergencyBrake();
    }
}
