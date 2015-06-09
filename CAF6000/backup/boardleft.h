#ifndef BOARDLEFT_H
#define BOARDLEFT_H

#include <QMainWindow>
#include "src/models/subtestatus.h"

namespace Ui {
class BoardLeft;
}

class BoardLeft : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardLeft(QWidget *parent = 0, SubteStatus *subte = 0);
    ~BoardLeft();

private:
    Ui::BoardLeft *ui;
    SubteStatus *m_subte;
};

#endif // BOARDLEFT_H
