#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "treemodel.h"

#include <QFile>
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent, EventHandler *eventHandler) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_eventHandler = eventHandler;

    connect(ui->view, SIGNAL(clicked(QModelIndex)), this, SLOT(clickAction(QModelIndex)));

    QStringList headers;
    headers << tr("Operacion") << tr("Accion");

    QFile file(":/resources/instructionsolutionpanel.txt");
    file.open(QIODevice::ReadOnly);
    TreeModel *model = new TreeModel(headers, file.readAll());
    file.close();

    ui->view->setModel(model);
    for (int column = 0; column < model->columnCount(); ++column)
        ui->view->resizeColumnToContents(column);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clickAction(QModelIndex hoja)
{
  if (! hoja.model()->hasChildren(hoja))
  {
     //QVariant accion =  (hoja.data(0)).toString();
     //QString accion = new QString((hoja.data(0)).toString());
     //m_eventHandler->notifyValueChanged("c_averia",accion);
     m_eventHandler->notifyValueChanged("c_averia","hola");
     qDebug() << "Clickeado!!!!" + (hoja.data(0)).toString();
 }
}
