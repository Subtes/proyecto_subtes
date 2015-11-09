#include "auxiliarypanel.h"
#include "ui_auxiliarypanel.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

AuxiliaryPanel::AuxiliaryPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuxiliaryPanel)
{
    ui->setupUi(this);
}

void AuxiliaryPanel::level1()
{
     ui->qkW_N1->setSource(QUrl("qrc:/foot_horn.qml"));
     m_qmlView1 = ui->qkW_N1->rootObject();
     connect(m_qmlView1,SIGNAL(pedalPressed(int)),this,SLOT(level2(int)));
     LOG(INFO)<<"Entro en Nivel 1";
     qDebug()<<"Entro en Nivel 1";
}

void AuxiliaryPanel::level2(int op)
{
    ui->qkW_N2->setSource(QUrl("qrc:/foot_horn.qml"));

    m_qmlView2 = ui->qkW_N2->rootObject();

    QObject *imageprop = m_qmlView2->findChild<QObject*>("upname");

    imageprop->setProperty("source","qrc:/resources/blue.png");

    connect (m_qmlView2,SIGNAL(pedalPressed(int)),this,SLOT(level3(int)));
    LOG(INFO)<<"Entro en Nivel 2";
    qDebug()<<"entro nivel 2";
}

void AuxiliaryPanel::level3(int op)
{
    if (op == 0){
        ui->qkW_N3->setSource(QUrl("qrc:/foot_horn.qml"));
    }
    m_qmlView3 = ui->qkW_N3->rootObject();
    qDebug()<<"entro nivel 3 " << op;
}

AuxiliaryPanel::~AuxiliaryPanel()
{
    delete ui;
}
