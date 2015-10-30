#include "caf6000subwaycartermicas.h"
#include "ui_caf6000subwaycartermicas.h"

caf6000subwaycartermicas::caf6000subwaycartermicas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caf6000subwaycartermicas)
{
    ui->setupUi(this);
}

caf6000subwaycartermicas::~caf6000subwaycartermicas()
{
    delete ui;
}
