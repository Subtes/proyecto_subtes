#include <QMetaObject>

#include "panel_buttons2.h"
#include "ui_panel_buttons2.h"

Panel_Buttons2::Panel_Buttons2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Panel_Buttons2)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);
    this->qmlView = ui->quickWidget->rootObject();

    connect(qmlView,SIGNAL(button1_ClickedOff()),this,SLOT(off_Button2()));
}

void Panel_Buttons2::enable_Button1(QVariant enable){
    QVariant returnedValue;
    QMetaObject::invokeMethod(this->qmlView, "enable_mouseArea1", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, enable.value<boolean>()));

}

void Panel_Buttons2::enable_Button2(QVariant enable){
    QVariant returnedValue;
    QMetaObject::invokeMethod(this->qmlView, "enable_mouseArea2", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, enable.value<boolean>()));

}

void Panel_Buttons2::trigger_Alarm(QVariant enable){
    QVariant returnedValue;
    QMetaObject::invokeMethod(this->qmlView, "alarm_light", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant,enable.value<boolean>()));
}

void Panel_Buttons2::on_Button1(){

    QVariant returnedValue;
    //QVariant enable(true);
    QMetaObject::invokeMethod(this->qmlView, "light_Button1", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, "ON"));
    //QMetaObject::invokeMethod(this->qmlView, "enable_mouseArea1", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, enable.value<boolean>()));

}

void Panel_Buttons2::on_Button2(){

    QVariant returnedValue;
    //QVariant enable(false);
    QMetaObject::invokeMethod(this->qmlView, "light_Button2", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, "ON"));
    //QMetaObject::invokeMethod(this->qmlView, "enable_mouseArea2", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, enable.value<boolean>()));

}

void Panel_Buttons2::off_Button1(){

    QVariant returnedValue;
    QMetaObject::invokeMethod(this->qmlView, "light_Button1", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, "OFF"));
    //QMetaObject::invokeMethod(this->qmlView, "enable_mouseArea1", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, "OFF"));
}

void Panel_Buttons2::off_Button2(){

    QVariant returnedValue;
    QMetaObject::invokeMethod(this->qmlView, "light_Button2", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, "OFF"));
    //QMetaObject::invokeMethod(this->qmlView, "enable_mouseArea2", Q_RETURN_ARG(QVariant, returnedValue),Q_ARG(QVariant, "OFF"));
    emit this->on_ClickButton1();
}

Panel_Buttons2::~Panel_Buttons2()
{
    delete ui;
}
