#include "base_enethelper.h"

Base_ENetHelper::Base_ENetHelper(){
    m_eNetClient = NULL;
}

Base_ENetHelper::~Base_ENetHelper(){
}

void Base_ENetHelper::initENet(Base_EventHandler *eventHandler, QString dirPath){
    if (m_eNetClient==NULL)
        m_eNetClient = new ENetClient();

    //=== eNet setup ===
    readIni(dirPath);

    using namespace std::placeholders;
    m_eNetClient->OnCambioValClave = std::bind(&Base_EventHandler::processValueChanged, eventHandler, _1, _2, _3);
    if (!m_eNetClient->Conectar(m_serverIp, m_serverPort, m_controlsHostName)){
        qDebug() << "ERROR AL CONECTAR CON EL SERVIDOR";
        qDebug() << "Intento conectar con:: servidor " << m_serverIp.c_str() << " , puerto "<< m_serverPort << " , host "<< m_controlsHostName.c_str();
    }
    m_eNetClient->Suscribirse(m_instructionsHostName,"i_iniciar_simulador");
}

ENetClient *Base_ENetHelper::client()
{
    if (m_eNetClient==NULL)
        m_eNetClient = new ENetClient();
    return m_eNetClient;
}

std::string Base_ENetHelper::serverIp() const
{
    return m_serverIp;
}

int Base_ENetHelper::serverPort() const
{
    return m_serverPort;
}

std::string Base_ENetHelper::controlsHostName() const
{
    return m_controlsHostName;
}

std::string Base_ENetHelper::visualHostName() const
{
    return m_visualHostName;
}

std::string Base_ENetHelper::instructionsHostName() const
{
    return m_instructionsHostName;
}

void Base_ENetHelper::readIni(QString dirPath)
{
    QDomDocument xml;

    qDebug() << "file: " << QDir(dirPath).absoluteFilePath(ini.c_str());

    QString fileName = QDir(dirPath).absoluteFilePath(ini.c_str());

    qDebug() << "LECTURA DEL ARCHIVO DE CONFIGURACION .INI: " ;
    qDebug() << "Ubicacion del archivo: " << fileName;

    QFile f(fileName);
    if (!f.open(QIODevice::ReadOnly))
    {
        qDebug() << "Error en la carga del archivo de configuracion control.ini";
        return;
    }

    xml.setContent(&f);
    f.close();

    QDomElement root=xml.documentElement();

    qDebug() << "XML: root object" << root.nodeName();

    m_serverIp = root.namedItem("serverIp").toElement().text().toStdString();
    m_serverPort = root.namedItem("serverPort").toElement().text().toInt();
    m_controlsHostName = root.namedItem("m_controlsHostName").toElement().text().toStdString();
    m_visualHostName = root.namedItem("m_visualHostName").toElement().text().toStdString();
    m_instructionsHostName = root.namedItem("m_instructionsHostName").toElement().text().toStdString();

    qDebug() << "XML: server Ip: " << m_serverIp.c_str();
    qDebug() << "XML: server Port: " << m_serverPort;
    qDebug() << "XML: controls Host Name: " << m_controlsHostName.c_str();
    qDebug() << "XML: visual Host Name: " << m_visualHostName.c_str();
    qDebug() << "XML: instructions Host Name: " << m_instructionsHostName.c_str();
}
