#include "switchmultipoint.h"
#include "ui_switchmultipoint.h"
#include <QDebug>

SwitchMultiPoint::SwitchMultiPoint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SwitchMultiPoint)
{
    ui->setupUi(this);

    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);

    m_qml = ui->quickWidget->rootObject();

    connect(m_qml,SIGNAL(onPressPos(int)),this,SIGNAL(onPressPosSwitch(int)));

}

SwitchMultiPoint::~SwitchMultiPoint()
{
    delete ui;
}

void SwitchMultiPoint::setSize(QSize size)
{
   // ui->switchMP->resize(size);
}

void SwitchMultiPoint::setONMouseArea(QString pos)
{
   QObject *switch_i = m_qml->findChild<QObject*>(pos,Qt::FindChildrenRecursively);

   qDebug() << "QUE POSICION LLEGA: "<< pos;
   qDebug() << switch_i->objectName();
   switch_i->setProperty("enabled",true);

}

