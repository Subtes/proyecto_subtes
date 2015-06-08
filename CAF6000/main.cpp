#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"
#include "boardtop.h"

#include "src/models/subtestatus.h"

#include <QApplication>
#include <ENetClient.h>
#include <QDebug>
#include <QDesktopWidget>
#include <QFlags>
#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QTabWidget>
#include <QSplashScreen>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/Splash1024x768.jpeg");
    QSplashScreen splash(pixmap);
    splash.show();
    //cargar algo...
    //splash.finish(QWidget*);

    SubteStatus * subte = new SubteStatus();

    QTimer *load = new QTimer(0);
    load->setInterval(3500);
    load->start();

    BoardHardware *h = new BoardHardware(0,subte);
    BoardCenter *c = new BoardCenter(0,subte);
    //ATP:
    BoardLeft *l = new BoardLeft(0,subte);
    //BoardRight *r = new BoardRight(0,subte);
    //BoardTop *t = new BoardTop(0,subte);

    QDesktopWidget *desktop = a.desktop();

    if (desktop->screenCount() == 3){
        //s1 = desktop->createWindowContainer(h,0,Qt::Window);
        for (int i = 0; i < desktop->screenCount(); i++) {
            qDebug() << "Dimensiones: " << desktop->screenGeometry(i);
            }

        QRect s1 = desktop->screenGeometry(-1);
        qDebug() << "Pantalla a mostrar" << s1.width() << "Alto: " << s1.height();
        s1 = desktop->screenGeometry(1);
        qDebug() << "Pantalla a mostrar" << s1.width() << "Alto: " << s1.height();
        s1 = desktop->screenGeometry(2);
        qDebug() << "Pantalla a mostrar" << s1.width() << "Alto: " << s1.height();
        s1 = desktop->screenGeometry(3);
        qDebug() << "Pantalla a mostrar" << s1.width() << "Alto: " << s1.height();

        //h->move(s1.height(),s1.width());
        //l->move(-1025,-1);
        //ATP:
        l->move(-1024,0);
        qDebug() << "Pantalla a mostrar Izquierda: " << s1.width() << "Alto: " << s1.height();
        //l->show();
        l->showFullScreen();
        //load->start();

        //QWidget ScreenCentral = desktop->createWindowContainer(h,0,Qt::Window);
        //ScreenCentral.setWindowFlags();

        //c->move(-6,-5);
        c->move(0,0);
        c->showFullScreen();
        //load->start();

        //h->move(1055,6);
        h->move(1024,0);
        //h->setWindowFlags(Qt::FramelessWindowHint);
        //h->show();
        h->showFullScreen();
        //load->start();

        //r->move(1024,0);
        //r->show();
        //load->start();

        //QTabWidget *tabRight = new QTabWidget(0);
        //tabRight->addTab(h,QObject::tr("Hardware"));
        //tabRight->addTab(r,QObject::tr("RightPanel"));

        //tabRight->move(1050,5);
        //tabRight->showFullScreen();

        //t->move(0,0);
        //t->show();

    }

    return a.exec();
}
