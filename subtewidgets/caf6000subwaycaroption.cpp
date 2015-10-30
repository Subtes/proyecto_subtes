#include "caf6000subwaycaroption.h"
#include "ui_caf6000subwaycaroption.h"

caf6000subwaycaroption::caf6000subwaycaroption(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caf6000subwaycaroption)
{
    ui->setupUi(this);
}

caf6000subwaycaroption::~caf6000subwaycaroption()
{
    delete ui;
}
