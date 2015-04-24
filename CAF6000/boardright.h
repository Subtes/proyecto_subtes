#ifndef BOARDRIGHT_H
#define BOARDRIGHT_H

#include <QMainWindow>
#include "src/models/subtestatus.h"

namespace Ui {
class BoardRight;
}

class BoardRight : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardRight(QWidget *parent = 0, SubteStatus *subte = 0);
    ~BoardRight();

private:
    Ui::BoardRight *ui;
    SubteStatus *m_subte;
};

#endif // BOARDRIGHT_H
