#include "rana.h"
#include "ui_rana.h"
#include <QtDebug>

Rana::Rana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Rana)
{
    ui->setupUi(this);
    setStyleSheet("\
        QSlider::handle {width: 80px; height: 80px; image: url(:/resources/palanca.png); }\
        QSlider::groove {border: 0px solid black; border-radius: 3px; width: 100px; };");

    connect (ui->rana_slider,SIGNAL(valueChanged(int)),this,SLOT(processValueChanged(int)));
}

void Rana::processValueChanged(int pos){

    switch ( pos ) {
    case 1:
            emit ranaCERO();
            qDebug() << "emitiendo rana UNO";
      break;
    case 0:
            emit ranaAD();
            qDebug() << "emitiendo rana CERO";
      break;
    case -1:
            emit ranaAT();
            qDebug() << "emitiendo rana MENOS UNO";
      break;
    default:
        qDebug() << "Error: Rana value DEVICE" << pos;
      break;
    }

}

Rana::~Rana()
{
    delete ui;
}
