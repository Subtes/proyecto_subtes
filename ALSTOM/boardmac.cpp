#include "boardmac.h"
#include "ui_boardmac.h"

BoardMac::BoardMac(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardMac)
{
    ui->setupUi(this);
}

BoardMac::~BoardMac()
{
    delete ui;
}
