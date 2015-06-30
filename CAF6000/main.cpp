#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>
#include <QSplashScreen>

#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"
#include "boardtop.h"

#include "src/controllers/eventhandler.h"
#include "src/controllers/keypresseater.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // CONTROLLER DISPATCHER
    EventHandler *m_eventHandler = new EventHandler();

    // MODEL
    SubteStatus * m_subte = new SubteStatus();

    // VIEWS
    BoardHardware *m_h = new BoardHardware(0,m_subte,m_eventHandler);
    BoardCenter * m_c = new BoardCenter(0,m_subte,m_eventHandler);
    BoardLeft *m_l = new BoardLeft(0,m_subte,m_eventHandler);
    BoardRight *m_r = new BoardRight(0,m_subte,m_eventHandler);
    //BoardTop *m_t = new BoardTop(0,m_subte,m_eventHandler);

    QDesktopWidget *desktop = a.desktop();
    if(desktop->screenCount() == 4){
        qDebug() << "Entre en For de pantallas igual 4: ";
        for(int i = 0; i < desktop->screenCount(); i++){
            qDebug() << "Dimensiones --> "<< desktop->screenGeometry(i);
        }

    QRect s0 = desktop->screenGeometry(0);
    QRect s1 = desktop->screenGeometry(1);
    QRect s2 = desktop->screenGeometry(2);
    QRect s3 = desktop->screenGeometry(3);

    /**
     * Dimensiones -->  QRect(0,0 1024x768)
     * Dimensiones -->  QRect(-2048,0 1024x768)
     * Dimensiones -->  QRect(1024,0 1024x768)
     * Dimensiones -->  QRect(-1024,0 1024x768)
     */

    m_h->move(s0.topLeft());
    m_l->move(s1.topLeft());
    m_r->move(s2.topLeft());
    m_c->move(s3.topLeft());

    m_h->showNormal();
    m_l->showNormal();
    m_c->showNormal();
    m_r->showNormal();

    }else{
        m_h->showNormal();
        m_l->showNormal();
        m_c->showNormal();
        m_r->showNormal();
    }

    // DEPENDENCY INJECTION
    m_eventHandler->setModel(m_subte);
    m_subte->setHandler(m_eventHandler);
    m_eventHandler->initConnection();

    return a.exec();
}
