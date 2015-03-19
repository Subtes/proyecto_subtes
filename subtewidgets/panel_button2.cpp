#include "Panel_Button2.h"
#include "ui_Panel_Button2.h"

Panel_Button2::Panel_Button2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_Button2)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
}

Panel_Button2::~Panel_Button2()
{
    delete ui;
}
