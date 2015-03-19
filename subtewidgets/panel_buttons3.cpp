#include "panel_buttons3.h"
#include "ui_panel_buttons3.h"
#include <QString>

Panel_Buttons3::Panel_Buttons3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_Buttons3)
{
    ui->setupUi(this);

    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    m_qmlView = ui->quickWidget->rootObject();

    connect(m_qmlView,SIGNAL(firstClicked()),this,SIGNAL(firstClicked()));
    connect(m_qmlView,SIGNAL(secondClicked()),this,SIGNAL(secondClicked()));
    connect(m_qmlView,SIGNAL(thirdClicked()),this,SIGNAL(thirdClicked()));
}

Panel_Buttons3::~Panel_Buttons3()
{
    delete ui;
}

void Panel_Buttons3::firstOn(){
    QObject * button = m_qmlView->findChild<QObject*>("first");
    button->setProperty("state", "stateFirstOn" );
}

void Panel_Buttons3::firstOff(){
    QObject * button = m_qmlView->findChild<QObject*>("first");
    button->setProperty("state", "stateFirstOff" );
}

void Panel_Buttons3::secondOn(){
    QObject * button = m_qmlView->findChild<QObject*>("second");
    button->setProperty("state", "stateSecondOn" );
}

void Panel_Buttons3::secondOff(){
    QObject * button = m_qmlView->findChild<QObject*>("second");
    button->setProperty("state", "stateSecondOff" );
}

void Panel_Buttons3::thirdOn(){
    QObject * button = m_qmlView->findChild<QObject*>("third");
    button->setProperty("state", "stateThirdOn" );
}

void Panel_Buttons3::thirdOff(){
    QObject * button = m_qmlView->findChild<QObject*>("third");
    button->setProperty("state", "stateThirdOff" );
}

bool Panel_Buttons3::stateFirst(){
    QObject * button = m_qmlView->findChild<QObject*>("first");
    QVariant state = button->property("state");
    return QString::compare(state.toString(),"stateFirstOn")==0;
}

bool Panel_Buttons3::stateSecond(){
    QObject * button = m_qmlView->findChild<QObject*>("second");
    QVariant state = button->property("state");
    return QString::compare(state.toString(),"stateSecondOn")==0;
}

bool Panel_Buttons3::stateThird(){
    QObject * button = m_qmlView->findChild<QObject*>("third");
    QVariant state = button->property("state");
    return QString::compare(state.toString(),"stateThirdOn")==0;
}

bool Panel_Buttons3::firstClickeable(){
    QObject * button = m_qmlView->findChild<QObject*>("first");
    return button->property("enabled").toBool();
}

bool Panel_Buttons3::secondClickeable(){
    QObject * button = m_qmlView->findChild<QObject*>("second");
    return button->property("enabled").toBool();
}

bool Panel_Buttons3::thirdClickeable(){
    QObject * button = m_qmlView->findChild<QObject*>("third");
    return button->property("enabled").toBool();
}

void Panel_Buttons3::setFirstClickeable(bool clickeable){
    QObject * button = m_qmlView->findChild<QObject*>("first");
    button->setProperty("enabled",clickeable);
}

void Panel_Buttons3::setSecondClickeable(bool clickeable){
    QObject * button = m_qmlView->findChild<QObject*>("second");
    button->setProperty("enabled",clickeable);
}

void Panel_Buttons3::setThirdClickeable(bool clickeable){
    QObject * button = m_qmlView->findChild<QObject*>("third");
    button->setProperty("enabled",clickeable);
}

void Panel_Buttons3::setFirstButtonImage(QUrl on, QUrl off){
    QObject * button = m_qmlView->findChild<QObject*>("firstON");
    button->setProperty("source", on);
    button = m_qmlView->findChild<QObject*>("firstOFF");
    button->setProperty("source", off);
}

void Panel_Buttons3::setSecondButtonImage(QUrl on, QUrl off){
    QObject * button = m_qmlView->findChild<QObject*>("secondON");
    button->setProperty("source", on);
    button = m_qmlView->findChild<QObject*>("secondOFF");
    button->setProperty("source", off);}

void Panel_Buttons3::setThirdButtonImage(QUrl on, QUrl off){
    QObject * button = m_qmlView->findChild<QObject*>("thirdON");
    button->setProperty("source", on);
    button = m_qmlView->findChild<QObject*>("thirdOFF");
    button->setProperty("source", off);
}
