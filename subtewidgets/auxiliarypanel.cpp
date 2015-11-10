#include "auxiliarypanel.h"
#include "ui_auxiliarypanel.h"

AuxiliaryPanel::AuxiliaryPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuxiliaryPanel)
{
    ui->setupUi(this);
}

/**
 * @brief AuxiliaryPanel::level1, estoy partiendo de una configuracion que deberia
 * llegar como parametro (agregar parametro QString), por ejemplo, llegaria MM-MM-MM,
 * entonces deberia buscar un archivo con el nombre CAF6000_23. Con este archivo, lee
 * el tipo de formacion MM-MM-MM, entonces asigna el recurso qml con ese nombre.
 */
void AuxiliaryPanel::level1()
{
    //Buscar en un json la configuracion, en realidad esta primera parte ya la conozco.
    //Agregar Assertion por si llega un nombre no esperado;

    QString f("MM-MM-MM");
    f.insert(0,"qrc:/");

    ui->qkW_N1->setSource(QUrl(f));

    m_qmlView1 = ui->qkW_N1->rootObject();

    connect(m_qmlView1,SIGNAL(selected(QString)),this,SLOT(level2(QString)));

    qDebug()<<"Entro en Nivel 1";
}

/**
 * @brief AuxiliaryPanel::level2
 * @param s
 * recibe en s el coche (Ci), con ese busca en el archivo(json), 4 recursos, cada uno
 * asociado a un boton, B1..B4, y lo carga (Nivel 2)
 */
void AuxiliaryPanel::level2(QString s)
{
    qDebug()<<"Selected option"<< s;

    ui->qkW_N2->setSource(QUrl("qrc:/foot_horn.qml"));
    m_qmlView2 = ui->qkW_N2->rootObject();

    QObject *imageprop = m_qmlView2->findChild<QObject*>("upname");

    imageprop->setProperty("source","qrc:/resources/blue.png");

    connect (m_qmlView2,SIGNAL(pedalPressed(int)),this,SLOT(level3(int)));

    qDebug()<<"entro nivel 2";
}

/**
 * @brief AuxiliaryPanel::level3
 * @param op, segun la opcion elejida (B1..B4) busca y carga el recurso asociado.
 * No precisaria buscar en json, el onclick devolveria el nombre (Alias) del recurso,
 * asociado para cargar el qml.
 * Finalmente agregar un SLOT para devolver resultado. Ver seria.
 */
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
