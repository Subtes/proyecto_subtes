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
    headers << tr("Operacion");

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
     QModelIndex root = hoja;
     while (root.parent().isValid())
            root = root.parent();
     clickActionDecision(hoja,root);
 }
}

void MainWindow::clickActionDecision(QModelIndex hoja, QModelIndex root)
{
    QString action = hoja.data(0).toString();
    QString father = hoja.parent().data(0).toString();
    QString category = hoja.parent().parent().data(0).toString();

    if (category.operator ==("Grifos")){
        if (father.operator ==("B-138"))
            if (action.operator ==("CON"))
                m_eventHandler->notifyValueChanged("c_grifob138","con");
            else
                m_eventHandler->notifyValueChanged("c_grifob138","des");
        if (father.operator ==("L-2"))
            if (action.operator ==("CON"))
                m_eventHandler->notifyValueChanged("c_grifol2","con");
            else
                m_eventHandler->notifyValueChanged("c_grifol2","des");
        if (father.operator ==("B-73"))
            if (action.operator ==("CON"))
                m_eventHandler->notifyValueChanged("c_grifob73","con");
            else
                m_eventHandler->notifyValueChanged("c_grifob73","des");
    }
    else{
        if (category.operator ==("Termicos"))
            if (father.operator ==("57F1"))
                if (action.operator ==("CON"))
                    m_eventHandler->notifyValueChanged("c_termico_57f1","con");
                else
                    m_eventHandler->notifyValueChanged("c_termico_57f1","des");
            if (father.operator ==("53F1"))
                if (action.operator ==("CON"))
                    m_eventHandler->notifyValueChanged("c_termico_53f1","con");
                else
                    m_eventHandler->notifyValueChanged("c_termico_53f1","des");
            if (father.operator ==("33F1"))
                if (action.operator ==("CON"))
                    m_eventHandler->notifyValueChanged("c_termico_33f1","con");
                else
                    m_eventHandler->notifyValueChanged("c_termico_33f1","des");
    }
    qDebug() << "Clickeado!!!!" + action + " " + father + " " + category + " " + root.data(0).toString();
    //m_eventHandler->notifyValueChanged("c_grifoB138_N",action.toStdString());
    //qDebug() << "Clickeado!!!!" + (hoja.data(0)).toString();
}
