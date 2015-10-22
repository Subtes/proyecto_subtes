#include "boardatp.h"
#include "ui_boardatp.h"

BoardAtp::BoardAtp(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardAtp)
{
    ui->setupUi(this);
}

BoardAtp::~BoardAtp()
{
    delete ui;
}
