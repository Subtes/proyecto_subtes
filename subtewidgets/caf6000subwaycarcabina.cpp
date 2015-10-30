#include "caf6000subwaycarcabina.h"
#include "ui_caf6000subwaycarcabina.h"

caf6000subwaycarcabina::caf6000subwaycarcabina(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::caf6000subwaycarcabina)
{
    ui->setupUi(this);
}

caf6000subwaycarcabina::~caf6000subwaycarcabina()
{
    delete ui;
}
