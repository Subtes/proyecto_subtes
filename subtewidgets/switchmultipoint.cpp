#include "switchmultipoint.h"
#include "ui_switchmultipoint.h"

SwitchMultiPoint::SwitchMultiPoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchMultiPoint)
{
    ui->setupUi(this);

    m_qml = ui->quickWidget->rootObject();

    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);

}

SwitchMultiPoint::~SwitchMultiPoint()
{
    delete ui;
}
