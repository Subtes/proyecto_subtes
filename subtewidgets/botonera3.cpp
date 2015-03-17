#include "botonera3.h"
#include "ui_botonera3.h"

Botonera3::Botonera3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Botonera3)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
}

Botonera3::~Botonera3()
{
    delete ui;
}
