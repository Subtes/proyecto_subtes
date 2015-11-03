#ifndef INSTRUCTIONPANEL_H
#define INSTRUCTIONPANEL_H

#include <QWidget>
#include <QQuickItem>
#include "src/models/subtestatus.h"
#include "src/controllers/eventhandler.h"

namespace Ui {
class InstructionPanel;
}

class InstructionPanel : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionPanel(QWidget *parent = 0, SubteStatus *subte = 0, EventHandler *eventHandler = 0);
    ~InstructionPanel();

public slots:
    void nivel1();
    void nivel2(int v);
    void nivel3(int v);

private:
    Ui::InstructionPanel *ui;
    QQuickItem *m_qmlView1;
    QQuickItem *m_qmlView2;
    QQuickItem *m_qmlView3;
    EventHandler *m_eventhandler;
    SubteStatus *m_subte;
};

#endif // INSTRUCTIONPANEL_H
