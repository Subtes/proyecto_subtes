#include "instructionpanel.h"
#include "ui_instructionpanel.h"

InstructionPanel::InstructionPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionPanel)
{
    ui->setupUi(this);
}

InstructionPanel::~InstructionPanel()
{
    delete ui;
}
