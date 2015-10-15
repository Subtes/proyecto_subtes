#include "boardcenter.h"
#include "ui_boardcenter.h"

BoardCenter::BoardCenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardCenter)
{
    ui->setupUi(this);
}

BoardCenter::~BoardCenter()
{
    delete ui;
}
