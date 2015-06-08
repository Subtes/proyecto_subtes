#include "splashtest.h"
#include "ui_splashtest.h"

splashTest::splashTest(QWidget *parent, Dispatcher *dispatcher) :
    QMainWindow(parent),
    ui(new Ui::splashTest)
{
    connect(dispatcher,SIGNAL(closeSplash()),this,SLOT(close());
    ui->setupUi(this);
}

splashTest::~splashTest()
{
    delete ui;
}
