#include "sicasmac.h"
#include "ui_sicasmac.h"

SicasMac::SicasMac(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SicasMac)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_qmlView = ui->quickWidget->rootObject();
}

SicasMac::~SicasMac()
{
    delete ui;
}

void SicasMac::setBackgroudImage(QUrl bg)
{
    QObject * hook = m_qmlView->findChild<QObject*>("background");
    hook->setProperty("source", bg);
}


void SicasMac::setGlassImage(QUrl gl)
{
    QObject * hook = m_qmlView->findChild<QObject*>("glassmac");
    hook->setProperty("source", gl);
}

void SicasMac::setFailure1(QUrl fl)
{
    QObject * hook = m_qmlView->findChild<QObject*>("failure1");
    hook->setProperty("source", fl);
}

void SicasMac::setFailure2(QUrl f2)
{
    QObject * hook = m_qmlView->findChild<QObject*>("failure2");
    hook->setProperty("source", f2);
}

void SicasMac::setFailure3(QUrl f3)
{
    QObject * hook = m_qmlView->findChild<QObject*>("failure3");
    hook->setProperty("source", f3);
}

void SicasMac::setFailure4(QUrl f4)
{
    QObject * hook = m_qmlView->findChild<QObject*>("failure4");
    hook->setProperty("source", f4);
}

void SicasMac::setFailure5(QUrl f5)
{
    QObject * hook = m_qmlView->findChild<QObject*>("failure5");
    hook->setProperty("source", f5);
}

void SicasMac::setFailure6(QUrl f6)
{
    QObject * hook = m_qmlView->findChild<QObject*>("failure6");
    hook->setProperty("source", f6);
}

void SicasMac::setStartTrain(QUrl at1)
{
    QObject * hook = m_qmlView->findChild<QObject*>("actualtrainstart");
    hook->setProperty("source", at1);
}

void SicasMac::setEndTrain(QUrl at6)
{
    QObject * hook = m_qmlView->findChild<QObject*>("actualtrainend");
    hook->setProperty("source", at6);
}



void SicasMac::startBlinkFailure(int failure)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "startBlinkFailure",
                              Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, failure));
}

void SicasMac::stopBlink(int failure)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "stopBlinkFailure",
                              Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, failure));
}

void SicasMac::textEditSicas(QString error,QString trenes,QString letra, int index)
{
    qDebug() << "llega: " << error << trenes << letra << index;
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "changeText",
                              Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, error),
                                    Q_ARG(QVariant, trenes),Q_ARG(QVariant, letra),Q_ARG(QVariant, index));
}

void SicasMac::insertTrainSicas(QString coche, QString estFreno)
{
    qDebug() << "llega: estdado tren ";
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "changeStateTrain",
                              Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, coche),
                                    Q_ARG(QVariant, estFreno));
}
void SicasMac::insertDoorsSicas(QString doors,int tren){
   /* qDebug() << "llega: puertas ";
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "changeStateDoors",
                              Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, doors), Q_ARG(QVariant, tren));
*/
}
void SicasMac::turnOffFailure(int coche)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "turnOffFailure",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, coche));
}

void SicasMac::turnOnFailure(int coche)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "turnOnFailure",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, coche));
}
void SicasMac::turnBlinkFailure(int coche)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "turnBlinkFailure",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, coche));
}
void SicasMac::turnInhabFailure(int coche)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "turnInhabFailure",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, coche));
}
void SicasMac::turnOffDoors(int coche)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "turnOffDoors",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, coche));
}

void SicasMac::turnOnDoors(int coche)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "turnOnDoors",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, coche));
}

void SicasMac::actualizarTamArreRenglon(int finRenglon, int indiceArre)
{
    QVariant returnedValue;
    QMetaObject::invokeMethod(m_qmlView, "actualizarTamArreRenglon",
            Q_RETURN_ARG(QVariant, returnedValue), Q_ARG(QVariant, finRenglon), Q_ARG(QVariant, indiceArre));
}
