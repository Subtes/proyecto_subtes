#include "auxiliarypanel.h"
#include "ui_auxiliarypanel.h"

AuxiliaryPanel::AuxiliaryPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuxiliaryPanel)
{
    ui->setupUi(this);
}

AuxiliaryPanel::~AuxiliaryPanel()
{
    delete ui;
}
