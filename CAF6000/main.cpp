#include <QApplication>
#include <QDebug>
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
    m_h->show();
    BoardCenter * m_c = new BoardCenter(0,m_subte,m_eventHandler);
    m_c->show();
    BoardLeft *m_l = new BoardLeft(0,m_subte,m_eventHandler);
    m_l->show();

    // DEPENDENCY INJECTION
    m_eventHandler->setModel(m_subte);
    m_subte->setHandler(m_eventHandler);
    m_eventHandler->initConnection();

    return a.exec();
}
