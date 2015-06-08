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




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SubteStatus * subte = new SubteStatus();

    QTimer *load = new QTimer(0);
    load->setInterval(1500);

    BoardHardware *h = new BoardHardware(0,subte);
    BoardCenter *c = new BoardCenter(0,subte);
    BoardLeft *l = new BoardLeft(0,subte);
    BoardRight *r = new BoardRight(0,subte);

    load->start();

    QDesktopWidget *desktop = a.desktop();

//    QPixmap pixmap(":/splash.png");
//    QSplashScreen splash(pixmap);
//    splash.show();
//    app.processEvents();
//    ...
//    QMainWindow window;
//    window.show();
//    splash.finish(&window);


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
        //l->move(-1024,0);
        qDebug() << "Pantalla a mostrar Izquierda: " << s1.width() << "Alto: " << s1.height();
        //l->showFullScreen();
        //load->start();

        //QWidget ScreenCentral = desktop->createWindowContainer(h,0,Qt::Window);
        //ScreenCentral.setWindowFlags();

        c->move(0,0);
        c->showFullScreen();
        //load->start();

        h->move(-1024,0);
        //h->setWindowFlags(Qt::FramelessWindowHint);
        h->showFullScreen();
        //load->start();

        r->move(1024,0);
        r->showFullScreen();
        //load->start();

    }

    //BoardTop *t = new BoardTop(0,subte);
    //t->showFullScreen();
    //t->show();

    return a.exec();
}
