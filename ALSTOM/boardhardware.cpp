#include "boardhardware.h"
#include "ui_boardhardware.h"

BoardHardware::BoardHardware(QWidget *parent, SubteState *subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardHardware)
{
    ui->setupUi(this);

    TractionController * traction = new TractionController(subte,ui->tractionWidget,ui->ranaWidget);
}

BoardHardware::~BoardHardware()
{
    delete ui;
}
