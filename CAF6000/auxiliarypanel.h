#ifndef AUXILIARYPANEL_H
#define AUXILIARYPANEL_H

#include <QWidget>

namespace Ui {
class AuxiliaryPanel;
}

class AuxiliaryPanel : public QWidget
{
    Q_OBJECT

public:
    explicit AuxiliaryPanel(QWidget *parent = 0);
    ~AuxiliaryPanel();

private:
    Ui::AuxiliaryPanel *ui;
};

#endif // AUXILIARYPANEL_H
