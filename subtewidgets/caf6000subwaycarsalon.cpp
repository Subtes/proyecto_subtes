#include "caf6000subwaycarsalon.h"
#include "ui_caf6000subwaycarsalon.h"

caf6000subwaycarsalon::caf6000subwaycarsalon(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caf6000subwaycarsalon)
{
    ui->setupUi(this);
}

caf6000subwaycarsalon::~caf6000subwaycarsalon()
{
    delete ui;
}
