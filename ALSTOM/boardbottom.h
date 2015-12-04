#ifndef BOARDBOTTOM_H
#define BOARDBOTTOM_H

#include <QMainWindow>
#include "switchmultipoint.h"

namespace Ui {
class BoardBottom;
}

class BoardBottom : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardBottom(QWidget *parent = 0);
    ~BoardBottom();

public slots:
    void onPressPosSlot(int pos);

private:
    Ui::BoardBottom *ui;
    SwitchMultiPoint *m_switch1;
};

#endif // BOARDBOTTOM_H
