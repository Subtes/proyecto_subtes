/********************************************************************************
** Form generated from reading UI file 'tablero.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLERO_H
#define UI_TABLERO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "panel_buttons2.h"
#include "panel_buttons3.h"
#include "speedgauge.h"
#include "tractionlever.h"

QT_BEGIN_NAMESPACE

class Ui_Tablero
{
public:
    QWidget *centralWidget;
    SpeedGauge *widget;
    Panel_Buttons3 *panel_buttons3_left;
    Panel_Buttons2 *widget_3;
    Panel_Buttons3 *panel_buttons3_right;
    TractionLever *widget_5;
    QLCDNumber *lcdNumber;
    QDial *dial;

    void setupUi(QMainWindow *Tablero)
    {
        if (Tablero->objectName().isEmpty())
            Tablero->setObjectName(QStringLiteral("Tablero"));
        Tablero->resize(800, 600);
        Tablero->setStyleSheet(QStringLiteral("background-image: url(:/resources/BKG_tablero.png);"));
        centralWidget = new QWidget(Tablero);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new SpeedGauge(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(280, 20, 260, 260));
        widget->setStyleSheet(QStringLiteral("background-image: url(:/resources/velocimetro.png);"));
        panel_buttons3_left = new Panel_Buttons3(centralWidget);
        panel_buttons3_left->setObjectName(QStringLiteral("panel_buttons3_left"));
        panel_buttons3_left->setGeometry(QRect(20, 20, 156, 266));
        panel_buttons3_left->setStyleSheet(QLatin1String("background-image: url(:/resources/BKG_botonera.png);\n"
"\n"
""));
        widget_3 = new Panel_Buttons2(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(510, 430, 100, 150));
        widget_3->setStyleSheet(QStringLiteral("background-image: url(:/resources/BKG_botonera_HM.png);"));
        panel_buttons3_right = new Panel_Buttons3(centralWidget);
        panel_buttons3_right->setObjectName(QStringLiteral("panel_buttons3_right"));
        panel_buttons3_right->setGeometry(QRect(630, 20, 156, 266));
        panel_buttons3_right->setStyleSheet(QStringLiteral("background-image: url(:/resources/BKG_botonera.png);"));
        widget_5 = new TractionLever(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(627, 316, 157, 266));
        widget_5->setStyleSheet(QStringLiteral("background-image: url(:/resources/BKG_palanca.png);"));
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(280, 300, 260, 60));
        lcdNumber->setStyleSheet(QLatin1String("color: rgb(85, 255, 0); \n"
"background-color: Black ;\n"
"background-image: url(:/);"));
        lcdNumber->setFrameShadow(QFrame::Raised);
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber->setProperty("value", QVariant(223));
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(10, 440, 151, 151));
        dial->setMaximum(2);
        dial->setPageStep(1);
        Tablero->setCentralWidget(centralWidget);

        retranslateUi(Tablero);

        QMetaObject::connectSlotsByName(Tablero);
    } // setupUi

    void retranslateUi(QMainWindow *Tablero)
    {
        Tablero->setWindowTitle(QApplication::translate("Tablero", "Tablero", 0));
    } // retranslateUi

};

namespace Ui {
    class Tablero: public Ui_Tablero {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLERO_H
