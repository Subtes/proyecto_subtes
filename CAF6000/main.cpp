#include <QApplication>
#include <QDebug>
#include <QDesktopWidget>

#include <tractionhardware.h>

#include "boardhardware.h"
#include "boardcenter.h"
#include "boardleft.h"
#include "boardright.h"
#include "boardtop.h"
#include "src/instructionsolutionpanel/mainwindow.h"
#include "boardauxiliarypanel.h"

#include "src/controllers/eventhandler.h"
#include "src/controllers/keypresseater.h"
#include "src/controllers/failures_controller.h"

#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

class LogHandler : public el::LogDispatchCallback {
public:
    void handle(const el::LogDispatchData* data) {
        // NEVER LOG ANYTHING HERE! NOT HAPPY WITH MULTI_THREADING
        ELPP_COUT << "Test this " << data << std::endl;
    }
};

class HtmlHandler : public el::LogDispatchCallback {
public:
    HtmlHandler() {
        el::Loggers::getLogger("html");
    }
    void handle(const el::LogDispatchData* data) {
        // NEVER LOG ANYTHING HERE! NOT HAPPY WITH MULTI_THREADING
        ELPP_COUT << "<b>" << data->logMessage()->message() << "</b>" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    START_EASYLOGGINGPP(argc, argv);

   el::Loggers::removeFlag(el::LoggingFlag::NewLineForContainer);
   el::Helpers::installLogDispatchCallback<LogHandler>("LogHandler");
   el::Helpers::installLogDispatchCallback<HtmlHandler>("HtmlHandler");

   LOG(INFO) << "First log";

   LogHandler* logHandler = el::Helpers::logDispatchCallback<LogHandler>("LogHandler");
   logHandler->setEnabled(false);

   LOG(INFO) << "Second log";

    //QCoreApplication::setAttribute(Qt::AA_UseOpenGLES);
    QApplication::setAttribute(Qt::AA_UseOpenGLES,true);
    //QApplication::setAttribute(Qt::AA_UseDesktopOpenGL,true);
    //QApplication::setAttribute(Qt::AA_UseSoftwareOpenGL,true);

    QApplication a(argc, argv);

    TractionHardware * m_tHardware = new TractionHardware();

    // MODEL
    SubteStatus * m_subte = new SubteStatus();

    // CONTROLLER DISPATCHER
    EventHandler *m_eventHandler = new EventHandler(a.desktop());
    Failures_Controller *m_failures = new Failures_Controller(m_subte);

    // VIEWS
    BoardHardware *m_h = new BoardHardware(0,m_subte,m_eventHandler);
    BoardCenter * m_c = new BoardCenter(0,m_subte,m_eventHandler);
    BoardLeft *m_l = new BoardLeft(0,m_subte,m_eventHandler);
    BoardRight *m_r = new BoardRight(0,m_subte,m_eventHandler);
    BoardTop *m_t = new BoardTop(0,m_subte,m_eventHandler);
    MainWindow *m_tree = new MainWindow(0,m_eventHandler);
    BoardAuxiliaryPanel *m_auxiliaryPanel = new BoardAuxiliaryPanel(0,m_subte,m_eventHandler);

    m_h->setHardware(m_tHardware);
    m_c->setHardware(m_tHardware);
    m_t->setHardware(m_tHardware);
    m_l->setHardware(m_tHardware);
    m_r->setHardware(m_tHardware);

    QDesktopWidget *desktop = a.desktop();

    if(desktop->screenCount() == 4){
        qDebug() << "Entre en For de pantallas igual 4 main: ";
        for(int i = 0; i < desktop->screenCount(); i++){
            qDebug() << "Dimensiones --> "<< desktop->screenGeometry(i);
        }

        QRect s0 = desktop->screenGeometry(0);//Dimensiones -->  QRect(0,0 1024x768)
        QRect s1 = desktop->screenGeometry(1);//Dimensiones -->  QRect(-2048,0 1024x768)
        QRect s2 = desktop->screenGeometry(2);//Dimensiones -->  QRect(1024,0 1024x768)
        QRect s3 = desktop->screenGeometry(3);//Dimensiones -->  QRect(-1024,0 1024x768)


        /**
         * Dimensiones -->  QRect(0,0 1024x768)
         * Dimensiones -->  QRect(1024,0 1024x768)
         * Dimensiones -->  QRect(-1024,0 1024x768)
         * Dimensiones -->  QRect(0,-768 1024x768)
        */

        m_t->showFullScreen();
        m_c->showFullScreen();
        m_l->showFullScreen();

        QTabWidget *tabRight = new QTabWidget(0);
        tabRight->addTab(m_r,QObject::tr("RightPanel"));
        tabRight->addTab(m_h,QObject::tr("Hardware"));
        tabRight->addTab(m_tree,QObject::tr("TreePanel"));
        tabRight->addTab(m_auxiliaryPanel,QObject::tr("Paneles Auxiliares"));

        tabRight->showFullScreen();

        m_c->move(s1.topLeft());
        m_l->move(s0.topLeft());
        m_t->move(s3.topLeft());

        tabRight->move(s2.topLeft());

    }else{

        m_h->showNormal();
        m_l->showNormal();
        m_t->showNormal();

        QTabWidget *tabRight = new QTabWidget(0);
        tabRight->addTab(m_c,QObject::tr("Center"));
        tabRight->addTab(m_r,QObject::tr("RightPanel"));
        tabRight->addTab(m_tree,QObject::tr("TreePanel"));
        tabRight->addTab(m_auxiliaryPanel,QObject::tr("Paneles Auxiliares"));

        tabRight->setMinimumWidth(1024);
        tabRight->setMinimumHeight(768);
        tabRight->showNormal();

    }

    // DEPENDENCY INJECTION
    m_eventHandler->setModel(m_subte);
    m_eventHandler->setFailures(m_failures);
    m_subte->setHandler(m_eventHandler);
    m_eventHandler->initConnection();

    QObject::connect(m_eventHandler,SIGNAL(closeApp()),qApp,SLOT(quit()));
    return a.exec();
}
