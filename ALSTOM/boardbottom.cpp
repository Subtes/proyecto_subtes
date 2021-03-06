#include "boardbottom.h"
#include "ui_boardbottom.h"

BoardBottom::BoardBottom(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BoardBottom)
{
    ui->setupUi(this);

    QSize size;
    size.setHeight(109);
    size.setWidth(109);
    ui->cerrarPuertasIzq->setSize(size);
    ui->abriPuertasIzq->setSize(size);
    ui->cerrarPuertasDer->setSize(size);
    ui->abrirPuertasDer->setSize(size);
    ui->puertasCerradasDer->setSize(size);
    ui->puertasCerradasIzq->setSize(size);
    ui->lavaParabrisas->setSize(size);
    ui->bajarPanto->setSize(size);
    ui->subirPanto->setSize(size);

    ui->cerrarPuertasIzq->setButtonImage(QUrl("qrc:/resources/alstom_red_on.png"),QUrl("qrc:/resources/alstom_red.png"));
    ui->abriPuertasIzq->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));
    ui->cerrarPuertasDer->setButtonImage(QUrl("qrc:/resources/alstom_red_on.png"),QUrl("qrc:/resources/alstom_red.png"));
    ui->abrirPuertasDer->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));
    ui->puertasCerradasDer->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));
    ui->puertasCerradasIzq->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));
    ui->lavaParabrisas->setButtonImage(QUrl("qrc:/resources/alstom_blue_on.png"),QUrl("qrc:/resources/alstom_blue.png"));
    ui->bajarPanto->setButtonImage(QUrl("qrc:/resources/alstom_black_on.png"),QUrl("qrc:/resources/alstom_black.png"));
    ui->subirPanto->setButtonImage(QUrl("qrc:/resources/alstom_green_on.png"),QUrl("qrc:/resources/alstom_green.png"));

    ui->cerrarPuertasIzq->setOnPressAsDriver();
    ui->abriPuertasIzq->setOnPressAsDriver();
    ui->cerrarPuertasDer->setOnPressAsDriver();
    ui->abrirPuertasDer->setOnPressAsDriver();
    ui->puertasCerradasDer->setOnPressAsDriver();
    ui->puertasCerradasIzq->setOnPressAsDriver();
    ui->lavaParabrisas->setOnPressAsDriver();
    ui->bajarPanto->setOnPressAsDriver();
    ui->subirPanto->setOnPressAsDriver();
}

BoardBottom::~BoardBottom()
{
    delete ui;
}
