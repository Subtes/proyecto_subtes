#ifndef BOTTOMBOARD_H
#define BOTTOMBOARD_H

#include <QMainWindow>

namespace Ui {
class BottomBoard;
}

class BottomBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit BottomBoard(QWidget *parent = 0);
    ~BottomBoard();

private:
    Ui::BottomBoard *ui;
};

#endif // BOTTOMBOARD_H
