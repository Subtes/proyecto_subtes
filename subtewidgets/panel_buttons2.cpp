#include "panel_buttons2.h"
#include "ui_panel_buttons2.h"

Panel_Buttons2::Panel_Buttons2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_Buttons2)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
}

Panel_Buttons2::~Panel_Buttons2()
{
    delete ui;
}
