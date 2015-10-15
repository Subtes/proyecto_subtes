#include "boardbottom.h"
#include "ui_boardbottom.h"

BoardBottom::BoardBottom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardBottom)
{
    ui->setupUi(this);
}

BoardBottom::~BoardBottom()
{
    delete ui;
}
