#include "boardmac.h"
#include "ui_boardmac.h"


BoardMac::BoardMac(QWidget *parent, SubteState * subte, EventHandler *eventHandler) :
    BaseBoard(parent,subte,eventHandler),
    ui(new Ui::BoardMac)

{
    ui->setupUi(this);
    qDebug()<<"2";
    m_alstomtcms = new AlstomTcms_Controller(m_subte,ui->widget); //widget sería alstomTCMS cambiar!

    qDebug()<<"4";

}

BoardMac::~BoardMac()
{
    delete ui;
}
