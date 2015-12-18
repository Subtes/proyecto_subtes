#include "boardhardware.h"
#include "ui_boardhardware.h"

BoardHardware::BoardHardware(QWidget *parent, SubteState *subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardHardware)
{
    ui->setupUi(this);
    QSize size;
    size.setHeight(90);
    size.setWidth(90);

    ui->hablar->setSize(size);
    ui->hablar->setButtonImage(QUrl("qrc:/resources/alstom_yellowsmall_on.png"),QUrl("qrc:/resources/alstom_yellowsmall.png"));
    ui->hablar->setOnPressAsDriver();

    m_traction = new TractionController(subte,ui->tractionWidget,ui->ranaWidget);
    m_hongo = new HongoEmergenciaController(m_subte,ui->hongo);
    m_llaveSeguridad = new LlavaSeguridadController(m_subte,ui->llaveSeguridad);

}

BoardHardware::~BoardHardware()
{
    delete ui;
}
