#ifndef INSTRUCTIONPANEL_H
#define INSTRUCTIONPANEL_H

#include <QWidget>

namespace Ui {
class InstructionPanel;
}

class InstructionPanel : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionPanel(QWidget *parent = 0);
    ~InstructionPanel();

private:
    Ui::InstructionPanel *ui;
};

#endif // INSTRUCTIONPANEL_H
