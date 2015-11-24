#include "boardcenter.h"
#include "ui_boardcenter.h"

BoardCenter::BoardCenter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardCenter)
{
    ui->setupUi(this);

    QSize size;
    size.setHeight(110);
    size.setWidth(110);
    ui->start->setSize(size);
    ui->retroceso->setSize(size);
    ui->atoUp->setSize(size);
    ui->atoDown->setSize(size);
    ui->reconocer->setSize(size);
    ui->puerta->setSize(size);
    ui->desacople->setSize(size);
    ui->senaleraAcople->setSize(size);

    ui->start->setButtonImage(QUrl("qrc:/resources/alstom_blue_on.png"),QUrl("qrc:/resources/alstom_blue.png"));
    ui->retroceso->setButtonImage(QUrl("qrc:/resources/alstom_yellow_on.png"),QUrl("qrc:/resources/alstom_yellow.png"));
    ui->atoUp->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));
    ui->atoDown->setButtonImage(QUrl("qrc:/resources/alstom_red_on.png"),QUrl("qrc:/resources/alstom_red.png"));
    ui->reconocer->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));
    ui->puerta->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));
    ui->desacople->setButtonImage(QUrl("qrc:/resources/alstom_blue_on.png"),QUrl("qrc:/resources/alstom_blue.png"));
    ui->senaleraAcople->setButtonImage(QUrl("qrc:/resources/alstom_yellow_on.png"),QUrl("qrc:/resources/alstom_yellow.png"));

    ui->start->setOnPressAsDriver();
    ui->retroceso->setOnPressAsDriver();
    ui->atoUp->setOnPressAsDriver();
    ui->atoDown->setOnPressAsDriver();
    ui->reconocer->setOnPressAsDriver();
    ui->puerta->setOnPressAsDriver();
    ui->desacople->setOnPressAsDriver();
    ui->senaleraAcople->setOnPressAsDriver();
}

BoardCenter::~BoardCenter()
{
    delete ui;
}
