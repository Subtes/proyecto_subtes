#include <QApplication>
#include <QDebug>

#include "boardcenter.h"
#include "boardhardware.h"
#include "boardleft.h"
#include "boardright.h"
#include "boardtop.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MODEL
    SubteStatus * m_subte = new SubteStatus();

    //VIEWS
    BoardHardware *m_h = new BoardHardware(0,m_subte);
    m_h->show();
    BoardCenter * m_c = new BoardCenter(0,m_subte);
    m_c->show();
    //BoardLeft *m_l = new BoardLeft(0,m_subte);
    //m_l->show();
    //BoardRight *m_r = new BoardRight(0,m_subte);
    //m_r->show();
    //BoardTop *m_t = new BoardTop(0,m_subte);
    //m_t->show();

    m_subte->initENet();

    return a.exec();
}
