#include "speedgauge.h"
#include "ui_speedgauge.h"

SpeedGauge::SpeedGauge(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SpeedGauge)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
}

SpeedGauge::~SpeedGauge()
{
    delete ui;
}
