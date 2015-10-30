#include "caf6000subwaycarselection.h"
#include "ui_caf6000subwaycarselection.h"

caf6000subwaycarselection::caf6000subwaycarselection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caf6000subwaycarselection)
{
    ui->setupUi(this);
}

caf6000subwaycarselection::~caf6000subwaycarselection()
{
    delete ui;
}
