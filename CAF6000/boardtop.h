#ifndef BOARDTOP_H
#define BOARDTOP_H

#include <QMainWindow>
#include "src/models/subtestatus.h"


namespace Ui {
class BoardTop;
}

class BoardTop : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardTop(QWidget *parent = 0, SubteStatus *subte = 0);
    ~BoardTop();

private:
    Ui::BoardTop *ui;
    SubteStatus *m_subte;

public slots:
    void startBoard();
    void enableScreen();
    void disableScreen();
    void resetControls();
};

#endif // BOARDTOP_H
