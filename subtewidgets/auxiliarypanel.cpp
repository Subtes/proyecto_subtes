#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonArray>

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

    QString f("CAF6000-MM-MM-MM");
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
//    qDebug()<<"Selected option"<< s;

//    ui->qkW_N2->setSource(QUrl("qrc:/CAF6000-N2-PANEL-4"));
//    m_qmlView2 = ui->qkW_N2->rootObject();

//    //QObject *imageprop = m_qmlView2->findChild<QObject*>("upname");

//    //imageprop->setProperty("source","qrc:/resources/blue.png");

//    connect (m_qmlView2,SIGNAL(selected(QString)),this,SLOT(level3(QString)));

//    qDebug()<<"entro nivel 2";

QFile source;
if (source.exists("://CONFIG-CAF6000-23")){
    qDebug()<<"EXISTE Archivo!!!!!!!!";
    source.setFileName("://CONFIG-CAF6000-23");
}else{
        qDebug()<<"NOOOOOOO EXISTE Archivo!!!!!!!!";
}
    QJsonParseError jerror;
    if (!source.open(QIODevice::ReadOnly)){
        qDebug()<<"No se pudo abrir el archivo";
    }else{
        qDebug()<<"Abrio archivo";
    }
    QJsonDocument jdoc= QJsonDocument::fromJson(source.readAll(),&jerror);
    if(jerror.error != QJsonParseError::NoError){
        qDebug()<<"Error en parseo de archivo Json configuracion Trenes";
        source.close();
        return;
    }
    QJsonObject obj = jdoc.object();
    QString configuracion = obj["configuracion"].toString();
    qDebug()<<"Recurso"<< configuracion;

        if(configuracion.isEmpty()){
            qDebug()<<"Configuracion vacia";
            return;
        }

    QJsonArray coches = obj["coches"].toArray();
    QString numero,tipo;
    qDebug()<<"Antes del FOR";

        //int coche=1;
        for(auto&& item: coches)
        {
            const QJsonObject& coche = item.toObject();
            numero = coche["numero"].toString();
            tipo = coche["tipo"].toString();
            qDebug() << "Numero y tipo de Coche: " << numero <<"--" << tipo;
        }
    source.close();
}

/**
 * @brief AuxiliaryPanel::level3
 * @param op, segun la opcion elejida (B1..B4) busca y carga el recurso asociado.
 * No precisaria buscar en json, el onclick devolveria el nombre (Alias) del recurso,
 * asociado para cargar el qml.
 * Finalmente agregar un SLOT para devolver resultado. Ver seria.
 */
void AuxiliaryPanel::level3(QString op)
{
    if (op == "B1;button1Image" ){
        ui->qkW_N3->setSource(QUrl("qrc:/CAF6000-N3-TERMICAS"));
    }
    m_qmlView3 = ui->qkW_N3->rootObject();
    connect (m_qmlView3,SIGNAL(selected(QString)),this,SLOT(optionSelected(QString)));
    qDebug()<<"entro nivel 3 " << op;
}

void AuxiliaryPanel::optionSelected(QString op){
    qDebug()<<"option selected from panel auxiliary: "<< op;
}

AuxiliaryPanel::~AuxiliaryPanel()
{
    delete ui;
}
