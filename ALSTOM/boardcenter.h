#ifndef BOARDCENTER_H
#define BOARDCENTER_H

#include <QMainWindow>

namespace Ui {
class BoardCenter;
}

class BoardCenter : public QMainWindow
{
    Q_OBJECT

public:
    explicit BoardCenter(QWidget *parent = 0);
    ~BoardCenter();

private:
    Ui::BoardCenter *ui;
};

#endif // BOARDCENTER_H
