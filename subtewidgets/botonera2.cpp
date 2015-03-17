#include "botonera2.h"
#include "ui_botonera2.h"

Botonera2::Botonera2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Botonera2)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
}

Botonera2::~Botonera2()
{
    delete ui;
}
