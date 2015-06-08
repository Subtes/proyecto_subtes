#include "splash.h"
#include "ui_splash.h"

Splash::Splash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Splash)
{
    ui->setupUi(this);
}

Splash::~Splash()
{
    delete ui;
}
