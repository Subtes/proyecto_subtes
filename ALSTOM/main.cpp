#include <QApplication>
#include <QDebug>
#include "src/models/subtestate.h"
#include "src/controllers/eventhandler.h"
#include "boardhardware.h"
#include "boardcenter.h"
#include "boardatp.h"
#include "boardmac.h"
#include "boardbottom.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // MODEL
    SubteState * m_subte = new SubteState();

    // CONTROLLER DISPATCHER
    EventHandler *m_eventHandler = new EventHandler();

    // VIEWS
    BoardHardware *m_h = new BoardHardware(0,m_subte,m_eventHandler);
    BoardCenter * m_c = new BoardCenter(0);
    BoardAtp *m_a = new BoardAtp(0);
    BoardBottom *m_b = new BoardBottom(0);
    BoardMac *m_m = new BoardMac(0);

    m_a->showNormal();
    m_b->showNormal();
    m_c->showNormal();
    m_h->showNormal();
    m_m->showNormal();

    m_eventHandler->setModel(m_subte);
    m_subte->setHandler(m_eventHandler);
    m_eventHandler->initConnection();

    QObject::connect(m_eventHandler,SIGNAL(closeApp()),qApp,SLOT(quit()));
    return a.exec();
}
