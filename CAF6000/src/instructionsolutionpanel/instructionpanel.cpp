#include "instructionpanel.h"
#include "ui_instructionpanel.h"

InstructionPanel::InstructionPanel(QWidget *parent, SubteStatus *subte, EventHandler *eventHandler) :
    QWidget(parent),
    ui(new Ui::InstructionPanel)
{
    ui->setupUi(this);

    m_subte = subte;
    m_eventhandler = eventHandler;

    connect (m_eventhandler,SIGNAL(kPressed()),this,SLOT(nivel1()));

    //connect (m_qmlView,SIGNAL(pedalReleased()),this,SIGNAL(hornReleased()));

}

InstructionPanel::~InstructionPanel()
{
    delete ui;
}

void InstructionPanel::nivel1()
{
    ui->n1->setSource(QUrl("qrc:/foot_horn.qml"));
   /* ui->n1->setClearColor(Qt::transparent);
    ui->n1->setAttribute(Qt::WA_AlwaysStackOnTop);*/

    m_qmlView1 = ui->n1->rootObject();
    connect (m_qmlView1,SIGNAL(pedalPressed(int)),this,SLOT(nivel2(int)));

    qDebug()<<"entro nivel 1";

}

void InstructionPanel::nivel2(int v)
{
    ui->n2->setSource(QUrl("qrc:/foot_horn.qml"));    

    m_qmlView2 = ui->n2->rootObject();    

    QObject *imageprop = m_qmlView2->findChild<QObject*>("upname");

    imageprop->setProperty("source","qrc:/resources/blue.png");

    connect (m_qmlView2,SIGNAL(pedalPressed(int)),this,SLOT(nivel3(int)));
    qDebug()<<"entro nivel 2";

}

void InstructionPanel::nivel3(int v)
{
    if (v == 0){
    ui->n3->setSource(QUrl("qrc:/foot_horn.qml"));
    /*ui->n3->setClearColor(Qt::transparent);
    ui->n3->setAttribute(Qt::WA_AlwaysStackOnTop);*/
    }
    m_qmlView3 = ui->n3->rootObject();
    qDebug()<<"entro nivel 3 " << v;

}
