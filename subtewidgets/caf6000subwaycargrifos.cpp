#include "caf6000subwaycargrifos.h"
#include "ui_caf6000subwaycargrifos.h"

caf6000subwaycargrifos::caf6000subwaycargrifos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caf6000subwaycargrifos)
{
    ui->setupUi(this);
}

caf6000subwaycargrifos::~caf6000subwaycargrifos()
{
    delete ui;
}
