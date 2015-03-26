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

        connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SIGNAL(valueChanged(int)));
}

TractionLever::~TractionLever()
{
    delete ui;
}
