#include "bottomboard.h"
#include "ui_bottomboard.h"

BottomBoard::BottomBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BottomBoard)
{
    ui->setupUi(this);
}

BottomBoard::~BottomBoard()
{
    delete ui;
}
