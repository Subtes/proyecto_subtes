#include "atp.h"
#include "ui_atp.h"

Atp::Atp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Atp)
{
    ui->setupUi(this);

    ui->atp_quickWidget->setClearColor(Qt::transparent);
    ui->atp_quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);

    this->m_qmlView = ui->atp_quickWidget->rootObject();
}

Atp::~Atp()
{
    delete ui;
}
