#ifndef BOARDBOTTOM_H
#define BOARDBOTTOM_H

#include <QMainWindow>

namespace Ui {
class BoardBottom;
}

class BoardBottom : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardBottom(QWidget *parent = 0);
    ~BoardBottom();

private:
    Ui::BoardBottom *ui;
};

#endif // BOARDBOTTOM_H
