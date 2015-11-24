#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>

#include "src/models/subtestate.h"
#include "src/controllers/eventhandler.h"
#include "boardhardware.h"
#include "boardcenter.h"
#include "boardatp.h"
#include "boardmac.h"
#include "boardbottom.h"

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_UseOpenGLES,true);
    QApplication a(argc, argv);

    // MODEL
    SubteState * m_subte = new SubteState();

    // CONTROLLER DISPATCHER
    EventHandler *m_eventHandler = new EventHandler();

    // VIEWS
    BoardCenter * m_c = new BoardCenter(0);
    BoardAtp *m_a = new BoardAtp(0);
    BoardMac *m_m = new BoardMac(0,m_subte,m_eventHandler);
    BoardBottom *m_b = new BoardBottom(0);
    BoardHardware *m_h = new BoardHardware(0,m_subte,m_eventHandler);

    QTabWidget *m_tabs = new QTabWidget(0);
    m_tabs->addTab(m_h,QObject::tr("HARDWARE"));
    m_tabs->addTab(m_b,QObject::tr("BOTTOM"));
    m_tabs->setMinimumWidth(1024);
    m_tabs->setMinimumHeight(768);

    QDesktopWidget *desktop = a.desktop();
    if(desktop->screenCount() == 4){
        QRect s0 = desktop->screenGeometry(0);
        QRect s1 = desktop->screenGeometry(1);
        QRect s2 = desktop->screenGeometry(2);
        QRect s3 = desktop->screenGeometry(3);

        m_c->showFullScreen();
        m_a->showFullScreen();
        m_m->showFullScreen();
        m_tabs->showFullScreen();

        m_c->move(s0.topLeft());
        m_a->move(s2.topLeft());
        m_m->move(s3.topLeft());
        m_tabs->move(s1.topLeft());

    }else{
        m_c->showNormal();
        m_a->showNormal();
        m_m->showNormal();
        m_tabs->showNormal();
    }

    m_eventHandler->setModel(m_subte);
    m_subte->setHandler(m_eventHandler);
    m_eventHandler->initConnection();

    QObject::connect(m_eventHandler,SIGNAL(closeApp()),qApp,SLOT(quit()));
    return a.exec();
}
