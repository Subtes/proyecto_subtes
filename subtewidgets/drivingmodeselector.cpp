#include "drivingmodeselector.h"
#include "ui_drivingmodeselector.h"

DrivingModeSelector::DrivingModeSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrivingModeSelector)
{
    ui->setupUi(this);
    ui->quickWidget->setClearColor(Qt::transparent);
    ui->quickWidget->setAttribute(Qt::WA_AlwaysStackOnTop);

    m_qmlView = ui->quickWidget->rootObject();

    connect(m_qmlView,SIGNAL(selectedOption(int)),this,SIGNAL(selectedOption(int)));
}

DrivingModeSelector::~DrivingModeSelector()
{
    delete ui;
}
