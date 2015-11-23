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
    //Archivo config, contiene el nombre del recurso asociado para cada Subte.
    m_config = "://SUBWAY-CONFIGS";
    m_wagonSelected = "DEFAULT";
}

/**
 * @brief AuxiliaryPanel::level1, estoy partiendo de una configuracion que deberia
 * llegar como parametro (agregar parametro QString), por ejemplo, llegaria CAF6000-MM-MM-MM,
 * entonces deberia buscar un archivo con el nombre CAF6000_23. Con este archivo, lee
 * el tipo de formacion MM-MM-MM, entonces asigna el recurso qml con ese nombre.
 * Debe instanciar en una variable privada la opcion llegada, asi se utiliza en los
 * niveles proximos (N2).
 * .././Source/config/SUBTES-PanelesAuxiliares.json
 * key: modelo y configuracion instanciado en el ejercicio
 * value: nombre del recurso asociado a esa key. El recurso contiene toda la descripcion de
 * la config en un json.
 * {
 *   "CAF6000-M-M-M-M-M-M": "://CONFIG-CAF6000-23",
 *   "CAF6000-M-R-M-M-R-M": null
 * }
 */
bool AuxiliaryPanel::level1(QString configSubway)
{
    /**
     * Buscar en un json el nombre del archivo con la configuracion para el modelo
     * llegado por parametro.
     */
    QJsonDocument jdoc;
    QJsonParseError jerror;
    QJsonObject obj;

    qDebug()<<"Comienzo en NIVEL 1: ";

    //Si existe el archivo de configuraciones de Subtes
    if (m_subways.exists(m_config)){
        qDebug()<< "Archivo de Configuracion encontrado: "<< m_config;
        m_subways.setFileName(m_config);

        if (!m_subways.open(QIODevice::ReadOnly)){
            qDebug()<<"No se pudo abrir el archivo de configuracion: "<< m_subways.fileName();
            return false;
        }else{
            qDebug()<<"Abrio archivo "<<m_subways.fileName()<<" de configuracion de paneles axuliares OK";
        }

        jdoc= QJsonDocument::fromJson(m_subways.readAll(),&jerror);

        if(jerror.error != QJsonParseError::NoError){
            qDebug()<<"Error en parseo de archivo Json de Subtes y sus configuraciones asociadas:... "<< m_subways.fileName();
            m_subways.close();
            return false;
        }

        obj = jdoc.object();
        if (!obj.contains(configSubway)){
            qDebug()<<"Archivo de configuracion "<<m_subways.fileName()<< " no contiene Clave: "<< configSubway;
            m_subways.close();
            return false;
        }

        QJsonValue configModel = obj[configSubway];
        if (configModel.isUndefined()){
            qDebug()<<"No existe configuracion asignada en archivo de config "<<m_subways.fileName()<< " para el modelo "<<configModel.toString();
            m_subways.close();
            return false;
        }
        //Seteamos al subte en cuestion su archivo de configuracion.
        m_configModelSubway.append(configModel.toString());

        m_modelSubway.setFileName(m_configModelSubway);
        qDebug()<<"Configuracion a cargar para el modelo "<<m_subways.fileName()<< ": --> "<<configModel.toString();
        m_subways.close();

    }else{
        qDebug()<< "No existe Archivo de configuraciones " <<m_subways.fileName()<<" para subtes";
        return false;
    }

    /**
     * Aca ya tengo el nombre en configModel del archivo con los datos de toda la configuracion
     * para la instancia en particular llegada por parametro.
     */
 //   QString subte = "://";
 //   subte.append(configModel.toString());
    qDebug() << "Comenzando la carga del archivo de configuracion: " << m_modelSubway.fileName();

  //  QFile source;
    if (m_modelSubway.exists()){
        qDebug()<< "Archivo de Configuracion encontrado: "<< m_modelSubway.fileName();
    }else{
        qDebug()<< "No existe Archivo de configuracion asociado a ese modelo "<<m_modelSubway.fileName()<<" de subte.";
        return false;
    }

//    QJsonParseError jerror;
    if (!m_modelSubway.open(QIODevice::ReadOnly)){
        qDebug()<<"No se pudo abrir el archivo: "<< m_modelSubway.fileName();
        return false;
    }else{
        qDebug()<<"Abrio archivo "<<m_modelSubway.fileName()<<" de configuracion de paneles axuliares OK";
    }

//    QString datos1 = m_modelSubway.readAll();
//    qDebug()<<"datos archivo: "<<datos1;

    jdoc= QJsonDocument::fromJson(m_modelSubway.readAll(),&jerror);
    if(jerror.error != QJsonParseError::NoError){
        qDebug()<<"Error en parseo de archivo Json configuracion de paneles auxiliares de Subtes:... "<< m_modelSubway.fileName();
        m_modelSubway.close();
        return false;
    }
    QJsonObject subWay = jdoc.object();
    QString recursoNivel1 = subWay["recurso"].toString();
    //QString configuracion = obj["configuracion"].toString();
    qDebug()<<"Recurso QML asociado a esta configuracion de Subte: "<< recursoNivel1;

    if(recursoNivel1.isEmpty()){
        qDebug()<<"Archivo de Configuracion "<<m_modelSubway.fileName() <<" de formacion no contiene VALUE para el Key: recurso";
        m_modelSubway.close();
        return false;
    }

    m_modelSubway.close();

    //QString f("CAF6000-MM-MM-MM");
    QString f(recursoNivel1);
    f.insert(0,"qrc:/");

    ui->qkW_N1->setSource(QUrl(f));

    m_qmlView1 = ui->qkW_N1->rootObject();

    connect(m_qmlView1,SIGNAL(selected(QString)),this,SLOT(level2(QString)));

    qDebug()<<"Saliendo de Nivel 1.................";
    return true;
}

/**
 * @brief AuxiliaryPanel::level2
 * @param s
 * recibe en s el coche (Ci), con ese busca en el archivo(json), 4 recursos, cada uno
 * asociado a un boton, B1..B4, y lo carga (Nivel 2)
 */
void AuxiliaryPanel::level2(QString s)
{
    qDebug()<<"Entro en Nivel 2";
    qDebug()<<"Selected option"<< s;
    //Guardo el coche seleccionado.
    m_wagonSelected = s;

    ui->qkW_N2->setSource(QUrl("qrc:/CAF6000-N2-PANEL-4"));
    m_qmlView2 = ui->qkW_N2->rootObject();
    m_qmlView2->setVisible(false);

    QMetaObject::invokeMethod(m_qmlView2,"resetResourceButton",
                              Q_ARG(QVariant,QString("BACKGROUND-PANEL")));

    m_modelSubway.setFileName(m_configModelSubway);

    if (!m_modelSubway.open(QIODevice::ReadOnly)){
        qDebug()<<"No se pudo abrir el archivo: "<< m_modelSubway.fileName();
        return;
    }else{
        qDebug()<<"Abrio archivo "<<m_modelSubway.fileName()<<" de configuracion de paneles axuliares OK";
    }

    QJsonDocument jdoc2;
    QJsonParseError jerror2;
    QJsonObject obj2;
//    QString datos = m_modelSubway.readAll();

    jdoc2= QJsonDocument::fromJson(m_modelSubway.readAll(),&jerror2);
    if(jerror2.error != QJsonParseError::NoError){
        qDebug()<<"Error: "<< jerror2.errorString() <<" en parseo de archivo Json configuracion de paneles auxiliares de Subtes:... "<< m_modelSubway.fileName();
        //qDebug()<<" ARCHIVO: ----------->" << datos;
        m_modelSubway.close();
        return;
    }

    obj2 = jdoc2.object();
    if (!( obj2.contains(QString("coches")) && obj2["coches"].isArray())){
        qDebug()<<"Archivo de configuracion "<<m_modelSubway.fileName()<< " no contiene Clave: coches, o no es un arreglo de coches.";
        m_modelSubway.close();
        return;
    }

    QJsonArray coches = obj2["coches"].toArray();
    QString numero,tipo;
    QJsonArray paneles;
    QObject *imageprop;

    //Buscar el coche 1 y cargar, aca me confundi N1 con N2, en N1 solo cargo el QML y paso a N2 donde va a esperar por click de un coche
    qDebug()<<"Antes del FOR";

        //int coche=1;
        for(auto&& item: coches)
        {
            const QJsonObject& coche = item.toObject();
            numero = coche["numero"].toString();
            tipo = coche["tipo"].toString();
            qDebug() << "Numero y tipo de Coche: " << numero <<"--" << tipo;
            QString imageButton, recursoButton;
            if (numero == s){
                qDebug()<<"Entro en coche seleccionado: "<< s;

                if(!(coche["paneles"].isNull())){
                      paneles = coche["paneles"].toArray();
                      int i = 0;
                      for(auto&& item2:paneles){
                          const QJsonObject& panel = item2.toObject();
                          imageprop = m_qmlView2->findChild<QObject*>(QString("buttonImage").append(QString::number(i)));
                          qDebug()<<"PANEL:  --> "<< panel["tipo"].toString() <<" Numero de Orden en Json: "<< QString::number(i);

                          if(panel["image"].isNull()){
                              imageButton = "NO-OPTION";
                              recursoButton = "BACKGROUND-PANEL";
                              qDebug()<< "NO OPTION!!!!!!!!" << imageButton;
                          }else{
                              imageButton = panel["image"].toString();
                              if (panel["recurso"].isNull()){
                                  recursoButton = "BACKGROUND-PANEL";
                                }else{
                                  recursoButton = panel["recurso"].toString();
                                }
                          }
                          qDebug()<<"Button: "<< i <<" Image configured to: "<<imageButton;
                          imageprop->setProperty("source",("qrc:/"+imageButton));//"qrc:/resources/blue.png"
                          qDebug()<<"Button: "<< i <<" Resource configured to: "<<recursoButton;
                          //imageprop->setProperty("resourceButton",(recursoButton));

                          QMetaObject::invokeMethod(m_qmlView2,"setResourceButton",
                                                    Q_ARG(QVariant,QString::number(i)),
                                                    Q_ARG(QVariant,recursoButton));

                          i++;
                      }//for
                }
            }//numero == s
        }

      //QObject *imageprop = m_qmlView2->findChild<QObject*>("buttonImage1");

//    imageprop->setProperty("source","qrc:/N2-B-TERMICAS");//"qrc:/resources/blue.png"

    connect (m_qmlView2,SIGNAL(selected(QString)),this,SLOT(level3(QString)));
    m_qmlView2->setVisible(true);

    qDebug()<<"Salio nivel 2";
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
  ui->qkW_N3->setSource(QUrl("qrc:/"+op));
  m_qmlView3 = ui->qkW_N3->rootObject();

  qDebug()<<"entro nivel 3 " << op;

  if (op == "BACKGROUND-PANEL" ){
        return;
    }
  (m_qmlView3->findChild<QObject*>(QString("conT17")))->setProperty("opacity",0);
  (m_qmlView3->findChild<QObject*>(QString("desT17")))->setProperty("opacity",1);
  m_qmlView3->setProperty("numberWagon",m_wagonSelected);

//  QMetaObject::invokeMethod(m_qmlView3,"resetThermal",
//                            Q_ARG(QVariant,QString("")));

  connect (m_qmlView3,SIGNAL(selected(QString)),this,SLOT(optionSelected(QString)));
}

void AuxiliaryPanel::optionSelected(QString op){
    qDebug()<<"option selected from panel auxiliary: "<< op;
}

AuxiliaryPanel::~AuxiliaryPanel()
{
    delete ui;
}
